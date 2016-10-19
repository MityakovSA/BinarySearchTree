#include "catch.hpp"
#include "BinarySearchTree.hpp"

SCENARIO("If element exist in tree, find() must return ptr on it")
{
   GIVEN("Tree with existing element")
   {
      BinarySearchTree<int> tree { 8,10,3};
      WHEN("Searhing element")
      {
         THEN("Method must return ptr on 10")
         {
            REQUIRE(*tree.find(10) == 10);
         }
      }
   }
}

SCENARIO("If element does not exist in tree, find() must throw exception")
{
   GIVEN("Tree with non-existing element")
   {
      BinarySearchTree<int> tree { 8,10,3 };
      WHEN("Searhing element")
      {
         THEN("Method must throw exception")
         {
            REQUIRE_THROWS_AS(tree.find(7), BinarySearchTree<int>::BST_exception);
         }
      }
   }
}

SCENARIO("find() must support const and non-const objects")
{
    GIVEN("const and non-const tree")
    {
        const BinarySearchTree<int> tree1 { 8,10,3 };
        BinarySearchTree<int> tree2 { 7,9,2 };
        WHEN("Searhing element")
        {
            THEN("Method must find elements")
            {
               REQUIRE(tree1.find(10));
               REQUIRE(tree2.find(9));
            }
        }
    }
}

SCENARIO("If tree is empty, find() must throw exception")
{
    GIVEN("Empty tree")
    {
        BinarySearchTree<int> tree;
        WHEN("Searhing element")
        {
            THEN("Method must throw exception")
            {
                REQUIRE_THROWS_AS(tree.find(7), BinarySearchTree<int>::BST_exception);
            }
        }
    }
}
