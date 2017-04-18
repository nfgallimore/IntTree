// Assignment 8 Binary Search Tree driver
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tree.hpp"

int main() {
   srand(time(nullptr)); // randomize the random number generator

   Tree<int> intTree;
   int intVal;

   std::cout << "The values being placed in the tree are:\n";

   // generate a tree with values
   for (int i{1}; i <= 15; ++i)
   {
      intVal = rand() % 100;
      std::cout << intVal << ' ';
      intTree.insertNode(intVal);
   }

   std::cout << "\n\nEnter a value to search for: ";
   std::cin >> intVal;

   // create a pointer with the user value
   TreeNode<int>* ptr{intTree.binaryTreeSearch(intVal)};

   // a value is found
   if (ptr != nullptr) {
      std::cout << ptr->getData() << " was found\n";
   }
   else { // value not found
      std::cout << "Element was not found\n";
   }

   // // intTree1Depth
   // Tree<int> intTree1Depth;
   // for (int i{0}; i < 2; i++) {
   //    intTree1Depth.insertNode(i);
   // }
   // std::cout << intTree1Depth.getDepth() << std::endl; // should print 1

   // // intTree2Depth
   // Tree<int> intTree2Depth;
   // for (int i{0}; i < 5; i++) {
   //    intTree2Depth.insertNode(i);
   // }
   // std::cout << intTree2Depth.getDepth() << std::endl; // should print 2

   // // intTree2Depth
   // Tree<int> intTree2DepthNeg;
   // for (int i{5}; i > 0; i--) {
   //    intTree2DepthNeg.insertNode(i);
   // }
   // std::cout << intTree2DepthNeg.getDepth() << std::endl; // should print 2


   // // intTree0Depth
   // Tree<int> intTree0Depth;
   // std::cout << intTree0Depth.getDepth() << std::endl; // should print 0
   

   std::cout << intTree.getDepth() << std::endl << intTree.getActualDepth() << std::endl;
}
