#include"headers.h"

class Node{
    public:
    Node * left;
    Node * right;
    int key;

    Node(int key){
        this->key = key;
        left = right = nullptr;
    }

};

class AVLTree{

    Node * root_node;

    Node * RotateLeft(Node * x){
        Node * y = x->right;
        Node * T = y->left;
        y->left = x;
        x->right = T;
        return y;
    }

    Node * RotateRight(Node * x){
        Node * y = x->left;
        Node * T = y->right;
        y->right = x;
        x->left =T;
        return y;
    }

    int CalculateHeight(Node * node){
        if(node==nullptr){
            return 0;
        }
        std::queue<Node*>Q;
        Q.push(node);
        int height =0;
        while(!Q.empty()){
            int levelSize = Q.size();

            for(auto i =0;i<levelSize;i++){
                Node * current_node = Q.front();
                Q.pop();

                if(current_node->left!=nullptr){
                    Q.push(current_node->left);
                }

                if(current_node->right!=nullptr){
                    Q.push(current_node->right);
                }

            }
        height++;
        }
        return height;

    }

    int BalanceFactor(Node * node){
        return CalculateHeight(node->left)-CalculateHeight(node->right);    
    }

    void CheckTree(Node * &current_node,int key){
        int balance_factor;
        balance_factor = BalanceFactor(current_node);
        if(balance_factor<-1 && key>current_node->right->key){
            current_node = RotateLeft(current_node);
        }
        else if(balance_factor<-1 && key<current_node->right->key){
            current_node->right = RotateRight(current_node->right);
            current_node = RotateLeft(current_node);

        }else if(balance_factor>1 && key> current_node->left->key){
            current_node->left = RotateRight(current_node->left);
            current_node = RotateRight(current_node);
        }
        else if(balance_factor>1 && key<current_node->left->key){
            current_node = RotateRight(current_node);
        }

    }

    void AddNode(int key){
        Node * new_node = new Node(key);

        if(root_node == nullptr){
            root_node = new_node;
        }
        Node * current_node = root_node;
    
        while(true){
            if(key<root_node->key){
                if(current_node->left==nullptr){
                    current_node->left->key = key;
                    return;
                }
                CheckTree(current_node,key);
                current_node = current_node->left;
                CheckTree(current_node,key);
            }
            else if(key>root_node->key){
                if(current_node->right==nullptr){
                    current_node->right->key = key;
                    return;
                }
                CheckTree(current_node,key);
                current_node= current_node->right;
                CheckTree(current_node,key);
            }
            else {
                // If the key already exists in the tree, you can decide
                // to handle it in a specific way or ignore the duplicate.
                // Here, we choose to ignore duplicates.
                std::cout<<"Duplicates not allowed!"<<std::endl;
                delete new_node;
                return;
            }
            
         
        }

    }

    public:

    AVLTree(){
        root_node = nullptr;
    }

    void Insert(int key){
        AddNode(key);
    }

};