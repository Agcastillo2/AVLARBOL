/***********************************************************************
 * Module:  Console.cpp
 * Author:  ismae
 * Modified: lunes, 8 de febrero de 2021 1:24:35
 * Purpose: Implementation of the class Console
 ***********************************************************************/

#include "Console.h"
#include <windows.h>

Console::Console(){
	SetConsoleTitle("PICKPERSON");
}

////////////////////////////////////////////////////////////////////////
// Name:       Console::hideCursor()
// Purpose:    Implementation of Console::hideCursor()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Console::hideCursor(bool value)
{
   CONSOLE_CURSOR_INFO cci = { 100, value }; // El segundo miembro de la estructura indica si se muestra el cursor o no.

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

////////////////////////////////////////////////////////////////////////
// Name:       Console::changeSize()
// Purpose:    Implementation of Console::changeSize()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Console::changeSize(int width ,int heigth)
{
   
   _COORD size;
    _SMALL_RECT rect;
    size.X = width;
    size.Y = heigth;

    rect.Top = 0;
    rect.Left = 0;
    rect.Right = width - 1;
    rect.Bottom = heigth - 1;

    HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(_console, size);
    SetConsoleWindowInfo(_console, TRUE, &rect);
   
}

////////////////////////////////////////////////////////////////////////
// Name:       Console::gotoXY()
// Purpose:    Implementation of Console::gotoXY()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Console::gotoXY(int x ,int y)
{
   HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

////////////////////////////////////////////////////////////////////////
// Name:       Console::changeColor()
// Purpose:    Implementation of Console::changeColor()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Console::changeColor(int texto, int fondo)
{
   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wColor = ((fondo & 0x0F) << 4) + (texto & 0x0F); 
    SetConsoleTextAttribute(h, wColor);
}
