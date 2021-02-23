#ifndef AVL_H
#define AVL_H
#include "Node.h"

template <typename T>
class AVL{
    public:
        
        Node<T> * root = NULL;
        int n;
        void insert(T x){
            root=insertUtil(root, x);
        }
        void inorder(){
            inorderUtil(root);
            cout<<endl;
        }
    private:
        int height(Node * head){
            if(head==NULL) return 0;
            return head->height;
        }
        Node<T> * rightRotation(Node * head){
            Node * newhead = head->left;
            head->left = newhead->right;
            newhead->right = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        Node<T> * leftRotation(Node * head){
            Node * newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1+max(height(head->left), height(head->right));
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        void inorderUtil(Node * head){
            if(head==NULL) return ;
            inorderUtil(head->left);
            cout<<head->key<<" ";
            inorderUtil(head->right);
        }

        Node<T> * insertUtil(Node<T> * head, T x){
            if(head==NULL){
                n+=1;
                Node<T><T> * temp = new Node<T>(x);
                return temp;
            }
            if(x < head->key) head->left = insertUtil(head->left, x);
            else if(x > head->key) head->right = insertUtil(head->right, x);
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if(bal>1){
                if(x < head->left->key){
                    return rightRotation(head);
                }else{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }else if(bal<-1){
                if(x > head->right->key){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }
        
        
};

#endif