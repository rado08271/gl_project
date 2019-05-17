#include <iostream>

#include "process.h"
using namespace std;                                                //to get rid of repeating std::

int main(int argc, char** argv){
    string readInput;                                               //to read the input
    cout << "Please write a string" <<endl;
    getline(cin, readInput);                                        //to get input

    readInput = deleteObsoleteCharacters(readInput);

    //after some digging i found out that sets are superior in c++ for this task
    //it deletes word that duplicates and sorts them
    //set sorts values in O(logn) meanwhile vector does it in O(n)
    set<string> separatedValues = separateValues(readInput);     //get separated values
//    set<string> value = getRidOfUnwanted(separatedValues, 4, 8);

    return 0;
}
