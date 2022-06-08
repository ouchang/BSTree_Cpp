#include <string>
#include <iostream>
#include <sstream>
#include "TreeNode.h"
using namespace std;

/**
 * @brief Class responsible for creating Binary Tree
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes
 */
template<typename T, class Node>
class Tree {
    public: 
        TreeNode<T>* root; //Tree's root
    
        Tree();

        string search(T element);
        void insert(T element);
        void deleteNode(T element);
        void draw();

    private:
        bool searchTree(T element, TreeNode<T>* currNode);
        TreeNode<T>* insertTree(T element, TreeNode<T>* root);
        TreeNode<T>* deleteInTree(T element, TreeNode<T>* root);
        TreeNode<T>* findSuccessor(TreeNode<T>* root);
        TreeNode<T>* findPredecessor(TreeNode<T>* root);
        void inOrder(TreeNode<T>* root);
        stringstream drawing(TreeNode<T>* root);
};

/**
 * @brief Method which starts process of searching for a given node
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes
 * @param element node's value we are searching for
 * @return string - output information about the result of searching process
 */
template<class T, class Node>
string Tree<T, Node>::search(T element) {
    bool found_element = searchTree(element, this->root);

    if(found_element)
        return ("We found element inside the tree!");
    else 
        return ("Element is not inside the tree!");
}

template<class T, class Node>
Tree<T, Node>::Tree() {
    this->root = NULL;
}

/**
 * @brief Method responsible for starting the process of inserting new node into the binary tree
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes
 * @param element value of the new node
 */
template<class T, class Node>
void Tree<T, Node>::insert(T element) {
    root = insertTree(element, this->root);
}

/**
 * @brief Method responsible for starting the process of deleting a given node in binary tree
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes
 * @param element value of the node we are deleting
 */
template<class T, class Node>
void Tree<T, Node>::deleteNode(T element) {
    root = deleteInTree(element, this->root);
}

/**
 * @brief Method responsible for starting the process of drawing the binary tree
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes
 */
template<class T, class Node>
void Tree<T, Node>::draw() {
    string output = drawing(this->root).str();
    cout << output << endl;
}

/**
 * @brief Method which searches for a given node in binary tree
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes
 * @param element value of the node we are searching for
 * @param currNode node we are currently analyzing during the method 
 * @return true - User's node is inside the binary tree
 * @return false - User's node is not inside the binary tree
 */
template<class T, class Node>
bool Tree<T, Node>::searchTree(T element, TreeNode<T>* currNode) {
    if(currNode == NULL)
        return false;
    
    if(element == currNode->val)
        return true;
    
    if(element < currNode->val)
        return searchTree(element, currNode->left);
    else
        return searchTree(element, currNode->right);
}

/**
 * @brief Method which inserts new node given by a user
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes
 * @param element value of the new node
 * @param root node we are currently analyzing during the method 
 * @return TreeNode<T>* updated node after the insertion
 */
template<class T, class Node> 
TreeNode<T>* Tree<T, Node>::insertTree(T element, TreeNode<T>* root) {
    if(root == NULL) {
        root = new TreeNode<T>(element);
        return root;
    }

    if(element < root->val) {
        root->left = insertTree(element, root->left);
    } else {
        root->right = insertTree(element, root->right);
    }

    return root;
}

/**
 * @brief Method which deletes a given node in binary tree
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes
 * @param element value of node we are deleting
 * @param root node we are currently analyzing during the method 
 * @return TreeNode<T>* updated node after the deletion
 */
template<class T, class Node>
TreeNode<T>* Tree<T, Node>::deleteInTree(T element, TreeNode<T>* root) {
    if(root == NULL)
        return root;

    if(element < root->val) {
        root->left = deleteInTree(element, root->left);
    } else if(element > root->val) {
        root->right = deleteInTree(element, root->right);
    } else {
        //element == root.val

        if(root->left == NULL && root->right == NULL) {
            //Node without children
            delete root;
            return NULL;
        } else if(root->right != NULL) {
            //Node has right child -> we are looking for the smallest number bigger than deleting node
            TreeNode<T>* successor = findSuccessor(root);
            root->val = successor->val;
            root->right = deleteInTree(root->val, root->right);
        } else {
            //We are looking for the biggest number smaller than the deleting node
            TreeNode<T>* predecessor = findPredecessor(root);
            root->val = predecessor->val;
            root->left = deleteInTree(root->val, root->left);
        }
    }

    return root;
}

/**
 * @brief Method which search for the successor (the smallest value still bigger than the root's value)
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes 
 * @param root node we are currently analyzing during the method 
 * @return TreeNode<T>* successor
 */
template<class T, class Node>
TreeNode<T>* Tree<T, Node>::findSuccessor(TreeNode<T>* root) {
    root = root->right;
    while(root->left != NULL) {
        root = root->left;
    }

    return root;
}

/**
 * @brief Method which search for the predecessor (the biggest value still smaller than the root's value)
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes 
 * @param root node we are currently analyzing during the method 
 * @return TreeNode<T>* predecessor 
 */
template<class T, class Node>
TreeNode<T>* Tree<T, Node>::findPredecessor(TreeNode<T>* root) {
    root = root->left;
    while(root->right != NULL) {
        root = root->right;
    }

    return root;
}

/**
 * @brief Method which prints tree's nodes lexicographically
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes 
 * @param root node we are currently analyzing during the method 
 */
template<class T, class Node>
void Tree<T, Node>::inOrder(TreeNode<T>* root) {
    if(root != NULL) {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}

/**
 * @brief Method which saves nodes' values in stringstream
 * 
 * @tparam T - type used in node's value
 * @tparam Node - type of class used in binary tree's nodes 
 * @param root node we are currently analyzing during the method 
 * @return stringstream saved values of the checked nodes 
 */
template<class T, class Node>
stringstream Tree<T, Node>::drawing(TreeNode<T>* root) {
    stringstream ss;
    if(root != NULL) {
        ss << "(" << root->val << "):(" << drawing(root->left).str() << "):(" << drawing(root->right).str() << ")";
        return ss;
    }
    return ss;
}
