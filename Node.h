#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
private:

	T key;
    int height;
    Node<T> * left;
    Node<T> * right;
	    
public:
    	
    Node<T>(T k);
    T getKey();
    int getHeigth();
    Node<T>* getLeft();
    Node<T>* getRigth();
    void setKey(T);
    void setHeigth(int);
	void setLeft(Node<T>*);
	void setRigth(Node<T> *);		
};

#endif