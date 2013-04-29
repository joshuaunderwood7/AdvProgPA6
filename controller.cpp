#include "controller.h"
#include <stdlib.h>

//takes cin and document as input and prompts user for command
//PROMPT then executes the command and returns false if the 
//user has given exit command, true otherwise.
bool PROMPT(std::istream &in, document &theDocument)
{
    std::string input, find;
    getline(in, input);

    std::string::iterator it = input.begin();
    char command = *it;
    unsigned int line_number = 0;

    switch(command)
    {
        case 'R':
            it++;
            while(it != input.end() && *it != ' ') { it++; }
            while(*it == ' ') it++;
            input.erase(input.begin(), it);
            if(input.length()>0) theDocument.Readfile(input.c_str());
            else theDocument.Readfile(theDocument.GetCurrentFileName());
            return true;
        break;
        case 'W':
            it++;
            while(it != input.end() && *it != ' ') { it++; }
            while(*it == ' ') it++;
            input.erase(input.begin(), it);
            if(input.length()>0) theDocument.Writefile(input.c_str());
            else theDocument.Writefile(theDocument.GetCurrentFileName());
            return true;
        break;
        case 'I':
            it++;
            while(it != input.end() && *it != ' ') { it++; };
            while(*it == ' ') it++;
            input.erase(input.begin(), it);
            it = input.begin();

            while(it != input.end() && *it != ' ') 
            { 
                line_number *= 10;
                line_number += *it - '0'; 
                it++; 
            }
            while(it != input.end() && *it == ' ') it++;
            input.erase(input.begin(), it);

            theDocument.Insert(line_number, input);
            return true;
        break;
        case 'D':
            it++;
            while(it != input.end() && *it != ' ') { it++; };
            while(*it == ' ') it++;
            input.erase(input.begin(), it);
            it = input.begin();

            while(it != input.end() && *it != ' ') 
            { 
                line_number *= 10;
                line_number += *it - '0'; 
                it++; 
            }
            while(it != input.end() && *it != ' ') it++;
            input.erase(input.begin(), it);

            theDocument.Delete(line_number);
            return true;
        break;
        case 'F':
            it++;
            while(it != input.end() && *it != ' ') { it++; };
            while(*it == ' ') it++;
            input.erase(input.begin(), it);
            it = input.begin();

            while(it != input.end() && *it != ' ') it++; 
            find = std::string(input.begin(), it);
            input.erase(input.begin(), it);
            it = input.begin();

            while(it != input.end() && *it != ' ') it++;
            while(*it == ' ') it++;
            input.erase(input.begin(), it);

            theDocument.Find(find, input);
            return true;
        break;
        case 'V':
            theDocument.View();
            return true;    
        break;

        case 'q':
            return false;    
        break;
        default:
            std::cout << "?" << std::endl;
            return true;
        break;
    }
};


bool GREETING(void)
{
    std::cout << "Greetings user." << std::endl
              << "This program was made for CSCI 3320 "
              << "Program Assignment 6 Spring 2013:" << std::endl
              << "By: Joshua Underwood" << std::endl
              << "This is a standard text editor" << std::endl
              << "good luck." << std::endl
              << "(q quits)"
              << std::endl << std::endl;
    return true;
};
