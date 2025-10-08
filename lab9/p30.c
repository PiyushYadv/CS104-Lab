#include <stdio.h>
#include <stdlib.h>

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

void inOrderTraversal(struct TreeNode *root)
{
  if (root != NULL)
  {
    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
  }
}

int main()
{
  printf("Piyush Yadav - 23/CS/301\n");

  struct TreeNode *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  printf("In-order traversal: ");
  inOrderTraversal(root);
  printf("\n");

  return 0;
}
