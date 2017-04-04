#pragma once


#include "ofMain.h"
#include "ofxSQLiteCpp.h"

struct YoloDet
{
    ofTexture texture;
    std::string path;
    ofRectangle rect;
    std::string label;
    float prob = 0.0f;
};


class ofApp: public ofBaseApp
{

public:
    void setup();
    void update();
    void draw();

    void setupDatabaseConnection(const std::string& databasePath);
    void loadDetsIntoDatabase();

    void keyPressed(int key);

    std::vector<YoloDet> getAllLabels(const std::string& label);
    std::vector<YoloDet> getAllLabelsWithProbabilityGreaterThan(float prob);

    std::vector<YoloDet> getResults(SQLite::Statement& statement);

    std::vector<YoloDet> currentDets;

    // Database Connection.
    std::unique_ptr<SQLite::SQLiteConnection> dbConnection;

    static const std::string SQLITE_CREATE_YOLO_DET_TABLE;
    static const std::string SQLITE_INSERT_YOLO_DET;
    static const std::string SQLITE_SELECT_YOLO_DET_LABEL_EQUAL;
    static const std::string SQLITE_SELECT_YOLO_DET_PROB_GREATER_THAN;

};
