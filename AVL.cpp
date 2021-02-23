#include "AVL.h"

template <typename T>
Node<T>* AVL<T>::getRoot(){
	return root;
}

template <typename T>
int AVL<T>::getN(){
	return n;
}
template <typename T>
void AVL<T>:: setRoot(Node<T> *root){
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
    //cout<<endl;
}

template <typename T>
int AVL<T>::height(Node<T> * head)
{
    if(head==NULL) return 0;
    return head->getHeigth();
}

template <typename T>
Node<T>* AVL<T>::rightRotation(Node<T> * head)
{
    Node<T> * newhead = head->getLeft();
    //head->getLeft() = newhead->getRigth();
    head->setLeft( newhead->getRigth() );
    //newhead->getRigth() = head;
    newhead->setRigth( head );
    head->setHeigth( 1+ std::max(height(head->getLeft()), height(head->getRigth())) );// = 1+max(setHeight(head->getLeft()), setHeight(head->getRigth()));
    newhead->setHeigth( 1+ std::max(height(newhead->getLeft()), height(newhead->getRigth())) );// = 1+max(setHeight(newhead->getLeft()), setHeight(newhead->getRigth()));
    return newhead;
}
template<typename T>
Node<T> * AVL<T>::leftRotation(Node<T> * head)
{
    Node<T> * newhead = head->getRigth();
    head->setRigth( newhead->getLeft() );// = newhead->getLeft();
    newhead->setLeft( head );// = head;
    head->setHeigth( 1+ std::max( height(head->getLeft() ) , height(head->getRigth() )) ); 
    newhead->setHeigth( 1+ std::max( height(newhead->getLeft() ) , height(newhead->getRigth() )) );
    return newhead;
}

template <typename T>
void AVL<T>::inorderUtil(Node<T> * head)
{
    if(head==NULL) return ;
    inorderUtil(head->getLeft());
    std::cout<<head->getKey()<<" ";
	inorderUtil(head->getRigth());
}

template <typename T>
Node<T>* AVL<T>::insertUtil(Node<T>* head, T x) 
{
    if (head == NULL) {
        n += 1;
        Node<T>* temp = new Node<T>(x);
        return temp;
    }
    if (x < head->getKey())
        head->setLeft(insertUtil(head->getLeft(), x));
    else if (x > head->getKey())
        head->setRigth(insertUtil(head->getRigth(), x));
    head->setHeigth(1+ std::max(height(head->getLeft()),height(head->getRigth())));
    int bal = height(head->getLeft()) - height(head->getRigth());
    if (bal > 1) {
        if (x < head->getLeft()->getKey()) {
            return rightRotation(head);
        }
        else {
            head->setLeft(leftRotation(head->getLeft()));
            return rightRotation(head);
        }
    }
    else if (bal < -1) {
        if (x > head->getRigth()->getKey()) {
            return leftRotation(head);
        }
        else {
            head->setRigth(rightRotation(head->getRigth()));
            return leftRotation(head);
        }
    }
    return head;
}


template <typename T>

Node<T>* AVL <T> :: removeUtil(Node<T>* head, T x) {
    if (head == NULL) return NULL;
    if (x < head->key) {
        head->setLeft() = removeUtil(head->getLeft(), x);
    }
    else if (x > head->key) {
        head->setRight() = removeUtil(head->getRight(), x);
    }
    else {
        Node<T>* r = head->getRight();
        if (head->getRight() == NULL) {
            Node<T>* l = head->getLeft();
            delete(head);
            head = l;
        }
        else if (head->getLeft() == NULL) {
            delete(head);
            head = r;
        }
        else {
            while (r->getLeft() != NULL) r = r->getLeft();
            head->setKey() = r->getKey();https:
            head->setRight() = removeUtil(head->getRight(), r->getKey());///..
        }
    }
    if (head == NULL) return head;
    head->setHeight() = 1 + std::max(setHeight(head->getLeft()), setHeight(head->getLight));
    int bal = setHeight(head->getLeft()) - setHeight(head->getRight());
    if (bal > 1) {
        if (x > head->getLeft()->getKey()) {
            return rightRotation(head);
        }
        else {
            head->setLeft() = leftRotation(head->getLeft);
            return rightRotation(head);
        }
    }
    else if (bal < -1) {
        if (x < head->getRight()->getKey()) {
            return leftRotation(head);
        }
        else {
            head->setRight() = rightRotation(head->getRight());
            return leftRotation(head);
        }
    }
    return head;
}
