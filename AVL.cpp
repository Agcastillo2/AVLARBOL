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
void AVL<T> ::inorder(){
    inorderUtil(root);
    cout<<endl;
}

template <typename T>
int AVL<T> ::height(Node * head){
    if(head==NULL) return 0;
    return head->height;
}

template <typename T>
Node<T> * AVL<T>::rightRotation(Node * head){
    Node * newhead = head->getLeft;
    head->getLeft = newhead->getRigth;
    newhead->getRigth = head;
    head->height = 1+max(height(head->getLeft), height(head->getRigth));
    newhead->height = 1+max(height(newhead->getLeft), height(newhead->getRigth));
    return newhead;
}

