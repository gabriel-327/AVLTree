# Gator AVL Project

## Description
The Gator AVL Project is a C++ application that implements an AVL (Adelson-Velsky and Landis) tree to manage University of Florida student accounts by their GatorIDs. AVL trees are self-balancing binary search trees, which help optimize search efficiency by maintaining a balanced structure. 

## Features
- **Self-Balancing AVL Tree**: Automatically adjusts to maintain balance, improving efficiency for search, insertion, and deletion operations.
- **Student Record Management**: Allows adding, removing, and searching of student accounts based on GatorID and name.
- **Traversals**: Supports inorder, preorder, and postorder traversals of student names.
- **Tree Analysis**: Can determine and print the number of levels in the tree.
- **Deletion**: Enables removal of student records by ID or by position in an inorder traversal.

## Commands
The following commands are supported in the Gator AVL Project:

- **insert "NAME" ID**
  - O(log n) where n is the number of nodes in the tree.
  - Inserts a student with the specified name and unique GatorID into the tree.
  - Automatically rebalances the tree if necessary.
  - Outputs **successful** if the insertion is completed; **unsuccessful** otherwise.

- **remove ID**
  - O(log n) where n is the number of nodes in the tree.
  - Removes the student with the specified GatorID.
  - Outputs **successful** if the deletion is completed; **unsuccessful** otherwise.

- **search ID**
  - O(log n) where n is the number of nodes in the tree.
  - Searches for a student by their GatorID.
  - Outputs the student’s name if found; otherwise, outputs **unsuccessful**.

- **search "NAME"**
  -  O(n) where n is the number of nodes.
  - Searches for a student by name.
  - Outputs the associated GatorID(s). If multiple students share the same name, each ID is listed on a new line in preorder traversal order. Outputs **unsuccessful** if no match is found.

- **printInorder**
  - O(1) recursive calling.
  - Prints a comma-separated list of student names in inorder traversal.

- **printPreorder**
  - O(1) recursive calling.
  - Prints a comma-separated list of student names in preorder traversal.

- **printPostorder**
  - O(1) recursive calling.
  - Prints a comma-separated list of student names in postorder traversal.

- **printLevelCount**
  - O(1) recall height value.
  - Prints the number of levels in the tree. Outputs **0** if the tree is empty.

- **removeInorder N**
  - O(n) where n is the number of nodes.
  - Removes the student at position **N** in an inorder traversal.
  - Outputs **successful** if completed; **unsuccessful** if the position **N** does not exist in the tree.
