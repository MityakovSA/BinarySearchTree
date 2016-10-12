#include <iostream>
#include <cstddef>
#include <fstream>
#include <memory>


template <typename T>
class BinarySearchTree
{
public:
    struct Node
    {
        T value_;
        std::shared_ptr<Node> left_;
        std::shared_ptr<Node> right_;

        Node(T value) : value_(value), left_(nullptr), right_(nullptr) {}

        std::shared_ptr<Node> copy()
        {
            std::shared_ptr<Node> cNode(new Node(value_));
            if (left_) cNode->left_ = left_->copy();
            if (right_) cNode->right_ = right_->copy();
            return cNode;
        }

        ~Node()
        {
            if (left_)
                left_ = nullptr;
            if (right_)
                right_ = nullptr;
        }
    };

    BinarySearchTree() : root_(nullptr), size_(0) {};

    BinarySearchTree(const std::initializer_list<T>& list) : BinarySearchTree()
    {
        for (auto& value : list)
            insert(value);
    };

    BinarySearchTree(const BinarySearchTree& tree)
    {
        size_ = tree.size_;
        root_ = tree.root_->copy();
    }

    BinarySearchTree(BinarySearchTree&& tree)
    {
        root_ = tree.root_;
        tree.root_ = nullptr;
        size_ = tree.size_;
        tree.size_ = 0;
    }

    auto size() const noexcept -> size_t
    {
        return size_;
    };

    auto find(const T& value) const noexcept -> const T*
    {
        if (size_ == 0) return nullptr;
        std::shared_ptr<Node> curNode(root_);
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
            root_.reset(new Node(value));
            size_ = 1;
            return true;
        }
        std::shared_ptr<Node> curNode(root_);
        std::shared_ptr<Node> prevNode(nullptr);
        while (curNode)
        {
            prevNode = curNode;
            if (value == curNode->value_) return false;
            else if (value < curNode->value_) curNode = curNode->left_;
            else curNode = curNode->right_;
        }
        if (value < prevNode->value_) prevNode->left_.reset(new Node(value));
        else prevNode->right_.reset(new Node(value));
        size_++;
        return true;
    }

    auto remove(const T& value) -> bool
    {
        if (size_ == 0) return false;
        else if (remove_n(value, root_))
        {
            size_--;
            return true;
        };
    }

    auto remove_n(const T& value, std::shared_ptr<Node>& curNode) -> bool
    {
        if (curNode == nullptr) return false;
        if (value > curNode->value_) return remove_n(value, curNode->right_);
        else if (value < curNode->value_)  return remove_n(value, curNode->left_);
        else
        {
            if ((curNode->left_ == nullptr) && (curNode->right_ == nullptr)) curNode = nullptr;
            else if (curNode->left_ == nullptr) curNode = curNode->right_;
            else if (curNode->right_ == nullptr) curNode = curNode->left_;
            else
            {
                auto parent = curNode;
                auto min = curNode->right_;
                bool check = true;
                while (min->left_)
                {
                    if (check) check = false;
                    parent = min;
                    min = min->left_;
                }
                curNode->value_ = min->value_;
                if (min->right_) parent->left_ = min->right_;
                else if (check) parent->right_ = nullptr;
                else parent->left_ = nullptr;
            }
            return true;
        }
    }

    bool osymmetric(std::ostream& out, std::shared_ptr<Node> node) const noexcept
    {
        if (node)
        {
            osymmetric(out, node->right_);
            out << node->value_ << ' ';
            osymmetric(out, node->left_);
            return true;
        } else return false;
    }

    bool odirect(std::ofstream& out, std::shared_ptr<Node> node) const noexcept
    {
        if (node)
        {
            out << node->value_ << ' ';
            odirect(out, node->left_);
            odirect(out, node->right_);
            return true;
        } else return false;
    }

    bool equal(std::shared_ptr<Node> fnode, std::shared_ptr<Node> snode) const noexcept
    {
        if (fnode)
        return snode && (fnode->value_ == snode->value_) &&
                         equal(fnode->left_, snode->left_) &&
                         equal(fnode->right_, snode->right_);
        else if (snode == nullptr) return true;
        else return false;
    }

    auto operator == (const BinarySearchTree& tree) const -> bool
    {
        if (this == &tree) return true;
        else if (size_ == tree.size_) return tree.equal(root_, tree.root_);
        else return false;
    }

    auto operator = (const BinarySearchTree& tree) -> BinarySearchTree&
    {
        if (this == &tree) return *this;
        else
        {
            root_ = nullptr;
            size_ = tree.size_;
            root_ = tree.root_->copy();
            return *this;
        }
    }

    auto operator = (BinarySearchTree&& tree) -> BinarySearchTree&
    {
        if (this == &tree) return *this;
        else
        {
            root_ = nullptr;
            size_ = tree.size_;
            tree.size_ = 0;
            root_ = tree.root_;
            tree.root_ = nullptr;
            return *this;
        }
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
        root_ = nullptr;
        size_ = 0;
    }

private:
    std::shared_ptr<Node> root_;
    size_t size_;
};
