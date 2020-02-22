//https://omegaup.com/arena/problem/Ancho-de-un-arbol#problems

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node{
	node* left, *right;
	int value, left_nodes, right_nodes;

	node(int value){
		this -> value = value;
		this -> left = this -> right = NULL;
	}
};

// void post_order(node *root){
// 	if(!root) return;
// 	post_order(root -> left);
// 	post_order(root -> right);
// }

int compute_num_nodes(node *root){
	if(!root) return 0;

	root -> left_nodes = compute_num_nodes(root -> left);
	root -> right_nodes = compute_num_nodes(root -> right);

	return root -> left_nodes + root -> right_nodes + 1;
}

void compute_left_distances(node* root, vector<int> &left_width, int level, bool inc, int sum){
	if(!root) return;
	int new_distance = inc == true ? sum + root -> right_nodes + 1 : sum - (root -> left_nodes + 1);

	if(level == 1) left_width[level] = new_distance = 1;
	if(left_width[level] == 0) left_width[level] += new_distance;

	if(root -> left){
		compute_left_distances(root->left, left_width, level + 1, true, new_distance);
	}
	if(root -> right){
		compute_left_distances(root->right, left_width, level + 1, false, new_distance);
	} else {
		return;
	}
}

void compute_right_distances(node* root, vector<int> &right_width, int level, bool inc, int sum){
	if(!root) return;
	int new_distance = inc == true ? sum + root -> left_nodes + 1: sum - (root -> right_nodes) - 1;

	if(level == 1) right_width[level] = new_distance = 0;
	else right_width[level] += new_distance;

	if(root -> right){
		compute_right_distances(root->right, right_width, level + 1, true, new_distance);
	} else if(root -> left){
		compute_right_distances(root->left, right_width, level + 1, false, new_distance);
	} else {
		return;
	}
}

pair<int, int> solve(node* root, int N){
	vector<int> left_width(N+1, 0);
	vector<int> right_width(N+1, 0);
	compute_num_nodes(root);
	compute_left_distances(root, left_width, 1, true, 0);
	compute_right_distances(root, right_width, 1, true, 0);

	pair<int, int> ans = make_pair(1,1);
	for(int i = 1; i <= N; i++){
		if(left_width[i] + right_width[i] > ans.first){
			ans = make_pair(left_width[i] + right_width[i] , i);
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, root, left, right;


	map<int, node*> m;


	while(cin >> N){
		for(int i = 0; i < N; i++){
			cin >> root >> left >> right;

			node* ptr_root = m.find(root) != m.end() ? m[root] : new node(root);
			m[root] = ptr_root;
			if(left != -1){
				node* ptr_left = m.find(left) != m.end() ? m[left] : new node(left);
				m[left] = ptr_left;
				ptr_root -> left = ptr_left;
			}
			if(right != -1){
				node* ptr_right = m.find(right) != m.end() ? m[right] : new node(right);
				m[right] = ptr_right;
				ptr_root -> right = ptr_right;
			}
		}
		pair<int, int> ans = solve(m[1], N);
		cout << ans.second << " " << ans.first << endl;
	}

	return 0;
}