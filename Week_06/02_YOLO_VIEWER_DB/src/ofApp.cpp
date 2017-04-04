#include "ofApp.h"


const std::string ofApp::SQLITE_INSERT_YOLO_DET = ""
"INSERT INTO `dets` ("
    "`path`,"
    "`x`,"
    "`y`,"
    "`w`,"
    "`h`,"
    "`label`,"
    "`prob`"
") "
"VALUES ("
    ":path,"
    ":x,"
    ":y,"
    ":w,"
    ":h,"
    ":label,"
    ":prob"
")";
const std::string ofApp::SQLITE_CREATE_YOLO_DET_TABLE = ""
"CREATE TABLE IF NOT EXISTS `dets` ("
    "`path` TEXT,"
    "`x` INTEGER,"
    "`y` INTEGER,"
    "`w` INTEGER,"
    "`h` INTEGER,"
    "`label` TEXT,"
    "`prob` REAL"
")";


const std::string ofApp::SQLITE_SELECT_YOLO_DET_LABEL_EQUAL = "SELECT * FROM dets WHERE dets.label == :label";
const std::string ofApp::SQLITE_SELECT_YOLO_DET_PROB_GREATER_THAN = "SELECT * FROM dets WHERE dets.prob > :prob";


void ofApp::setup()
{
    setupDatabaseConnection("yolo.db");
    loadDetsIntoDatabase();

    currentDets = getAllLabels("bird");

}


void ofApp::update()
{
}


void ofApp::draw()
{
    ofSetColor(255);

    float x = 0;
    float y = 0;

    for (auto& det: currentDets)
    {
        if (x > ofGetWidth())
        {
            y += det.rect.height;
            x = 0;
        }

        ofPushMatrix();
        ofTranslate(x, y);

        ofSetColor(255);

        ofRectangle subsectionRect = det.rect;
        ofRectangle drawRect = ofRectangle(0, 0, det.rect.width, det.rect.height);

        det.texture.drawSubsection(drawRect, subsectionRect);

        std::string displayString = det.label + " " + ofToString(det.prob);
        ofNoFill();
        ofSetColor(255, 255, 0);
        ofDrawBitmapStringHighlight(displayString, 0, 0);

        ofPopMatrix();

        x += det.rect.width;
    }
}

void ofApp::keyPressed(int key)
{
    if (key == 'h')
    {
        currentDets = getAllLabels("bird");
    }
    else if (key == 'j')
    {
        currentDets = getAllLabelsWithProbabilityGreaterThan(0.8);
    }
}


void ofApp::setupDatabaseConnection(const std::string& databasePath)
{
    try
    {
        // Example database connection.
        dbConnection = std::make_unique<SQLite::SQLiteConnection>(databasePath,
                                                                  SQLite::SQLiteConnection::Mode::READ_WRITE_CREATE);

        // Get a reference to our database.
        SQLite::Database& db = dbConnection->database();

        // Create a table. Our SQL syntax (SQLITE_CREATE_YOLO_DET_TABLE) says to
        // CREATE TABLE IF NOT EXISTS, which means that it will only recreate
        // the table structure, if it does not already exist.
        db.exec(SQLITE_CREATE_YOLO_DET_TABLE);

        // Do a simple query to figure out how many records we have.
        int numRecords = db.execAndGet("SELECT COUNT(*) FROM `dets`");

        ofLogNotice("ofApp::setupDatabaseConnection") << "There are " << numRecords << " records.";
    }
    catch (const std::exception& e)
    {
        ofLogError() << "SQLite exception: " << e.what();
    }
}


void ofApp::loadDetsIntoDatabase()
{
    // We surround this with a try-catch statement to catch any
    // exceptions and return them as errors.
    try
    {
        ofDirectory imageDir("images/");
        imageDir.allowExt("jpg");
        imageDir.allowExt("jpeg");
        imageDir.allowExt("png");
        imageDir.allowExt("gif");

        for (const ofFile& file: imageDir)
        {
            std::string imagePath = file.getAbsolutePath();
            std::string jsonPath = imagePath + ".yolo.json";

            ofJson json = ofLoadJson(jsonPath);

            for (ofJson det: json["dets"])
            {
                // This uses the "prepared statement" style.
                auto& statement = dbConnection->getStatement(SQLITE_INSERT_YOLO_DET);
                statement.bind(":path", imagePath);
                statement.bind(":x", det["rect"]["x"].get<int>());
                statement.bind(":y", det["rect"]["y"].get<int>());
                statement.bind(":w", det["rect"]["w"].get<int>());
                statement.bind(":h", det["rect"]["h"].get<int>());
                statement.bind(":label", det["label"].get<std::string>());
                statement.bind(":prob", det["prob"].get<float>());

                if (statement.exec() < 1)
                {
                    ofLogError("ofApp::setup") << "Error inserting image " << imagePath;
                }
            }
        }
    }
    catch (const std::exception& e)
    {
        ofLogError() << "SQLite exception: " << e.what();
    }
}


std::vector<YoloDet> ofApp::getAllLabels(const std::string& label)
{
    auto& statement = dbConnection->getStatement(SQLITE_SELECT_YOLO_DET_LABEL_EQUAL);
    statement.bind(":label", label);
    return getResults(statement);
}


std::vector<YoloDet> ofApp::getAllLabelsWithProbabilityGreaterThan(float prob)
{
    auto& statement = dbConnection->getStatement(SQLITE_SELECT_YOLO_DET_PROB_GREATER_THAN);
    statement.bind(":prob", prob);
    return getResults(statement);
}


std::vector<YoloDet> ofApp::getResults(SQLite::Statement& statement)
{
    std::vector<YoloDet> results;

    // Loop to execute the query step by step, to get one a row of results at a time.
    while (statement.executeStep())
    {
        // Demonstrate how to get some typed column value (and the equivalent explicit call)
        std::string path = statement.getColumn("path");
        int x = statement.getColumn("x");
        int y = statement.getColumn("y");
        int w = statement.getColumn("w");
        int h = statement.getColumn("h");
        float prob = statement.getColumn("prob").getDouble();
        std::string label = statement.getColumn("label");

        YoloDet det;
        det.path = path;
        det.rect = ofRectangle(x, y, w, h);;
        det.prob = prob;
        det.label = label;
        ofLoadImage(det.texture, det.path);
        results.push_back(det);
    }

    return results;
}






