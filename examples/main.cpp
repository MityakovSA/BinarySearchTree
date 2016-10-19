#include "BinarySearchTree.hpp"

int main()
{
    try
    {
        //BinarySearchTree<int> tree;
        BinarySearchTree<int> tree( { 8,3,1,6,4,7,15,11,9,10,12,16 } );
        //tree.find(2);
        //tree.insert(15);
        tree.remove(2);
        std::cout << tree << std::endl;
    }
    catch (BinarySearchTree<int>::BST_exception& error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}
