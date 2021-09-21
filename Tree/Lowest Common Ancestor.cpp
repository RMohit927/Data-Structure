#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

struct Node{
	int data;
	Node *left, *right;
};

Node *newNode(int data){
	Node *temp = new Node();
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}

Node *LowestCommonAncestor(Node *root, int n1, int n2){
	if(!root)
        return NULL;
    
    if(root->data == n1 || root->data == n2)
    {
        return root;
    }
    
    Node* left = LowestCommonAncestor(root->left, n1, n2);
    Node* right = LowestCommonAncestor(root->right, n1, n2);

    if(!left)
        return right;
    else if(!right)
        return left;
    
    return root; 
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
    
    int n1 = 15, n2 = 3;
	Node *result = LowestCommonAncestor(root, n1, n2);
	cout << result->data;
	return 0;
}
