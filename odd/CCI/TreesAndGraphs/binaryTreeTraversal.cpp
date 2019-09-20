#include <iostream>

using namespace std;

struct Node
{
   int value;
   Node* left;
   Node* right;
   Node(int value)
   {
      this->value = value;
      this->left = NULL;
      this->right = NULL;
   }
};

void inOrderTraversal(Node* root)
{
   if (root != NULL)
   {
      inOrderTraversal(root->left);
      cout << root->value << " ";
      inOrderTraversal(root->right);
   }
}

void preOrderTraversal(Node* root)
{
   if (root != NULL)
   {
      cout << root->value << " ";
      preOrderTraversal(root->left);
      preOrderTraversal(root->right);
   }
}

void postOrderTraversal(Node* root)
{
   if (root != NULL)
   {
      postOrderTraversal(root->left);
      postOrderTraversal(root->right);
      cout << root->value << " ";
   }
}

int main()
{
   Node* v1 = new Node(1);
   Node* v2 = new Node(2);
   Node* v3 = new Node(3);
   Node* v4 = new Node(4);
   Node* v5 = new Node(5);
   Node* v6 = new Node(6);
   Node* v7 = new Node(7);
   Node* v8 = new Node(8);

   v1->left = v2;
   v1->right = v3;
   v2->left = v4;
   v2->right = v5;
   v3->left = v6;
   v5->left = v8;
   v6->right = v7;

   inOrderTraversal(v1);
   cout << endl;
   preOrderTraversal(v1);
   cout << endl;
   postOrderTraversal(v1);
   cout << endl;
}
