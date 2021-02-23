#include<iostream>
#include <iomanip>
#include "AVL.h"


int main(){
    AVL<int> t;
    
    std::cout<<std::right<<std::setw(40)<<"\n<[ ARBOL AVL ]>"<<std::endl;
    std::cout<<std::right<<std::setw(20)<<" Insertando datos...\n"<<std::endl;
    t.insert(50);
    t.insert(24);
    t.insert(35);
    t.insert(46);
    t.insert(57);
    t.insert(18);
    t.insert(19);
    t.insert(119);
    t.insert(100);
    t.insert(1);
    std::cout<<std::left<<std::setw(30)<<" Mostrando en inorder ... \n"<<std::endl;
    t.inorder();
    std::cout<<std::endl;
    /*t.remove(5.7);
    t.remove(6.8);
    t.remove(7.9);
    t.inorder();*/
    
    return EXIT_SUCCESS;
}