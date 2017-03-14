#include "ofApp.h"


void ofApp::setup()
{
    
    // A map of our data.
    std::vector<SurnameDatum> data;

    // Load the data into a buffer.
    ofBuffer buffer = ofBufferFromFile("Top1000.csv");

    // Keep track of the first line, so we can skip it.
    bool isFirstLine = true;

    // Iterate through lines.
    for (auto line: buffer.getLines())
    {
        if (isFirstLine)
        {
            // Skip the first line.
            isFirstLine = false;
            continue;
        }

        // Split the line entry into string tokens.
        std::vector<std::string> fields = ofSplitString(line, ",");

        // Convert the string tokens into numbers as needed.
        SurnameDatum datum;
        datum.surname = fields[0];
        datum.rank = ofToInt(fields[1]);
        datum.count = ofToInt(fields[2]);
        datum.proportionPer100k = ofToFloat(fields[3]);
        datum.cumulativeProportionPer100k =ofToFloat(fields[4]);
        datum.percentWhite = ofToFloat(fields[5]);
        datum.percentBlack = ofToFloat(fields[6]);
        datum.percentAsianPacificIslanders = ofToFloat(fields[7]);
        datum.percentAmericanIndianAndAlaskanNative = ofToFloat(fields[8]);
        datum.percentTwoPlusRaces = ofToFloat(fields[9]);
        datum.percentHispanic = ofToFloat(fields[10]);

        // Add the name to our collection.
        data.push_back(datum);

    }

    // 1. From the vector, create a map between `name` and `count` (with rank less than 100).

    std::map<std::string, int> surnameCountMap;

    for (auto datum: data)
    {
        if (datum.rank < 100)
            surnameCountMap[datum.surname] = datum.count;
    }

    // 1.1. Remove any names whose second letter is `E`.
    auto it = surnameCountMap.begin();
    while (it != surnameCountMap.end())
    {
        std::string surname = it->first;

        if (surname[1] == 'E')
        {
            it = surnameCountMap.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // 1.2. Calculate the total count for that subgroup and print that number.

    int count = 0;
    for (auto entry: surnameCountMap)
    {
        count += entry.second;
    }

    std::cout << "Count: " << count << std::endl;

    // 1.3. Did you get 41268464?

    // 2. Make a "histogram" counts by first letter of the surname.
    // i.e. How many names start with A? How many names start with B? etc?
    std::map<char, int> firstLetterCountMap;

    for (char letter = 'A'; letter <= 'Z'; ++letter)
    {
        firstLetterCountMap[letter] = 0;
    }

    // 2.1. What is the most popular first letter?

    for (auto datum: data)
    {
        firstLetterCountMap[datum.surname[0]] += 1;
    }

    auto maxValues = std::make_pair('A', std::numeric_limits<int>::lowest());

    for (auto entry: firstLetterCountMap)
    {
        if (entry.second >= maxValues.second)
        {
            maxValues = entry;
        }
    }

    std::cout << maxValues.first << " : " << maxValues.second << std::endl;

    // Did you get "M"?

    // 2.2 What letters(s) have a count of zero?

    for (auto entry: firstLetterCountMap)
    {
        if (entry.second == 0)
        {
            std::cout << entry.first << std::endl;
        }
    }

    // 3. std::vectors can be sorted in many ways, including via a custom
    // "lambda" function.

    // The following lambda function sorts a std::vector in descending order
    // (the > sign determines ascending / descending) by comparing its
    // percentHispanic value.

    std::sort(data.begin(), data.end(), [](SurnameDatum a, SurnameDatum b) {
        return a.percentHispanic > b.percentHispanic;
    });

    // Thus, the first three highest percent Hispanic names would be
    // data[0], data[1], data[2].

    for (auto i = 0; i < 3; ++i)
        std::cout << data[i].percentHispanic << " " << data[i].surname << std::endl;

    // 3.1 Using a similar std::sort and lambda function, sort the data to find
    // the three _lowest_ percentWhite names.

    // Did you get ZHANG, YANG and HUYNH?

    std::sort(data.begin(), data.end(), [](SurnameDatum a, SurnameDatum b) {
        return a.percentWhite < b.percentWhite;
    });

    for (auto i = 0; i < 3; ++i)
        std::cout << data[i].percentWhite << " " << data[i].surname << std::endl;


    // We are done here.
    ofExit();
}
