#include <iostream>
#include <fstream>

#include "process.h"
using namespace std;                                                            //to get rid of repeating std::

int main(int argc, char** argv){
    ifstream inputFile;                                                         //inited var of strings
    inputFile.open("input.txt");                                                //opens file to read from

    if(inputFile.fail()){
        cout << "Problem occurred while opening file" << endl;
        return -1;
    }

    if(inputFile.eof()){
        cout << "File is empty!" << endl;
        return -1;
    }

    string readInput;                                                           //to read the input
    getline(inputFile , readInput);                                             //to get input from file

    inputFile.close();                                                          //close file...to free fd table with this file

    cout << "Inputed string is: \n" << readInput << endl;
    cout << "Processing..." << endl;


    //sets are superior for this task
    //it deletes word that duplicates and sorts them
    //set sorts values in O(logn) meanwhile vector does it in O(n)
    //this means that for 10 values it's 10 times faster
    // O(10) = 10
    // O(log(10)) = 1

//================================ deleting obsolete characters =======================================
//    readInput = deleteObsoleteCharacters(readInput);                            //to delete punct

//===================================== separating values into set =================================
    set<string> separatedValues = separateValues(readInput);                    //get separated values

//====================================== range defined by user ===================================
/*
    int shortest, longest;

    cout << "Length of shortest word: " << endl;
    cin >> shortest;
    cout << "Length of longest word: " << endl;
    cin >> longest;

    set<string> suitableValues = getRidOfUnwanted(separatedValues, shortest, longest);       //gets values that are in given range (4,8);
*/

    cout << "Input processed..." << endl;
    cout << "Writing to file..." << endl;

//================================= output when conditions for range ==================================
//    outputIntoFile(suitableValues);                                             //writes to file

//============================================ normal output ==========================================
    outputIntoFile(separatedValues);                                             //writes to file

    cout << "Finished..." << endl;
    return 0;
}
