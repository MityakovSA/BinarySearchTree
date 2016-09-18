#include <iostream>
#include <cstddef>
#include <fstream>


template <typename T>
class BinarySearchTree
{
public:
	struct Node
	{
		T value_;
		Node* left_;
		Node* right_;

		Node(T value) : value_(value), left_(nullptr), right_(nullptr) {}

		friend std::ostream& operator<<(std::ostream& out, const Node& node)
		{
			out << node.value_ << ' ';
			if (node.left_) out << *node.left_;
			if (node.right_) out << *node.right_;
			return out;
		}

		~Node()
		{
			if (left_)
				delete left_;
			if (right_)
				delete right_;
		}
	};

	BinarySearchTree() : root_(nullptr), size_(0) {};

	BinarySearchTree(const std::initializer_list<T>& list) : root_(nullptr), size_(list.size())
	{
		for (auto& value : list)
			insert(value);
	};

	auto size() //noexcept -> size_t
	{
		return size_;
	};

	auto find(const T& value) //const noexcept -> const T*
	{
		if (size_ == 0) return nullptr;
		Node* curNode = root_;
		do
		{
			if (value == curNode->value_) return &curNode->value_;
			else if (value < curNode->value_) curNode = curNode->left_;
			else if (value > curNode->value_) curNode = curNode->right_;
		} while (curNode);
		return nullptr;
	}

	auto insert(const T& value) //noexept -> bool
	{
		if (size_ == 0)
		{
			root_ = new Node(value);
			size_ = 1;
			return true;
		}
		else if (find(value)) return false;
		else
		{
			Node* curNode = root_;
			for (; ; )
			{
				if (value < curNode->value_)
					if (curNode->left_) curNode = curNode->left_;
					else
					{
						curNode->left_ = new Node(value);
						++size_;
						return true;
					}
				else if (value > curNode->value_)
					if (curNode->right_) curNode = curNode->right_;
					else
					{
						curNode->right_ = new Node(value);
						++size;
						return true;
					}
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const BinarySearchTree<T>& tree)
	{
		if (tree.size_) out << tree.size_ << ' ' << *tree.root_;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const BinarySearchTree<T>& tree)
	{
		int n = 0;
		in >> n;
		if (n == 0) return in;
		else for (int i = 0; i < n; i++)
		{
			T value;
			in >> value;
			tree.insert(value);
		}
		return in;
	}

	~BinarySearchTree()
	{
		delete root_;
		size_ = 0;
	}

private:
	Node* root_;
	size_t size_;
};