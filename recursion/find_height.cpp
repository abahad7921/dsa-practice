/*
    Find height of a binary tree using recursion
*/

#include <bits/stdc++.h>
using namespace std;

class node{

public:
	int data;
	node* left;
	node* right;
};


node* getNewNode(int data){
	node* temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


node* insert(node* root,int data){

	if(root == NULL){
		root = getNewNode(data);
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left,data);
	}
	else
		root->right = insert(root->right,data);

	return root;
}

void inorder(node* root){

	if(root == NULL){
		return;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int findHeight(node* root){

	if(root == NULL){
		return 0;
	}

	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);

	return 1 + max(leftHeight,rightHeight);
}

int main(){
	
	node* root = NULL; //initialzing the tree

	root = insert(root,10);
	root = insert(root,8);
	root = insert(root,15);
	root = insert(root,-1);
	root = insert(root,99);

	inorder(root);  //print the tree by inorder traversal

	cout<<findHeight(root);
}
