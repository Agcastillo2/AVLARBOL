#include<iostream>
#include "AVL.h"




int main(){
    AVL<int> t;
    t.insert(50);
    t.insert(24);
    t.insert(35);
    t.insert(46);
    t.insert(57);
    t.insert(18);
    t.insert(19);
    t.inorder();
    /*t.remove(5.7);
    t.remove(6.8);
    t.remove(7.9);
    t.inorder();*/
    
    return EXIT_SUCCESS;
}