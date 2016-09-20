#include "BinarySearchTree.h"
#include <string>

void main()
{
	BinarySearchTree<int> tree{ 8,10,3,14,6,1,7,13,4 };
	//BinarySearchTree<std::string> tree{ "ab","cd","ef" };
	//std::ofstream out("Tree.txt");
	//out << tree;
	//out.close();
	//BinarySearchTree<int>* tree = new BinarySearchTree<int>();
	//std::ifstream in("Tree.txt");
	//in >> *tree;
	//in.close();
	std::cout << tree << std::endl;
	//delete tree;
	system("pause");
}