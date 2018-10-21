#include<bits/stdc++.h>
#include"treeTraversal.cpp"
using namespace std;

node *root = new node;

vector<int> inOrderList;

void binaryTree();

int getRootElementIndex(vector<int> inOrderList, int rootElement) {
	int in = 0;
	for(int root : inOrderList) {
		if(root == rootElement) return in;
		in += 1;
	}
}

bool locateCurrentElement(vector<int> inOrderList, int curr, int endIndex) {
	for(int i=0; i<endIndex; i++) {
		if(curr == inOrderList.at(i)) return true;
	}
	
	return false;
}

void insertNode(node *ptr, int curr) {
	int rootElementIndex = getRootElementIndex(inOrderList, ptr->data);
	bool toLeft = locateCurrentElement(inOrderList, curr, rootElementIndex);
	
	if(toLeft) {
		if(ptr->left == NULL) {
			node *newNode = new node;
			newNode->data = curr;
			newNode->left = NULL;
			newNode->right = NULL;
			
			ptr->left = newNode;
			
		} else {
			insertNode(ptr->left, curr);
		}
		
	} else {
		if(ptr->right == NULL) {
			node *newNode = new node;
			newNode->data = curr;
			newNode->left = NULL;
			newNode->right = NULL;
			
			ptr->right = newNode;
			
		} else {
			insertNode(ptr->right, curr);
		}
	}
}

void constructTree(vector<int> sOrder, bool leftIndex) {
	int inOrderListLength = inOrderList.size();
	int sOrderLength = sOrder.size();
	
	if(inOrderListLength != sOrderLength) {
		cout<<endl<<"There is some mistake, lengths of in-order and supporting-order doesn't match!"<<endl;
		cout<<"Redirecting to home-screen!";
		
		binaryTree();
		
	} else {
		int inc 	= leftIndex?1:-1;
		int start	= leftIndex?0:sOrderLength-1;
		int end		= leftIndex?sOrderLength:-1;
		
		root->data = sOrder.at(start);
		root->left = NULL;
		root->right = NULL;
		
		start += leftIndex?1:-1;
		
		for(int i=start; i!=end; i+=inc) {
			insertNode(root, sOrder.at(i));
		}
	}
}

void binaryTree() {
	vector<int> preOrderList;
	vector<int> postOrderList;
	
	cout<<"Construct Binary-Tree using :"<<endl<<endl;
	cout<<"1. In-Order and Pre-Order"<<endl;
	cout<<"2. In-Order and Post-Order"<<endl<<endl;
	
	int choice;
	cin>>choice;
	
	cin.ignore();
	
	cout<<"Make sure each element is unique as it identifies nodes."<<endl;
	cout<<"Enter In-Order Traversal of Binary-Tree : "<<endl;
	
	string inOrderString;
	getline(cin, inOrderString);
	
	stringstream inOrderStream(inOrderString);
	
	while(1) {
		int temp;
		inOrderStream>>temp;
		
		if(!inOrderStream) break;
		
		inOrderList.push_back(temp);
	}
	
	cout<<"Enter "<<(choice==1?"Pre":"Post")<<"-Order Traversal of Binary-Tree : "<<endl;
	
	string supportingOrderString;
	getline(cin, supportingOrderString);
	
	stringstream supportingOrderStream(supportingOrderString);
	
	while(1) {
		int temp;
		supportingOrderStream>>temp;
				
		if(!supportingOrderStream) break;
		
		switch(choice) {
			case 1: {
				preOrderList.push_back(temp);
				break;
			}
			case 2: {
				postOrderList.push_back(temp);
				break;
			}
			default : {
				cout<<"Invalid choice!";
				break;
			}
		}	
	}
	
	constructTree((choice==1?preOrderList:postOrderList), (choice==1?true:false));
}
