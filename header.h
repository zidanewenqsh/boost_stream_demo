#ifndef __HEADER_H__
#define __HEADER_H__
#include <iostream>
#include <string>
#define RESET "\033[0m";
#define REDCOLOR "\033[31m";    
#define GREENCOLOR "\033[32m";  
#define YELLOWCOLOR "\033[33m"; 
#define BLUECOLOR "\033[34m";   
#define PURPLECOLOR "\033[35m"; 
#define CYANCOLOR "\033[36m";  
#define LREDCOLOR "\033[91m";    
#define LGREENCOLOR "\033[92m";  
#define LYELLOWCOLOR "\033[93m"; 
#define LBLUECOLOR "\033[94m";   
#define LPURPLECOLOR "\033[95m"; 
#define LCYANCOLOR "\033[96m";  
enum Color {
    RED = 0,
    GREEN = 1,
    YELLOW = 2,
    BLUE = 3,
    PURPLE = 4,
    CYAN = 5,
    LRED,
    LGREEN,
    LYELLOW,
    LBLUE,
    LPURPLE,
    LCYAN,
    NumberOfColors,
};

#endif