#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>

#include "process.h"
using namespace std;                                                         //to get rid of repeating std::

/**
 * This functions parses values by given delimiter
 * https://stackoverflow.com/questions/2275135/splitting-a-string-by-whitespace-in-c
 * @param stringToParse given string to parse by ani given delimiter
 * @param delimiter char that says where substring may be created
 * @return vector of words
 */
set<string> parser(const string stringToParse, char delimiter )  {
    set<string> tokens;                                                             //dec for set of tokens
    stringstream stringStream( stringToParse );                                     //stringStream for getLine function
    string temp;                                                                    //temporary string

    while( getline( stringStream, temp, delimiter ) ) {                             //while there is a line insert values from stram into temp string and delimit
        tokens.insert(temp);                                                        //insert delimited string into set
    }

    return tokens;
}


/**
 *
 * @param toChange
 * @param values
 * @return
 */
set<string> getRidOfUnwanted(set<string> toChange, int smallest, int largest){
    set<string>::iterator iterate;                                                  //creates an iterator of strings

    set<string> toFill;                                                             //fills this set with suitable strings...doing it this way may prevent iterator problems

    for (iterate = toChange.begin(); iterate != toChange.end(); iterate++) {        //init iterator with values of given set doing it till the end
        string actValue = *iterate;                                                 //gets value from iterator (string)
        if(actValue .length() >= smallest && actValue .length() <= largest)         //checks conditions
            toFill.insert(actValue);                                                //inserts value of iterator into the string if it suits given conditions

        cout << actValue  << endl;
    }

    return toFill;
}

/**
 *
 * @param input
 * @return
 */
string deleteObsoleteCharacters(string input){
    string out;                                                                     //string that will return new value without punctuation

    for( char c: input)                                                             //for each character in string check condition if char is punct get rid of it
        if(!ispunct(c))
            out += c;

//    input.erase(remove_if(input.begin(), input.end(), [](char c) {return ispunct(c);}), input.end());                 //this does the same using lambda expression

    return out;
}

set<string> separateValues(string input){
    set<string> listWithWords;
    listWithWords = parser(input, ' ');

    return listWithWords;
}
