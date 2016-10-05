#include "catch.hpp"
#include "BinarySearchTree.hpp"

SCENARIO("If element exist in tree, find() must return ptr on it")
{
   GIVEN("Tree with existing element")
   {
      BinarySearchTree<int> tree { 8,10,3};
      WHEN("Decide existance")
      {
         THEN("Method must return ptr on 10")
         {
            REQUIRE(*tree.find(10) == 10);
         }
      }
   }
}

SCENARIO("If element does not exist in tree, find() must return nullptr")
{
   GIVEN("Tree witn non-existing element")
   {
      BinarySearchTree<int> tree { 8,10,3 };
      WHEN("Decide existance")
      {
         THEN("Method must return nullptr")
         {
            REQUIRE(tree.find(7) == nullptr);
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
        WHEN("Decide existance")
        {
            THEN("Method must find elements")
            {
               REQUIRE(tree1.find(10));
               REQUIRE(tree2.find(9));
            }
        }
    }
}
