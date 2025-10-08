////////////////////////////////////////////////////////////////////////////////////////////////////////
// Q2. Write a program to construct binary search tree on given pre-order traversal of the tree.
// After constructing the binary search tree, print the nodes level wise top to down and left to
// right.
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode *newNode(int val)
{
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a node into a binary search tree
struct TreeNode *insert(struct TreeNode *root, int val)
{
  if (root == NULL)
    return newNode(val);
  if (val < root->val)
    root->left = insert(root->left, val);
  else if (val > root->val)
    root->right = insert(root->right, val);
  return root;
}

// Function to print nodes level-wise
void printLevelOrder(struct TreeNode *root)
{
  if (root == NULL)
    return;

  // Create an array to store nodes at each level
  struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 1000);
  int front = 0, rear = 0;
  queue[rear++] = root;

  while (front < rear)
  {
    int levelSize = rear - front;
    for (int i = 0; i < levelSize; i++)
    {
      struct TreeNode *current = queue[front++];
      printf("%d ", current->val);
      if (current->left)
        queue[rear++] = current->left;
      if (current->right)
        queue[rear++] = current->right;
    }
    printf("\n");
  }
  free(queue);
}

// Function to construct a binary search tree from pre-order traversal
struct TreeNode *constructBST(int pre[], int size)
{
  if (size == 0)
    return NULL;
  struct TreeNode *root = NULL;
  for (int i = 0; i < size; i++)
    root = insert(root, pre[i]);
  return root;
}

// Example usage
int main()
{
  printf("Piyush Yadav 23/CS/301\n");
  printf("CS104-Assignment2 Q2\n");
  int preOrder[] = {10, 5, 1, 7, 40, 50};
  int size = sizeof(preOrder) / sizeof(preOrder[0]);

  // Construct the binary search tree
  struct TreeNode *root = constructBST(preOrder, size);

  // Print nodes level-wise
  printf("Nodes level-wise from top to down and left to right:\n");
  printLevelOrder(root);

  return 0;
}
