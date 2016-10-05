#include "BinarySearchTree.hpp"
//#include <string>

int main()
{
    BinarySearchTree<int> tree{ 8,10,3,14,6,1,7,13,4 };
    //BinarySearchTree<int> tree2{ 8,10,3,14,6,1,7,13,4 };
    //if (tree == tree2) std::cout << "TRUE" << std::endl;
    //else std::cout << "FALSE" << std::endl;
    //tree.insert(5);
    //if (tree == tree2) std::cout << "TRUE" << std::endl;
    //else std::cout << "FALSE" << std::endl;
    //std::cin >> tree;
    //BinarySearchTree<std::string> tree{ "ab","cd","ef" };
    //std::ofstream out("Tree.txt");
    //out << tree;
    //out.close();
    std::cout << tree << std::endl;
    BinarySearchTree<int> tree2(tree);
    std::cout << tree2 << std::endl;
    tree2.insert(5);
    tree = tree2;
    std::cout << tree << std::endl;
    //BinarySearchTree<int>* tree = new BinarySearchTree<int>();
    //std::ifstream in("Tree.txt");
    //in >> *tree;
    //in.close();
    //std::cout << *tree << std::endl;
    //delete tree;
    return 0;
}
