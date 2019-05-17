#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <fstream>

#include "process.h"
using namespace std;                                                                //to get rid of repeating std::

/**
 * This functions parses values by given delimiter
 * https://stackoverflow.com/questions/2275135/splitting-a-string-by-whitespace-in-c
 * @param stringToParse given string to parse by ani given delimiter
 * @param delimiter char that says where substring may be created
 * @return set of words
 */
set<string> parser(string stringToParse, char delimiter )  {
    transform(stringToParse.begin(),
              stringToParse.end(),
              stringToParse.begin(),
              ::tolower);                                                           //fastest way is to ignore case while sorting

    set<string> tokens;                                                             //declare set of tokens
    stringstream stringStream( stringToParse );                                     //stringStream for getLine function
    string temp;                                                                    //temporary string

    while( getline( stringStream, temp, delimiter ) ) {                             //while there is a line insert values from stram into temp string and delimit
        tokens.insert(temp);                                                        //insert delimited string into set
    }

    return tokens;
}


/**
 * Get rid of words that are unwanted does not suit given length
 * @param toChange set to work with and from which you decide what words should stay
 * @param shortest shortest possible string
 * @param longest  longest possible string
 * @return suitable data
 */
set<string> getRidOfUnwanted(set<string> toChange, int shortest, int longest){
    set<string>::iterator iterate;                                                  //creates an iterator of strings

    set<string> toFill;                                                             //fills this set with suitable strings...doing it this way may prevent iterator problems

    for (iterate = toChange.begin(); iterate != toChange.end(); iterate++) {        //init iterator with values of given set doing it till the end
        string actValue = *iterate;                                                 //gets value from iterator (string)
        if(actValue .length() >= shortest && actValue .length() <= longest)         //checks conditions
            toFill.insert(actValue);                                                //inserts value of iterator into the string if it suits given conditions
    }

    return toFill;
}

/**
 * This function deletes puntuation
 * @param input string full of obsolete characters
 * @return clean string with no exclamation marks,..
 */
string deleteObsoleteCharacters(string input){
    string out;                                                                     //string that will return new value without punctuation

    for( char c: input )                                                            //for each character in string check condition if char is punct get rid of it
        if(!ispunct(c))
            out += c;

//    input.erase(remove_if(input.begin(), input.end(), [](char c) {return ispunct(c);}), input.end());                 //this does the same using lambda expression

    return out;
}

/**
 * Function just writes set to file
 * @param suitableValues set to output
 */
void outputIntoFile(set<string> suitableValues){
    ofstream outputFile;                                                            //output stream
    outputFile.open("output.txt");            //opens the file

    for (const string s: suitableValues){                                           //writes everything to output
        outputFile << s << "\t\t\t\t\t\t" << endl;
    }

    outputFile.close();                                                             //closes the file
}

/**
 * this funtion separates string to set of words by whitespace
 * @param input string
 * @return separated set
 */
set<string> separateValues(string input){
    set<string> listWithWords;
    listWithWords = parser(input, ' ');

    return listWithWords;
}
