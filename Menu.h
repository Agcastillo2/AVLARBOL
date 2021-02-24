/***********************************************************************
 * Module:  Menu.h
 * Author:  ismae
 * Modified: domingo, 7 de febrero de 2021 23:08:54
 * Purpose: Declaration of the class Menu
 ***********************************************************************/

#if !defined(__Taller_Menu_h)
#define __Taller_Menu_h

#include <string> 
#include "Console.h"

class Menu
{
public:
   int makeMenu(std::string message, std::string[] , int index);

private:
	Console screen;
};

#endif
