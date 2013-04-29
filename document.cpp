#include "document.h"
#include <iostream>
#include <fstream>

//c tor/dtor
document::document() {};

document::document::document(const char* filename)
{
    if(Readfile(filename)) line_count = lines.size();
    else
    {
        if(Writefile(filename)) 
            if(Readfile(filename)) line_count = lines.size();
        else 
        {
            std::cerr << "Error creating " << current_file_name 
                      << ". Cannot open." << std::endl;
        }
    }
};

document::~document() {};

//feature functions
bool document::Readfile(const char* filename)
{
   std::ifstream f;
   f.open(filename); 
   if(!f.is_open()) return false;
   while(!f.eof())
   {
       std::string line;
       std::getline(f, line, '\n');
       line.push_back('\n');       //add newline to end of input string
       lines.push_back(line);
       f.peek();
   }
   f.close();
   current_file_name = std::string(filename);
   return true;
};

bool document::Writefile(const char* filename)
{
   std::ofstream f;
   f.open(filename); 
   if(!f.is_open()) return false;
   std::list<std::string>::iterator it;
   for(it = lines.begin(); it != lines.end(); it++)
   {
       f << *it;
   }
   f.close();
   return true;
};

bool document::Insert(unsigned int line_number, std::string input)
{
   line_number--;
   line_count = lines.size();
   input.push_back('\n');       //add newline to end of input string

   if(line_number > line_count)
   {
       lines.push_back(input);
       return true;
   }
 
   std::list<std::string>::iterator it;
   it = lines.begin();
   for(unsigned int i = 0; i < line_number; ++i) it++;
   lines.insert(it, input);
   return true;
}

bool document::Delete(unsigned int line_number)
{
   line_number--;
   line_count = lines.size();
   if(line_number > line_count) 
   {
       std::cerr << "error: Delete line " << line_number 
                 << ". Line does not exist" << std::endl;
       return false;
   }

   std::list<std::string>::iterator it;
   it = lines.begin();
   for(unsigned int i = 0; i < line_number; ++i) it++;
   lines.erase(it);
   return true;
}

bool document::Find(std::string search, std::string replace) 
{
   std::list<std::string>::iterator it;
   size_t pos;       
   for( it = lines.begin(); it != lines.end(); it++) 
   {
       pos = it->find(search);
       if(pos != std::string::npos)
       {
           it->replace(pos, search.length(), replace);
           return true;
       }
   }
   return false;
};


bool document::View(size_t beginline, size_t endline)
{
   line_count = lines.size();
   if(endline > line_count) endline = line_count;

   std::list<std::string>::iterator it;
   it = lines.begin();
   unsigned int i;
   for(i = 0; i < beginline; ++i) it++;

   for( ; i < endline; ++i)
   {
       std::cout << *it;
       it++;
   }
   return true;
}

