//Modified BST using a Dynamic Single Linked List
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

//struct to store key and contains the two child nodes which define the node as part of tree
struct node{
	int key;
	struct node *left, *right;
};

//function to create new node
struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

//print function to perform inorder traversal of tree
void inorder(struct node *root){
	if (root != NULL){
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

//function to insert a new node with key into tree
struct node* insert(struct node* node, int key) {
	//if emtpy
	if (node == NULL) return newNode(key);
	//otherwise recur down
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	//return node ptr
	return node;
}

//return the node with min key value if tree != NULL
struct node * minValueNode(struct node* node){
	struct node* current = node;
	//loop to find leftmost leaf
	while (current->left != NULL)
		current = current->left;
		return current;
}

//delete key and return new root
struct node* deleteNode(struct node* root, int key){
	//base case
	if(root == NULL) return root;
	//if key to be deleted is smaller than root then look left
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	//if key to be deleted is greater than root then look right
	else if (key > root->key)
		root->right = deleteNode(root->right, key);		
	//if key == root then node needs to be deleted
	else {
		//node has one child or no child
		if(root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root ->right == NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		//node with two childern, get smallest in right subtree
		struct node* temp = minValueNode(root->right);
		//copy inorder content to node
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);	
	}
	return root;
}
//driver
int main() {
  struct node * root = NULL;
  string line;
  ifstream infile("A3.DAT"); //input file
  ofstream outfile("A3_Output.DAT"); //output file
  while (getline(infile, line)) {
    istringstream iss(line);
    char c;
    int num;
    cout << "Reading from input file... \n" << endl;
    while (iss >> c) {
      if (c == 'I' || c == 'i') {
        iss >> num;
        root = insert(root, num);
        cout << num << " has been inserted." << endl;
        outfile << num << " has been inserted." << endl;
      } else if (c == 'D' || c == 'd') {
        iss >> num;
        root = deleteNode(root, num);
        cout << num << " has been deleted." << endl;
        outfile << num << " has been deleted." << endl;
      }
    }
  }
  cout << endl << "Inorder traversal of the BST: \n" << endl;
  inorder(root); //call print function
  
  return 0;
}
