#include <iostream>
#include <stdio.h>
using namespace std;
#define NOTHING_TO_DELETE 1
struct node
{
  node *left;
  node *right;
  int item;
};

class BST
{
private:
  node *root;
  void recPreorder(node *);
  void recPostorder(node *);
  void recInorder(node *);
  void inordercopy(BST&,node*);

public:
  BST();
  BST(BST &);
  BST &operator=(BST &);
  bool isEmpty();
  void insert(int);
  void preorder();
  void inorder();
  void postorder();
  node *search(int);
  void del(int);
  ~BST();
};
BST::BST()
{
  root = NULL;
}
void BST::inordercopy(BST &b,node*ptr)
{
  if (ptr)
  {
    inordercopy(b,ptr->left);
    b.insert(ptr->item);
    inordercopy(b,ptr->right);
  }
}
BST::BST(BST &bst)
{
  root=NULL;
  if(bst.root)
  {
    bst.inordercopy(*this,bst.root);
  }
}
BST &BST::operator=(BST &bst)
{
  while(root)
  {
    del(root->item);
  }
    bst.inordercopy(*this,bst.root);
  return *this;
}
bool BST::isEmpty()
{
  return root == NULL;
}
void BST::insert(int data)
{
  node *ptr;
  if (root == NULL)
  {
    node *n = new node;
    n->left = NULL;
    n->item = data;
    n->right = NULL;
    root = n;
  }
  else
  {
    bool flag = true;
    ptr = root;
    while (flag)
    {
      if (n->item == ptr->item)
        break;
      if (n->item < ptr->item) // left subtree
      {
        if (ptr->left == NULL)
        {
          node *n = new node;
          n->left = NULL;
          n->item = data;
          n->right = NULL;
          ptr->left = n;
          flag = false;
        }
        else
          ptr = ptr->left;
      }
      else // rigth subtree
      {
        if (ptr->right == NULL)
        {
          node *n = new node;
          n->left = NULL;
          n->item = data;
          n->right = NULL;
          ptr->right = n;
          flag = false;
        }
        else
          ptr = ptr->right;
      }
    }
  }
}
void BST::recPreorder(node *ptr)
{
  if (ptr)
  {
    cout << ptr->item << " ";
    recPreorder(ptr->left);
    recPreorder(ptr->right);
  }
}

void BST::preorder()
{
  recPreorder(root);
}

void BST::recPostorder(node *ptr)
{
  if (ptr)
  {
    recPostorder(ptr->left);
    recPostorder(ptr->right);
    cout << ptr->item << " ";
  }
}
void BST::postorder()
{
  recPostorder(root);
}
void BST::recInorder(node *ptr)
{
  if (ptr)
  {
    recInorder(ptr->left);
    cout << ptr->item << " ";
    recInorder(ptr->right);
  }
}
void BST::inorder()
{
  recInorder(root);
}

node *BST::search(int data)
{
  node *ptr = root;
  while (ptr)
  {
    if (ptr->item == data)
      return ptr;
    if (data < ptr->item)
    {
      ptr = ptr->left;
    }
    else
    {
      ptr = ptr->right;
    }
  }
  return NULL;
}
void BST::del(int data)
{
  node *ptr, *parptr;
  if (root == NULL)
  {
    throw NOTHING_TO_DELETE;
  }
  ptr = root;
  parptr = NULL;
  while (ptr)
  {
    if (ptr->item == data)
      break;
    if (ptr->left)
    {
      parptr = ptr;
      ptr = ptr->left;
    }
    else
    {
      parptr = ptr;
      ptr = ptr->right;
    }
  }
  if (ptr == NULL)
    throw NOTHING_TO_DELETE;
  if (parptr == NULL && ptr != NULL) // when it is root node
  {
    if (ptr->left == NULL && ptr->right == NULL) // no child
    {
      delete ptr;
      root = NULL;
    }
    else if (ptr->left && ptr->right) // two child
    {
      node *suc, *parsuc;
      suc = ptr->right;
      while (suc->left != NULL)
      {
        parsuc = suc;
        suc = suc->left;
      }
      ptr->item = suc->item;
      // delete suc
      if (suc == parsuc->left)
        parsuc->left = suc->right;
      else
        parsuc->right = suc->right;
      delete suc;
    }
    else // one child
    {
      if (ptr->left)
        root = ptr->left;
      else
        root = ptr->right;
      delete ptr;
    }
  }
  else // when it is not a root node
  {
    if (ptr->left == NULL && ptr->right == NULL) // no child
    {
      if (ptr == parptr->left)
      {
        parptr->left = NULL;
        delete ptr;
      }
      else
      {
        parptr->right = NULL;
        delete ptr;
      }
    }
    else if (ptr->left && ptr->right) // two child
    {
      node *suc, *parsuc;
      suc = ptr->right;
      while (suc->left != NULL)
      {
        parsuc = suc;
        suc = suc->left;
      }
      ptr->item = suc->item;
      // delete suc
      if (suc == parsuc->left)
        parsuc->left = suc->right;
      else
        parsuc->right = suc->right;
      delete suc;
    }
    else // one child
    {
      if (ptr == parptr->left)
      {
        if (ptr->left)
          parptr->left = ptr->left;
        else
          parptr->left = ptr->right;
        delete ptr;
      }
      else
      {
        if (ptr->left)
          parptr->right = ptr->left;
        else
          parptr->right = ptr->right;
        delete ptr;
      }
    }
  }
}
BST::~BST()
{
  while (root)
    del(root->item);
}