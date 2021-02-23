#include "AVL.h"

template <typename T>
Nodo<T>* AVL<T>::getRoot(){
	return root;
}

template <typename T>
int AVL<T>::getN(){
	return n;
}
template <typename T>
void AVL<T>:: setRoot(Nodo<T> *root){
	this->root=root;
	
}
template <typename T>
void AVL<T>:: setN(int n){
	this->n=n;
}

template <typename T>
void AVL<T>::insert(T x){
    root=insertUtil(root, x);
}

template <typename T>
void inorder(){
    inorderUtil(root);
    cout<<endl;
}

template <typename T>
int height(Node * head){
    if(head==NULL) return 0;
    return head->height;
}