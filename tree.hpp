/*
   COPYRIGHT (C) 2017 Nicholas Gallimore (nfg3) All rights reserved.
   CS assignment
   Author.  Nicholas Gallimore
            nfg3@zips.uakron.edu
   Version. 1.01 04.16.2017
   Purpose: This program implements a binary tree with search and depth finding functionality.
*/
#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include "Treenode.hpp"

// Tree class-template definition
template<typename NODETYPE> class Tree {
public:
   // insert node in Tree
   void insertNode(const NODETYPE& value) {
      insertNodeHelper(&rootPtr, value);
   }

   // begin preorder traversal of Tree
   void preOrderTraversal() const {
      preOrderHelper(rootPtr);
   }

   // begin inorder traversal of Tree
   void inOrderTraversal() const {
      inOrderHelper(rootPtr);
   }

   // begin postorder traversal of Tree
   void postOrderTraversal() const {
      postOrderHelper(rootPtr);
   }

   // get the depth of the tree
   int getDepth() const {
      int totalDepth{0};
      int currentDepth{0};

      determineDepth(rootPtr, totalDepth, currentDepth);
      return totalDepth;
   }
   int getActualDepth() const {
      int totalDepth{0};
      int currentDepth{0};
      return determineDepthInt(rootPtr, totalDepth, currentDepth);
   }

   // begin binary search
   TreeNode<NODETYPE>* binaryTreeSearch(int val) const {
      return binarySearchHelper(rootPtr, val);
   }

private:
   TreeNode<NODETYPE>* rootPtr{nullptr};

   // utility function called by insertNode; receives a pointer
   // to a pointer so that the function can modify pointer's value
   void insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
      // subtree is empty; create new TreeNode containing value
      if (*ptr == nullptr) {
         *ptr = new TreeNode<NODETYPE>(value);
      }
      else { // subtree is not empty
             // data to insert is less than data in current node
         if (value <= (*ptr)->data) {
            insertNodeHelper(&((*ptr)->leftPtr), value);
         }
         else {
            insertNodeHelper(&((*ptr)->rightPtr), value);
         }
      }
   }

   // utility function to perform preorder traversal of Tree
   void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         std::cout << ptr->data << ' '; // process node
         preOrderHelper(ptr->leftPtr); // traverse left subtree
         preOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform inorder traversal of Tree
   void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         inOrderHelper(ptr->leftPtr); // traverse left subtree
         std::cout << ptr->data << ' '; // process node
         inOrderHelper(ptr->rightPtr); // traverse right subtree
      }
   }

   // utility function to perform postorder traversal of Tree
   void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
      if (ptr != nullptr) {
         postOrderHelper(ptr->leftPtr); // traverse left subtree
         postOrderHelper(ptr->rightPtr); // traverse right subtree
         std::cout << ptr->data << ' '; // process node
      }
   }

   // calculate the depth of the tree
   void determineDepth(TreeNode<NODETYPE>* root, int &totalDepth, int &currentDepth) const {
      
      // negative 1 to cancel out extra increment
      if (root == nullptr) {
         currentDepth = -1;
         return;
      }

      // updats totalDepth value
      if (currentDepth > totalDepth) {
         totalDepth = currentDepth;
      }

      // actual increment for currentDepth
      currentDepth++;

      // stores value of currentDepth for right subtree
      int tmp = currentDepth; 
      
      // recursive call to increment currentDepth for finding left subtree depth if leftPtr is not null
      determineDepth(root->leftPtr, totalDepth, currentDepth);

      // restores currentDepth to appropriate value for right subtree
      currentDepth = tmp;

      // recursuive call to increment currentDepth for finding right subtree depth if rightPtr is not null
      determineDepth(root->rightPtr, totalDepth, currentDepth); 

   }

   // do a binary search on the Tree
   TreeNode<NODETYPE>* binarySearchHelper(TreeNode<NODETYPE>* root, int val) const {
      TreeNode<NODETYPE>* subTreeNodeAddress = root;
      while (true) {
         if (subTreeNodeAddress == nullptr) {
            return nullptr;
         }
         if (val == subTreeNodeAddress->data) {
            std::cout << "Comparing " << val << " to " << subTreeNodeAddress->data << "; search complete\n";
            return subTreeNodeAddress;
         }
         else {
            if (val < subTreeNodeAddress->data) {
               // search the left sub tree
               std::cout << "Comparing " << val << " to " << subTreeNodeAddress->data << "; smaller, walk left\n";
               subTreeNodeAddress = subTreeNodeAddress->leftPtr;
            }
            else {
               // search the right sub tree
               std::cout << "Comparing " << val << " to " << subTreeNodeAddress->data << "; larger, walk right\n";
               subTreeNodeAddress = subTreeNodeAddress->rightPtr;
            }
         }
      }
   }

};

#endif // TREE_HPP
