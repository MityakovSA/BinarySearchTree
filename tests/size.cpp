#include "catch.hpp"
#include "BinarySearchTree.hpp"

SCENARIO("Size of empty tree must be equal 0")
{
    GIVEN("Empty tree")
    {
        BinarySearchTree<int> tree;
        WHEN("Decide size")
        {
            THEN("Size must be equal 0")
            {
                REQUIRE(tree.size() == 0);
            }
        }
    }
}

SCENARIO("Size of not empty tree must not be equal 0")
{
    GIVEN("Not empty tree")
    {
        BinarySearchTree<int> tree { 8,10,3,14,6,1,7,13,4 };
        WHEN("Decide size")
        {
            THEN("Size must not be equal 0")
            {
                REQUIRE(tree.size() != 0);
            }
        }
    }
}

SCENARIO("Method must support const and non-const objects")
{
    GIVEN("const and non-const tree")
    {
        const BinarySearchTree<int> tree1 { 8,10,3 };
        BinarySearchTree<int> tree2 { 7,9,2 };
        WHEN("Decide size")
        {
            THEN("Size must be equal")
            {
                REQUIRE(tree1.size() == tree2.size());
            }
        }
    }
}
