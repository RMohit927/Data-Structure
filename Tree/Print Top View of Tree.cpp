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

void PrintTopView(Node *root){
	if(root == NULL) return;
    
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
 
    // push node and horizontal distance to queue
    q.push(root);
 
    cout << "The top view of the tree is : \n";
 
    while (q.size()) {
        hd = root->hd;
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
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
    
    PrintTopView(root);
    
	return 0;
}
/*
		10
	 2	    3
   7   8 12   15
             14

Ans: 7, 2, 10, 3, 15
*/
