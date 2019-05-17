#include <iostream>
#include <fstream>

#include "process.h"
using namespace std;                                                    //to get rid of repeating std::

int main(int argc, char** argv){
    ifstream inputFile;                                                 //inited var of strings
    inputFile.open("C://Users/rafig/Desktop/cLion/gl_task/input.txt");  //opens file to read from
    string readInput;                                                   //to read the input
    getline(inputFile , readInput);                                     //to get input from file

    inputFile.close();                                                  //close file...to free fd table with this file

    cout << "Inputed string is: \n" << readInput << endl;
    cout << "Processing..." << endl;


    //after some digging i found out that sets are superior in c++ for this task
    //it deletes word that duplicates and sorts them
    //set sorts values in O(logn) meanwhile vector does it in O(n)
    readInput = deleteObsoleteCharacters(readInput);                    //to delete punctuatuins
    set<string> separatedValues = separateValues(readInput);            //get separated values
    set<string> suitableValues = getRidOfUnwanted(separatedValues, 4, 8);           //gets values that are in given range (4,8);

    cout << "Input processed..." << endl;
    cout << "Writing to file..." << endl;

    outputIntoFile(suitableValues);                                     //writes to file

    cout << "Finished..." << endl;
    return 0;
}
