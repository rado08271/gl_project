//
// Created by rafig on 17. 5. 2019.
//

#ifndef GL_TASK_PROCESS_H
#define GL_TASK_PROCESS_H
#include <set>

std::set<std::string> separateValues(std::string input);
std::set<std::string> getRidOfUnwanted(std::set<std::string> toChange, int smallest, int largest);
std::string deleteObsoleteCharacters(std::string input);
void outputIntoFile(std::set<std::string> suitableValues);
#endif //GL_TASK_PROCESS_H
