#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "parse.h"

string parseName(stringstream& s)
{
    
   
    char alnum;
    string name = "";
    s >> ws;
    
    while (isalnum(s.peek()))
    {
        s >> alnum;
        name += alnum;
        
    }
    
    return name;
}
