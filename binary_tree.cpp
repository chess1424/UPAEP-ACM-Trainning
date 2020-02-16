#include <iostream>
#include <map>
using namespace std;

struct node{
	int value;
	node* left;
	node* right;
	node(int value){
		this -> value = value;
		this -> left = this->right = NULL;
	}
};

void pre_order(node* root){
    if(!root)
        return;
    cout << root->value << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(node* root){

    if(root == NULL){
        return;
    }
    in_order(root -> left);
    cout << root -> value << " ";
    in_order(root->right);

}
void post_order(node* root){
    if(root == NULL)
        return;

    post_order(root->left);
    post_order(root->right);
    cout << root->value << " ";
}

int main(){
	// node* root = new node(2);
	// root -> left = new node(7);
	// root -> left -> left = new node(2);
	// root -> left -> right = new node(6);
	// root -> left ->right -> left = new node(5);
	// root -> left -> right -> right = new node(11);
	// root -> right = new node(5);
	// root -> right -> right = new node(9);
	// root -> right -> right -> left = new node(4);

	int n, v, l, r;
	map<int, node*> m; //key -> node
	cin >> n;
	node* root = NULL;
	while(n--){
		cin >> v >> l >> r;
		if(m.find(v) == m.end()){
			node* new_node = new node(v);
			root = new_node;
			cout << "root value is " << v << endl;
			if(l != -1)
				m[l] = new_node -> left = new node(l);
			if(r != -1)
				m[r] = new_node -> right = new node(r);
		}else {
			if(l != -1)
				m[v] -> left = m[l] = new node(l);
			if(r != -1)
				m[v] -> right = m[r] = new node(r);
		}
	}

// 	     2
//     /   \
//    7     5
//  /  \      \
// 2    6       9
//    /   \    /
//   5    11  4


	 cout << "in_order "; in_order(root); cout << endl;
	 cout << "pre_order "; pre_order(root); cout << endl;
	 cout << "post_order "; post_order(root); cout << endl;

	return 0;
}