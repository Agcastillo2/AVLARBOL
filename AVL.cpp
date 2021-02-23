#include "AVL.h"

template <typename T>

Nodo<T> *::AVL getRoot(){
	return root;
}

int AVL::getN(){
	return n;
}
template <typename T>
void AVL:: setRoot(Nodo<T> *root){
	this->root=root;
	
}

void AVL:: setN(int n){
	n=n;
}
