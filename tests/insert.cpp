#include "catch.hpp"
#include "BinarySearchTree.hpp"

SCENARIO("If inserting element already exist in tree, method must return false")
{
   GIVEN("Tree with existing element")
   {
      BinarySearchTree<int> tree { 8,10,3};
      WHEN("Inserting")
      {
         THEN("Method must return false")
         {
            REQUIRE(tree.insert(10) == false);
         }
      }
   }
}

SCENARIO("If inserting element does not exist in tree, method must return true")
{
   GIVEN("Tree with non-existing element")
   {
      BinarySearchTree<int> tree { 8,10,3};
      WHEN("Inserting")
      {
         THEN("Method must return true")
         {
            REQUIRE(tree.insert(7));
         }
      }
   }
}

SCENARIO("If inserting element is lesser than root of the tree, it must be inserted left from root")
{
   GIVEN("Tree with bigger root and tree with inserted element")
   {
      BinarySearchTree<int> tree1 { 10 };
      BinarySearchTree<int> tree2 { 10, 8 };
      WHEN("Inserting")
      {
         tree1.insert(8)
         THEN("Element must be inserted left from root")
         {
            REQUIRE(tree1 == tree2);
         }
      }
   }
}

SCENARIO("If inserting element is bigger than root of the tree, it must be inserted right from root")
{
   GIVEN("Tree with lesser root and tree with inserted element")
   {
      BinarySearchTree<int> tree1 { 10 };
      BinarySearchTree<int> tree2 { 10, 12 };
      WHEN("Inserting")
      {
         tree1.insert(12)
         THEN("Element must be inserted right from root")
         {
            REQUIRE(tree1 == tree2);
         }
      }
   }
}

SCENARIO("If inserting element already exist in tree, method must not change size of tree")
{
   GIVEN("Tree with existing element")
   {
      BinarySearchTree<int> tree { 8,10,3};
      WHEN("Inserting")
      {
         tree.insert(10)
         THEN("Method must not change size of tree")
         {
            REQUIRE(tree.size() == 3);
         }
      }
   }
}

SCENARIO("If inserting element does not exist in tree, method must increment size of tree")
{
   GIVEN("Tree with non-existing element")
   {
      BinarySearchTree<int> tree { 8,10,3};
      WHEN("Inserting")
      {
         tree.insert(7)
         THEN("Method must increment size of tree")
         {
            REQUIRE(tree.size() == 4);
         }
      }
   }
}
