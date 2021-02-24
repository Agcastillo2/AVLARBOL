/***********************************************************************
 * Module:  Main.cpp
 * Author:  ismae
 * Modified: domingo, 7 de febrero de 2021 22:59:50
 * Purpose: Main
 ***********************************************************************/
#include<iostream>
#include <iomanip>
#include <string>
#include "AVL.h"
#include "Menu.h"
#include "Color.h"
//#define _GLIBCXX_USE_CXX11_ABI 0

using namespace std;

int main(int argc, char** argv){
    AVL<int> t;
    Menu menu;
    int option = 0, value = 0;
    string mainMenu[] = { "Ingresar dato","Eliminar","Ver Arbol","Salir" };
    
    
    do{
    	
    	option = menu.makeMenu("ArbolesAVL",mainMenu,4);
    	
    	switch (option)
        {
        	case 1:
			{
				//Insertar
        		system("cls");
        		std::cout<<ansi::reset<<"\n\n"<<std::right<<std::setw(40)<<" Ingrese un numero entero: ";
        		std::cin>>value;
        		t.insert(value);
        		system("pause");
				break;
			}
        	case 2:
			{
				//Eliminar
				system("cls");
        		std::cout<<std::right<<std::setw(20)<<" Ingrese un numero entero...\n"<<std::endl;
        		std::cin>>value;
        		t.remove(value);
        		system("pause");
				break;	
			}
			case 3:
			{
				//Mostrar
				system("cls");
				
				std::cout<<ansi::reset<<std::left<<std::setw(40)<<" \nMostrando en inorder ... \n"<<std::endl;
		
    			t.inorder();
				system("pause");
				break;	
			}
			default:
				break;	
        }
    	
    	
	} while (option > 0 && option < 4);
    
    
    return EXIT_SUCCESS;
}