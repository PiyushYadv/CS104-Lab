#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *createTree(int data)
{
  TreeNode *treeNode = (TreeNode *)malloc(sizeof(TreeNode));
  treeNode->data = data;
  treeNode->left = NULL;
  treeNode->right = NULL;
  return treeNode;
}

void preOrderTraversal(TreeNode *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

void postOrderTraversal(TreeNode *root)
{
  if (root != NULL)
  {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
  }
}

void inOrderTraversal(TreeNode *root)
{
  if (root != NULL)
  {
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
  }
}

bool isBSTUtil(TreeNode *root, int min, int max)
{
  if (root == NULL)
    return true;

  // Check if current node's value is within the valid range
  if (root->data < min || root->data > max)
    return false;

  // Recursively check left and right subtrees
  return isBSTUtil(root->left, min, root->data - 1) &&
         isBSTUtil(root->right, root->data + 1, max);
}

int binaryRecurSearch(TreeNode *root, int data)
{
  if (root == NULL)
    return 0;
  if (root->data == data)
    return 1;
  if (root->data > data)
    return binaryRecurSearch(root->left, data);
  else
    return binaryRecurSearch(root->right, data);
}

int binaryIterSearch(TreeNode *root, int data)
{
  while (root != NULL)
  {
    if (root->data == data)
      return 1;
    else if (root->data > data)
      root = root->left;
    else
      root = root->right;
  }
  return 0;
}

TreeNode *insert(TreeNode *node, int data)
{
  if (node == NULL)
    return createTree(data);

  // Otherwise, recur down the tree
  if (data < node->data)
    node->left = insert(node->left, data);
  else if (data > node->data)
    node->right = insert(node->right, data);

  // return the (unchanged) node pointer
  return node;
}

TreeNode *minValueNode(TreeNode *root)
{
  TreeNode *current = root;

  // Loop down to find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

TreeNode *deleteNode(TreeNode *root, int data)
{
  // Base case: if the tree is empty
  if (root == NULL)
    return root;

  // Otherwise, recur down the tree
  if (data < root->data)
    root->left = deleteNode(root->left, data);
  else if (data > root->data)
    root->right = deleteNode(root->right, data);

  // If the key to be deleted is the same as the root's key
  else
  {
    // Node with only one child or no child
    if (root->left == NULL)
    {
      TreeNode *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      TreeNode *temp = root->left;
      free(root);
      return temp;
    }

    // Node with two children: Get the inorder successor (smallest in the right subtree)
    TreeNode *temp = minValueNode(root->right);

    // Copy the inorder successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

// TreeNode *inOrderPredecessor(TreeNode *root)
// {
//   root = root->left;
//   while (root->right != NULL)
//   {
//     root = root->right;
//   }
//   return root;
// }

// TreeNode *deleteNode(TreeNode *root, int data)
// {
//   TreeNode *iPre;
//   if (root == NULL)
//     return NULL;

//   if (root->left == NULL && root->right == NULL && root->data == data)
//     free(root);

//   if (data < root->data)
//     root->left = deleteNode(root->left, data);
//   else if (data > root->data)
//     root->right = deleteNode(root->right, data);
//   else
//   {
//     iPre = inOrderPredecessor(root);
//     root->data = iPre->data;
//     root->left = deleteNode(root->left, iPre->data);
//   }
//   return root;
// }

int main()
{
  /*          4
             / \
            2  6
           /\  /\
          1 3 5 7
  */
  TreeNode *root = createTree(4);
  TreeNode *parent1 = createTree(2);
  TreeNode *leaf1 = createTree(1);
  TreeNode *leaf2 = createTree(3);
  TreeNode *parent2 = createTree(6);
  TreeNode *leaf3 = createTree(5);
  TreeNode *leaf4 = createTree(7);

  root->left = parent1;
  root->right = parent2;
  parent1->left = leaf1;
  parent1->right = leaf2;
  parent2->left = leaf3;
  parent2->right = leaf4;
  insert(root, 11);
  deleteNode(root, 4);

  preOrderTraversal(root);
  printf("\n");
  postOrderTraversal(root);
  printf("\n");
  inOrderTraversal(root);

  printf("\n%d", binaryIterSearch(root, 3));

  printf("\nYour boolean variable is: %s", isBSTUtil(root, INT_MIN, INT_MAX) ? "true" : "false");
  return 0;
}