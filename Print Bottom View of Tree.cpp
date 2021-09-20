#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"

struct Node{
	int data, hd;
	Node *left, *right;
};

Node *newNode(int data){
	Node *temp = new Node();
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}

void PrintBottomView(Node *root){
	if(root == NULL) return;
	
	int hd = 0;
	map<int, int> m;
	queue<Node*> q;
	root->hd = hd;
	q.push(root);
	
	while(q.size()){
		Node *temp = q.front();
        q.pop();
        
        hd = temp->hd;
        m[hd] = temp->data;
        if (temp->left)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if (temp->right)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
	}
	for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }
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
    
    PrintBottomView(root);
	return 0;
}

/*
		10
	 2	    3
   7   8 12   15
             14

Ans: 7, 2, 12, 14, 15
*/
