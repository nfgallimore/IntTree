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

      return determineDepth(rootPtr, &totalDepth, &currentDepth);
      //return totalDepth;
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
   // inspired by http://www.cs.kent.edu/~durand/CS2/Notes/10_Binary_Trees/ds_treesC.html
   int determineDepth(TreeNode<NODETYPE>* root, int* totalDepth, int* currentDepth) const {
      if (root == nullptr) {
         return -1;
      }
      else {
         int depthLeft = determineDepth(root->leftPtr, totalDepth, currentDepth);
         int depthRight = determineDepth(root->rightPtr, totalDepth, currentDepth);
         int depthVal = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
         return depthVal;
      }
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
