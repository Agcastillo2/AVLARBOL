/***********************************************************************
 * Module:  Menu.cpp
 * Author:  ismae
 * Modified: domingo, 7 de febrero de 2021 23:08:54
 * Purpose: Implementation of the class Menu
 ***********************************************************************/

#include "Menu.h"
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;


int Menu::makeMenu(std::string message, std::string options[], int index)
{
  	
  	
  	int selection=1;
  	int key;
  	bool flag = true;
	//screen.changeSize(60,30);
	screen.hideCursor(FALSE);
	
	do{
		
		system("cls");
		screen.gotoXY(20,12);
		screen.changeColor(RED,BLACK);
		cout<<message<<endl;
		
		
		for (int i = 0; i < index; i++) {
            if (selection == i + 1) {
                
                screen.gotoXY(20, 14 + i);
				//screen.changeColor(LIGHT_BLUE,BLACK);
				screen.changeColor(WHITE,BLACK);
                cout <<" "<<*(options+i)<<endl;
            }
            else {
                
                screen.gotoXY(21, 14 + i);
                screen.changeColor(GRAY,BLACK);
                cout << *(options + i);
            }
        }
        
        do {
            key = _getch();
        } while (key != UP && key != DOWN && key != ENTER);
        
        switch (key) {
        case UP:
            selection--;
            if (selection <= 0) {
                selection = index;
            }
            break;
        case DOWN:
            selection++;
            if (selection > index) {
                selection = 1;
            }
            break;
        case ENTER:
            flag = false;
            break;
        }
		
	}while(flag);   
  	
  	return selection;
}