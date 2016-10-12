#include "catch.hpp"
#include "BinarySearchTree.hpp"

SCENARIO("If removing element does not exist in tree, remove() must return false")
{
    GIVEN("Tree with non-existing element")
    {
        BinarySearchTree<int> tree { 8,3,1,6,4,7,15,11,9,10,12,16 };
        WHEN("Removing")
        {
            THEN("Method must return false")
            {
                REQUIRE(tree.remove(2) == false);
            }
        }
    }
}

SCENARIO("If removing element exist in tree, remove() must return true")
{
    GIVEN("Tree with existing element")
    {
        BinarySearchTree<int> tree { 8,3,1,6,4,7,15,11,9,10,12,16 };
        WHEN("Removing")
        {
            THEN("Method must return true")
            {
                REQUIRE(tree.remove(11) == true);
            }
        }
    }
}

SCENARIO("If removing element does not exist in tree, remove() must not change size of tree")
{
    GIVEN("Tree with non-existing element")
    {
        BinarySearchTree<int> tree { 8,3,1,6,4,7,15,11,9,10,12,16 };
        WHEN("Removing")
        {
            tree.remove(2);
            THEN("Method must not change size of tree")
            {
                REQUIRE(tree.size() == 12);
            }
        }
    }
}

SCENARIO("If removing element exist in tree, remove() must decrement size of tree")
{
    GIVEN("Tree with existing element")
    {
        BinarySearchTree<int> tree { 8,3,1,6,4,7,15,11,9,10,12,16 };
        WHEN("Removing")
        {
            tree.remove(11);
            THEN("Method must decrement size of tree")
            {
                REQUIRE(tree.size() == 11);

            }
        }
    }
}

SCENARIO("If removing element does not exist in tree, remove() must not change its structure")
{
    GIVEN("Tree and with non-existing element and its copy")
    {
        BinarySearchTree<int> tree1 { 8,3,1,6,4,7,15,11,9,10,12,16 };
        auto tree2 = tree1;
        WHEN("Removing")
        {
            tree1.remove(2);
            THEN("Trees must be equivalent")
            {
                REQUIRE(tree1 == tree2);
            }
        }
    }
}

SCENARIO("If removing element exist in tree, remove() must remove it and change tree's structure")
{
    GIVEN("Tree with existing element and result tree")
    {
        BinarySearchTree<int> tree1 { 8,3,1,6,4,7,15,11,9,10,12,16 };
        BinarySearchTree<int> tree2 { 8,3,1,6,4,15,11,9,10,12,16 };
        WHEN("Removing node without children")
        {
            tree1.remove(7);
            THEN("Trees must be equivalent")
            {
                REQUIRE(tree1 == tree2);
            }
        }
    }
}