//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3769
#include <iostream>

using namespace std;

struct node{
	int value;
	node* left, *right;
	node(int value){
		this -> value = value;
		this -> left = this -> right = NULL;
	}
};

void insert_node(node** root, int value){
	if(!*root) *root = new node(value);
	else {
		if((*root) -> value > value)
			insert_node(&(*root)-> left, value);
		else
			insert_node(&(*root)-> right, value);
	}
}

void post_order(node* root){
	if(!root) return;
	post_order(root -> left);
	post_order(root -> right);
	cout << root -> value << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int node_value;
	node* root = NULL;
	while(cin >> node_value){
		insert_node(&root, node_value);
	}
	post_order(root);

	return 0;
}

