                                      2
                                    /   \
                                   7     50
                                 /  \      \
                                20   6       9
                                   /   \    /
                                  5    11  4


string ans = "";
void find_path(node *root, int target, string path){
    if(root->value == target){
        ans = path + to_string(target-value)
    } else {
        find_path(root->left, path + to_stirng(root->value);
        find_path(root->right, path + to_string(root->value);
    }
}


int find_parent(node* root, int n1,int n2){
    find_path(root, n1)
    string s1 = ans;

    find_path(root, n2)
    string s2 = ans;

}

bool solved = false;

int find_parent(node* root, int n1,int n2){
        if(solved)
            return 0;
        if(root -> value == n1 || root -> value == n2){
            return 1;
        }
        else if(!root->left || !root->right){
            return 0;
        }
        else{
            bool m = find_parent(root -> left, n1, n2)
            bool n = find parent(root -> right, n1, n2)
            if(n && m ){
                cout << node-> value << endl;
                solved = true;
                return 0;
            }
            else if(n || m)
                return 1;
            else
                return 0;
        }

}

n1 = 20
n2 = 11

root = 11