#include<iostream>
#include<stack>

int Algorithim(int i){
    return 2*i+1;
}

class Node{
    public:
    int key;
    Node * left;
    Node * right;

    Node(int key){
        this->key =key;
        left = right =nullptr;
    }

};



class BinarySearchTree {
private:
    Node* root_node;

public:
    BinarySearchTree() : root_node(nullptr) {}

    void Insert(int key) {
        Node* newNode = new Node(key);

        if (root_node == nullptr) {
            root_node = newNode;
            return;
        }

        Node* current = root_node;
        while (true) {
            if (key < current->key) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            } else if (key > current->key) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            } else {
                // If the key already exists in the tree, you can decide
                // to handle it in a specific way or ignore the duplicate.
                // Here, we choose to ignore duplicates.
                delete newNode;
                return;
            }
        }
    }

    void Search(int key) {
        Node* current = root_node;
        int count = 0;

        while (current != nullptr) {
            count++;
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            } else {
                std::cout << "Element found at: " << count << " node in the BST." << std::endl;
                return;
            }
        }

        std::cout << "Element not found in the BST." << std::endl;
    }

    void Inorder() {
        if (root_node == nullptr) {
            return;
        }

        std::stack<Node*> nodeStack;
        Node* current = root_node;

        while (!nodeStack.empty() || current != nullptr) {
            while (current != nullptr) {
                nodeStack.push(current);
                current = current->left;
            }

            current = nodeStack.top();
            nodeStack.pop();

            std::cout << current->key << ",";

            current = current->right;
        }
    }
};


void AddElementsToBST(BinarySearchTree &object,int NumberOfElements){
    for(auto i =0;i<NumberOfElements;i++){
        object.Insert(Algorithim(i));
    }
}
