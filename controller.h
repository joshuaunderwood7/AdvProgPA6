//controller.h
//written by Joshua Underwood
//for PA6 "editor"

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "document.h"

//takes cin and document as input and prompts user for command
//PROMPT then executes the command and returns false if the 
//user has given exit command, true otherwise.
bool PROMPT(std::istream &in, document &theDocument);

bool GREETING(void);
#endif
