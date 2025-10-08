////////////////////////////////////////////////////////////////////////////////////////////////////////
// Q1. Write a program to check if one tree appears in another tree. Two trees match each other
// if either
// 1. Both trees are empty, or
// 2. both trees are non-empty and
// 1. both root nodes have the same value,
// 2. each root has the same number of children, and
// 3. the corresponding children in each root node match.

// The program accepts a source binary tree and a pattern binary tree, and returns the root of an
// occurrence of the pattern in the source, if it exists. The pattern tree may occur anywhere in the
// source tree.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Function to check if two trees match each other
bool isEqual(struct TreeNode *s, struct TreeNode *t)
{
  if (!s && !t)
    return true;
  if (!s || !t || s->val != t->val)
    return false;
  return isEqual(s->left, t->left) && isEqual(s->right, t->right);
}

// Function to check if one tree appears in another tree
bool isSubtree(struct TreeNode *s, struct TreeNode *t)
{
  if (!t)
    return true;
  if (!s)
    return false;
  return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}

// Example usage
int main()
{
  printf("Piyush Yadav 23/CS/301\n");
  printf("CS104-Assignment2 Q1\n");
  // Example trees
  struct TreeNode tree1 = {1, &(struct TreeNode){2, &(struct TreeNode){4, NULL, NULL}, &(struct TreeNode){5, NULL, NULL}}, &(struct TreeNode){3, NULL, NULL}};
  struct TreeNode tree2 = {2, &(struct TreeNode){4, NULL, NULL}, &(struct TreeNode){5, NULL, NULL}};

  // Check if tree2 appears in tree1 or vice versa
  if (isSubtree(&tree1, &tree2) || isSubtree(&tree2, &tree1))
    printf("One tree appears in another\n");
  else
    printf("No tree appears in another\n");

  return 0;
}
