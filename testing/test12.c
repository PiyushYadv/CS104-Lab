#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
// #include <limits.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
  int height;
} TreeNode;

TreeNode *createTree(int data)
{
  TreeNode *treeNode = (TreeNode *)malloc(sizeof(TreeNode));
  treeNode->data = data;
  treeNode->left = NULL;
  treeNode->right = NULL;
  treeNode->height = 1;
  return treeNode;
}

int getHeight(TreeNode *node)
{
  if (node == NULL)
    return 0;
  return node->height;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int getBalanceFactor(TreeNode *node)
{
  if (node == NULL)
    return 0;
  return getHeight(node->left) - getHeight(node->right);
}

TreeNode *leftRotate(TreeNode *x)
{
  TreeNode *y = x->right;
  TreeNode *T2 = y->left;

  y->left = x;
  x->right = T2;

  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

  return y;
}

TreeNode *rightRotate(TreeNode *y)
{
  TreeNode *x = y->left;
  TreeNode *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

  return x;
}

TreeNode *insert(TreeNode *root, int data)
{
  if (root == NULL)
    return createTree(data);

  if (root->data > data)
  {
    root->left = insert(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
  }
  root->height = 1 + max(getHeight(root->left), getHeight(root->right));
  int bf = getBalanceFactor(root);

  // Left Left Case
  if (bf > 1 && data < root->left->data)
  {
    return rightRotate(root);
  }
  // Right Right Case
  if (bf < -1 && data > root->right->data)
  {
    return leftRotate(root);
  }
  // Left Right Case
  if (bf > 1 && data > root->left->data)
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  // Right Left Case
  if (bf < -1 && data < root->right->data)
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void preOrder(TreeNode *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main()
{
  TreeNode *root = NULL;
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 5);
  preOrder(root);
  return 0;
}