#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"

struct Node{
	int data;
	Node *left, *right;
};

Node *newNode(int item){
	Node *temp = new Node();
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
};

void leftViewUtil(Node *root, int level, int *max_level){
	if (root == NULL) return;
	if (*max_level < level)
	{
		cout << root->data << " ";
		*max_level = level;
	}
	leftViewUtil(root->right, level + 1, max_level);
	leftViewUtil(root->left, level + 1, max_level);
}

void leftView(Node *root)
{
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}

int main(){
	fast;
	Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	leftView(root);
	return 0;
}

/*
	10
     2	    3
   7   8 12   15
             14

Ans: 10, 3, 15, 14
*/
