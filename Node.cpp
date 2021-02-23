#include "Node.h"
#include <iostream>

template<class T>
Node<T>::Node(T k)
{
    this->height = 1;
    this->key = k;
    this->left = NULL;
    this->right = NULL;
}

template<class T>
T Node<T>::getKey(){
	return this->key;
}

template<class T>
int Node<T>::getHeigth()
{
	return this->height;
}

template<class T>
Node<T>* Node<T>::getLeft()
{
	return this->left;
}

template<class T>
Node<T>* Node<T>::getRigth()
{
	return this->right;
}

template<class T>
void Node<T>::setKey(T key)
{
	this->key = key;
}

template<class T>
void Node<T>::setHeigth(int h)
{
	this->height = h;
}

template<class T>
void Node<T>::setLeft(Node<T>* L)
{
	this->left = L;	
}

template<class T>
void Node<T>::setRigth(Node<T> * R)
{
	this->right = R;
}


template class Node<int>; 
