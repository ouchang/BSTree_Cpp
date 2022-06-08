#include <iostream>
#include <string>

/**
 * @brief Class responsible for creating tree's node
 * 
 * @tparam T type used in node's value
 */
template<class T>
class TreeNode {
    public:
        T val; //Node's value
        TreeNode<T>* left; //Node's left child
        TreeNode<T>* right; //Node's right child

    TreeNode(); 
    TreeNode(T element);
};

/**
 * @brief Construct a new Tree Node< T>:: Tree Node object
 * 
 * @tparam T type used in node's value
 */
template<class T>
TreeNode<T>::TreeNode() {
    val = NULL;
    left = NULL;
    right = NULL;
};

/**
 * @brief Construct a new Tree Node< T>:: Tree Node object
 * 
 * @tparam T type used in node's value
 * @param element new node's value
 */
template<class T>
TreeNode<T>::TreeNode(T element) {
    val = element;
    left = NULL;
    right = NULL;
};
