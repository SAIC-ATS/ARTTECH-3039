#pragma once


#include "ofMain.h"


/// Data description:
/// http://www2.census.gov/topics/genealogy/2000surnames/surnames.pdf
struct SurnameDatum
{
    /// Surname.
    std::string surname;

    /// Rank (1 is most common).
    int rank = 0;

    /// Number of occurances.
    int count = 0;

    /// Proportion per 100,000 for name.
    float proportionPer100k = 0.0f;

    /// Cumulative proportion per 100,000 people for name.
    float cumulativeProportionPer100k = 0.0f;

    /// Percent Non-Hispanic White Only.
    float percentWhite = 0.0f;

    /// Percent Non-Hispanic Black Only.
    float percentBlack = 0.0f;

    /// Percent Non-Hispanic Asian and Pacific Islanders Only.
    float percentAsianPacificIslanders = 0.0f;

    /// Percent Non-Hispanic American Indian and Alaskan Native Only.
    float percentAmericanIndianAndAlaskanNative = 0.0;

    /// Percent Non-Hispanic Two of More Races.
    float percentTwoPlusRaces = 0.0f;

    /// Percent Hispanic origin.
    float percentHispanic = 0.0f;

};



class ofApp: public ofBaseApp
{
public:
    void setup();

};
