//document.h
//written by Joshua Underwood
//for PA6 "editor"

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <list>
#include <string>
#include <climits>


class document
{
    public:
    //c tor/dtor
    document();
    document(const char* filename);
    ~document();

    //feature functions
        bool Readfile(const char* filename);
        bool Writefile(const char* filename);
        bool Insert(unsigned int line_number, std::string input);
        bool Delete(unsigned int line_number);
        bool Find(std::string search, std::string replace); 
        bool View(size_t beginline = 0, size_t endline = UINT_MAX);

    //getters
        const char* GetCurrentFileName() { return current_file_name.c_str(); };
        unsigned int GetLineCount() { return line_count; };

    private:
        std::string current_file_name;
        std::list<std::string> lines;
        unsigned int line_count;
};

#endif
