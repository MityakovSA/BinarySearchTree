#include "Catch.h"
#include "BinarySearchTree.h"

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
