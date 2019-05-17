#include <iostream>
#include <string>
#include <list>
#include <iterator>

#include "process.h"
using namespace std;                                                //to get rid of repeating std::

int main(int argc, char** argv){
    string readInput;                                               //to read the input
    cout << "Please write a string" <<endl;
    getline(cin, readInput);                                        //to get input

    vector<string> separatedValues = separateValues(readInput);     //get separated values


    return 0;
}
