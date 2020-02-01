#include <iostream>

// 1 -> 2 -> 3 -> NULL

using namespace std;

struct node{
	int value;
	node* next;
};

node* new_node(int value){
	node *new_node = new node;
	new_node -> value = value;
	new_node -> next = NULL;
	return new_node;
}

void insert_value(node** root, int value){
 	if(!*root){
 		*root = new_node(value);
 	} else {
 		node* aux = *root;
 		while(aux -> next){
 			aux = aux -> next;
 		}
 		aux -> next = new_node(value);
 	}
}

void print_linked_list(node* root){
	while(root){
		cout << root -> value << " ";
		root = root->next;
	}cout << endl;
}

void print_reverse_linked_list(node* root){
	if(!root)
		return;

	print_reverse_linked_list(root -> next);

	cout << root -> value << " ";
}


// 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> NULL

// 1 -> 2 -> 4 -> 5 -> 6 -> 7 -> NULL

void remove_first_match(node** root, int value){
	if((*root) -> value == value){
		*root = (*root) -> next;
	} else {
		node* aux = *root;
		while(aux -> next && aux -> next -> value != value){
			aux = aux -> next;
		}
		if(aux -> next)
			aux -> next = aux -> next -> next;
	}
}

int main(){
	node* root = NULL;
	insert_value(&root, 1);
	insert_value(&root, 2);
	insert_value(&root, 3);
	insert_value(&root, 4);
	insert_value(&root, 5);
	insert_value(&root, 6);
	insert_value(&root, 7);

	print_linked_list(root);
	remove_first_match(&root, 5	);
	print_linked_list(root);
	//print_reverse_linked_list(root);
	cout << endl;
}



