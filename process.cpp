#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <sstream>

#include "process.h"
using namespace std;                                                         //to get rid of repeating std::

/**
 * This functions parses values by given delimiter
 * https://stackoverflow.com/questions/2275135/splitting-a-string-by-whitespace-in-c
 * @param stringToParse given string to parse by ani given delimiter
 * @param delimiter char that says where substring may be created
 * @return vector of words
 */
vector<string> parser(const string stringToParse, char delimiter )  {
    vector<string> tokens;
    stringstream mySstream( stringToParse );
    string temp;

    while( getline( mySstream, temp, delimiter ) ) {
        tokens.push_back( temp );
    }

    return tokens;
}

vector<string> separateValues(string input){
    cout << "Your input is: \n" <<input;

    vector<string> listWithWords;
    listWithWords = parser(input, ' ');

    return listWithWords;
}
