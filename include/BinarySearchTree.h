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

        /*friend std::ostream& operator<<(std::ostream& out, const Node& node)
        {
            if (node.right_) out << *node.right_;
            out << node.value_ << ' ';
            if (node.left_) out << *node.left_;
            return out;
        }*/

        ~Node()
        {
            if (left_)
                delete left_;
            if (right_)
                delete right_;
        }
    };

    BinarySearchTree() : root_(nullptr), size_(0) {};

    BinarySearchTree(const std::initializer_list<T>& list) : BinarySearchTree()
    {
        for (auto& value : list)
            insert(value);
    };

    auto size() const noexcept -> size_t
    {
        return size_;
    };

    auto find(const T& value) const noexcept -> const T*
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

    auto insert(const T& value) noexcept -> bool
    {
        if (size_ == 0)
        {
            root_ = new Node(value);
            size_ = 1;
            return true;
        }
        Node* curNode = root_;
        Node* prevNode = nullptr;
        while (curNode)
        {
            prevNode = curNode;
            if (value == curNode->value_) return false;
            else if (value < curNode->value_) curNode = curNode->left_;
            else curNode = curNode->right_;
        }
        if (value < prevNode->value_) prevNode->left_ = new Node(value);
        else prevNode->right_ = new Node(value);
        size_++;
        return true;
    }

    bool osymmetric(std::ostream& out, Node* node) const
    {
        if (node)
        {
            osymmetric(out, node->right_);
            out << node->value_ << ' ';
            osymmetric(out, node->left_);
            return true;
        } else return false;
    }

    bool odirect(std::ofstream& out, Node* node) const
    {
        if (node)
        {
            out << node->value_ << ' ';
            odirect(out, node->left_);
            odirect(out, node->right_);
            return true;
        } else return false;
    }

    friend auto operator << (std::ostream& out, const BinarySearchTree<T>& tree) -> std::ostream&
    {
        tree.osymmetric(out, tree.root_);
        return out;
    }

    friend auto operator << (std::ofstream& out, const BinarySearchTree<T>& tree) -> std::ofstream&
    {
        tree.odirect(out, tree.root_);
        return out;
    }

    friend auto operator >> (std::istream& in, BinarySearchTree<T>& tree) -> std::istream&
    {
        T value;
        while (in >> value) tree.insert(value);
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
