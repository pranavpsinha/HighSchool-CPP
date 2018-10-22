#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *left;
	node * right;
}*tmp, *sr;

vector<int> preOrderData;
vector<int> inOrderData;
vector<int> postOrderData;
vector<int> levelOrderData;
vector<int> boundaryData;
vector<int> diagonalData;

/*
* Pre-Order Tree-Traversal
*/
int preOrder(node *root){
	if(root == NULL)
		return 0;
	
	preOrderData.push_back(root->data);
	preOrder(root->left);
	preOrder(root->right);
}

/*
* In-Order Tree-Traversal
*/
int inOrder(node *root){
	if(root == NULL)
		return 0;
	
	inOrder(root->left);
	inOrderData.push_back(root->data);
	inOrder(root->right);
}

/*
* Post-Order Tree-Traversal
*/
int postOrder(node *root){
	if(root == NULL)
		return 0;
	
	postOrder(root->left);
	postOrder(root->right);
	postOrderData.push_back(root->data);
}

/*
* Level-Wise Tree-Traversal
*/
queue<node*> q;
int levelOrder(node *root){
	
	if(root == NULL)
		return 0;
	
	levelOrderData.push_back(root->data);
	
	
	if(root->left != NULL)
		q.push(root->left);
	if(root->right != NULL)
		q.push(root->right);
	
	tmp = q.front();
	if(tmp != NULL)
		q.pop();
	
	levelOrder(tmp);
}

/*
* Boundary Tree-Traversal
*/
int travLeft(node *rt) {
	if(rt == NULL) return 0;
	
	bool isLeaf = rt->left == NULL && rt->right == NULL;
	
	if(!isLeaf) boundaryData.push_back(rt->data);
	travLeft(rt->left);
}

int travLeaf(node *rt) {
	if(rt == NULL) return 0;
	
	bool isLeaf = rt->left == NULL && rt->right == NULL;
	
	if(isLeaf) boundaryData.push_back(rt->data);
	travLeaf(rt->left);
	travLeaf(rt->right);
}

int lastLeaf = -1;
int travPre(node *rt, node *prevPar) {
	if(rt == NULL) return 0;
	
	if(rt->data == lastLeaf) {
		if(prevPar != sr) {
			lastLeaf = prevPar->data;
			boundaryData.push_back(lastLeaf);
		}
		
		return 0;
	}
	
	travPre(rt->left, rt);
	
	if(rt->data == lastLeaf) {
		if(prevPar != sr) {
			lastLeaf = prevPar->data;
			boundaryData.push_back(lastLeaf);
		}
	}
	
	travPre(rt->right, rt);
}

int travRight(node *rt) {
	if(rt == NULL) return 0;
	
	bool isLeaf = rt->left == NULL && rt->right == NULL;
		
	travRight(rt->right);
	if(!isLeaf) {
		if(rt != sr) {
			boundaryData.push_back(rt->data);	
		}
	}
}

void boundary(node *root) {
	node *bkp;
	bkp = root;
	travLeft(root); root = bkp;
	travLeaf(root); root = bkp;
	lastLeaf = boundaryData.at(boundaryData.size()-1);
	//travRight(root->right);
	travPre(root->right, root);
}

void diagonal(node *root) {
	queue<node*> curr;
	queue<node*> next;
	
	node *dryRun = root;
	inOrder(dryRun);
	
	int numberOfNodes = inOrderData.size();
	int nodesTraversed = 0;
	
	curr.push(root);
	
	while(nodesTraversed != numberOfNodes) {
		while(!curr.empty()) {
			node *me;
			me = curr.front();
			curr.pop();
			
			diagonalData.push_back(me->data);
			
			if(me->right != NULL) {
				curr.push(me->right);
			}
			
			if(me->left != NULL) {
				next.push(me->left);
			}
			
			nodesTraversed += 1;
		}
		
		while(!next.empty()) {
			curr.push(next.front());
			next.pop();
		}
	}
}


