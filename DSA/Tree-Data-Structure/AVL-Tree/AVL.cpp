#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
  node *left;
  node *right;
  int item;
  int height;
};

class AVL
{
private:
  node *root;

protected:
  node *insertion(node *, int);
  node *deletion(node *, int);
  void inorderrec(node *);
  node *minValueNode(node *);

public:
  AVL();
  int getBalanceFactor(node *);
  int getHeight(node *);
  node *leftRotate(node *);
  node *rightRotate(node *);
  void insert(int);
  void updateAnscestorsHeights(node *, int);
  void inorder();
  void del(int);
};

AVL::AVL()
{
  root = NULL;
}
node* AVL::minValueNode(node *ptr)
{
  node *current = ptr;
  while (current->left != NULL)
    current = current->left;

  // Step 2: Return the node with minimum value
  return current;

}
void AVL::updateAnscestorsHeights(node*ptr,int data)
{
   // Step 1: Base case — if subtree is empty, return
  if (ptr == NULL)
    return;

  // Step 2: Update height of current node
  ptr->height = 1 + max(getHeight(ptr->left), getHeight(ptr->right));

  // Step 3: Recursively update ancestors depending on data position
  if (data < ptr->item)
    updateAnscestorsHeights(ptr->left, data);
  else if (data > ptr->item)
    updateAnscestorsHeights(ptr->right, data);

}
void AVL::inorderrec(node *ptr)
{
  if (ptr)
  {
    inorderrec(ptr->left);
    cout << ptr->item << " ";
    inorderrec(ptr->right);
  }
}
void AVL::inorder()
{
  inorderrec(root);
}
int AVL::getHeight(node *ptr)
{
  if (ptr == NULL)
    return 0;
  return ptr->heigth;
}
int AVL::getBalanceFactor(node *ptr)
{
  if (ptr == NULL)
    return 0;
  return getHeight(ptr->left) - getHeight(ptr->right);
}
node *AVL::rightRotate(node *A)
{
  node *B = A->left;
  node *RT = B->right;

  B->right = A;
  A->left = RT;

  A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
  B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
  return B;
}
node *AVL::leftRotate(node *A)
{
  node *B = A->right;
  node *LT = B->left;

  B->left = A;
  A->right = LT;

  A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
  B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
  return B;
}
node *AVL::insertion(node *ptr, int data)
{
  node *n;

  // Step 1: Base case — if current subtree is empty, create a new node
  if (ptr == NULL)
  {
    n = new node;
    n->left = NULL;
    n->right = NULL;
    n->item = data;
    n->height = 1; // new leaf node has height 1
    return n;
  }

  // Step 2: Recursive BST insertion
  if (data < ptr->item)
    ptr->left = insertion(ptr->left, data); // insert into left subtree
  else if (data > ptr->item)
    ptr->right = insertion(ptr->right, data); // insert into right subtree
  else
    return ptr; // duplicate keys not allowed, return unchanged node

  // Step 3: Update height of current node after insertion
  ptr->height = 1 + max(getHeight(ptr->left), getHeight(ptr->right));

  // Step 4: Calculate balance factor to check if node became unbalanced
  int balance = getBalanceFactor(ptr);

  // Step 5a: Left-Left case → perform Right Rotation
  if (balance > 1 && data < ptr->left->item)
    return rightRotate(ptr);

  // Step 5b: Right-Right case → perform Left Rotation
  if (balance < -1 && data > ptr->right->item)
    return leftRotate(ptr);

  // Step 5c: Left-Right case → perform Left Rotation on left child, then Right Rotation
  if (balance > 1 && data > ptr->left->item)
  {
    ptr->left = leftRotate(ptr->left);
    return rightRotate(ptr);
  }

  // Step 5d: Right-Left case → perform Right Rotation on right child, then Left Rotation
  if (balance < -1 && data < ptr->right->item)
  {
    ptr->right = rightRotate(ptr->right);
    return leftRotate(ptr);
  }

  // Step 6: If balanced, just return current node
  return ptr;
}

void AVL::insert(int data)
{
  // Step 7: Call recursive insertion starting from root
  root = insertion(root, data);
}
node* AVL::deletion(node* ptr, int data)
{
  // Step 1: Base case — if subtree is empty, return
  if (ptr == NULL)
    return ptr;

  // Step 2: Standard BST deletion
  if (data < ptr->item)
    ptr->left = deletion(ptr->left, data);   // go left
  else if (data > ptr->item)
    ptr->right = deletion(ptr->right, data); // go right
  else
  {
    // Node found
    if (ptr->left == NULL || ptr->right == NULL)
    {
      // Case 1: Node has one child or no child
      node *temp = ptr->left ? ptr->left : ptr->right;

      if (temp == NULL)
      {
        // No child case
        temp = ptr;
        ptr = NULL;
      }
      else
      {
        // One child case — copy child’s data into current node
        *ptr = *temp;
      }
      delete temp;
    }
    else
    {
      // Case 2: Node has two children
      node *temp = minValueNode(ptr->right); // find inorder successor

      // Copy inorder successor’s value to current node
      ptr->item = temp->item;

      // Delete inorder successor
      ptr->right = deletion(ptr->right, temp->item);
    }
  }

  // Step 3: If tree had only one node, return
  if (ptr == NULL)
    return ptr;

  // Step 4: Update height of current node
  ptr->height = 1 + max(getHeight(ptr->left), getHeight(ptr->right));

  // Step 5: Get balance factor
  int balance = getBalanceFactor(ptr);

  // Step 6: Balance the tree if needed

  // Left-Left case
  if (balance > 1 && getBalanceFactor(ptr->left) >= 0)
    return rightRotate(ptr);

  // Left-Right case
  if (balance > 1 && getBalanceFactor(ptr->left) < 0)
  {
    ptr->left = leftRotate(ptr->left);
    return rightRotate(ptr);
  }

  // Right-Right case
  if (balance < -1 && getBalanceFactor(ptr->right) <= 0)
    return leftRotate(ptr);

  // Right-Left case
  if (balance < -1 && getBalanceFactor(ptr->right) > 0)
  {
    ptr->right = rightRotate(ptr->right);
    return leftRotate(ptr);
  }

  // Step 7: Return balanced node
  return ptr;
}
void AVL::del(int data)
{
  root=deletion(root,data);
}