#include "document.h"
#include <iostream>
#include "controller.h"

int main(int argc, const char *argv[])
{
    if(argc == 2)
    {
        GREETING();
        document doc(argv[1]);
        while(PROMPT(std::cin, doc)) {}
    }
    else
    {
        std::cout << "enter filename on command line to edit\n" 
                  << "pa6 <filename>\n";
        return 1;
    }
    return 0;
}
