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
int AVL<T>::height(Node * head){
    if(head==NULL) return 0;
    return head->getHeight();
}

template <typename T>
Node<T> * AVL<T>::rightRotation(Node * head){
    Node * newhead = head->getLeft();
    head->getLeft() = newhead->getRigth();
    newhead->getRigth() = head;
    head->getHeight() = 1+max(setHeight(head->getLeft()), setHeight(head->getRigth()));
    newhead->getHeight() = 1+max(setHeight(newhead->getLeft()), setHeight(newhead->getRigth()));
    return newhead;
}
template<typename T>
Node<T> * leftRotation(Node * head){
            Node * newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
}

template <typename T>
void AVL<T>::inorderUtil(Node * head){
    if(head==NULL) return ;
    inorderUtil(head->getLeft());
    cout<<head->getKey()<<" ";
	inorderUtil(head->getRight());
}
