#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *newNode(int val)
{
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

bool isBSTUtil(struct TreeNode *root, int min, int max)
{
  if (root == NULL)
    return true;

  if (root->val < min || root->val > max)
    return false;

  return (isBSTUtil(root->left, min, root->val - 1) &&
          isBSTUtil(root->right, root->val + 1, max));
}

bool isBST(struct TreeNode *root)
{
  return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");
  struct TreeNode *root = newNode(4);
  root->left = newNode(2);
  root->right = newNode(5);
  root->left->left = newNode(1);
  root->left->right = newNode(3);

  if (isBST(root))
    printf("Given tree is a Binary Search Tree.\n");
  else
    printf("Given tree is not a Binary Search Tree.\n");

  return 0;
}
