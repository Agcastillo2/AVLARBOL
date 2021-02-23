#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "Node.h"

template <typename T>
class AVL{
    public:
    	
        // CREAR GET Y SET DE ROOT Y N -> CAMILA
        
        Node<T>* getRoot();
        int getN();
        void setN(int n);
        void setRoot(Node<T>* root);
        void insert(T x);
        void inorder();
		Node<T>* RotacionCompuestaID(Node<T>*, Node<T>*);
		Node<T>* RotacionCompuestaDI(Node<T>*, Node<T>*);
		
    private:
    	Node<T> * root = NULL;
        int n;
        int height(Node<T> * head);      
        
        Node<T> * rightRotation(Node<T> * head);
		
        Node<T> * leftRotation(Node<T> * head);
	
        void inorderUtil(Node<T> * head);

        Node<T> * insertUtil(Node<T>*,T);
       
};

/*
template <class T>
Node<T>* AVL<T>::RotacionCompuestaID(Node<T> * Apunt, Node<T>* ApAux1)
{
    Node<T>* ApAux2;
    ApAux2 = ApAux1->getHijoDer();
    Apunt->setHijoIzq(ApAux2->getHijoDer());
    ApAux2->setHijoDer(Apunt);
    ApAux1->setHijoDer(ApAux2->getHijoIzq());
    ApAux2->setHijoIzq(ApAux1);
    if (ApAux2->getFE() == - 1)
        Apunt->setFE(1);
    else
        Apunt->setFE(0);
    if (ApAux2->getFE() == 1)
        ApAux1->setFE(- 1);
    else
        ApAux1->setFE(0);
    return ApAux2;
}

template <class T>
Node<T>* AVL<T>::RotacionCompuestaDI(Node<T> * Apunt, Node<T>* ApAux1)
{
    Node<T>* ApAux2;
    ApAux2 = ApAux1->getHijoIzq();
    Apunt->setHijoDer(ApAux2->getHijoIzq());
    ApAux2->setHijoIzq(Apunt);
    ApAux1->setHijoIzq(ApAux2->getHijoDer());
    ApAux2->setHijoDer(ApAux1);
    if (ApAux2->getFE() == 1)
        Apunt->setFE(- 1);
    else
        Apunt->setFE(0);
    if (ApAux2->getFE() == - 1)
        ApAux1->setFE(1);
    else
        ApAux1->setFE(0);
    return ApAux2;
}
*/
#endif
