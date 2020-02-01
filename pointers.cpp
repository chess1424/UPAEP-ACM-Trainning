#include <iostream>
#include <vector>

using namespace std;



void change_value_v2(int &v){
	v = 7;
	cout << "The value in change_value_v2 is " << v << endl;
}

void change_vector_by_reference(vector<int> &v){
	// for(int a = 0; a < v.size(); a++){
	// 	cout << v[a]
	// }
	for(int a : v){
		cout << a << " ";
	}

	cout << endl;

	v[1] = 100;
}


vector<int> change_vector_by_value(vector<int> v){
	// for(int a = 0; a < v.size(); a++){
	// 	cout << v[a]
	// }
	for(int a : v){
		cout << a << " ";
	}

	cout << endl;

	v[1] = 100;

	return v;
}

int main(){
	int a = 4;

	//change_vale(&a);

	//change_value_v2(a);
	//cout << "The value in the main method is " << a << endl;
	vector<int> v = {1,2,3,4,5};
	// change_vector_by_reference(v);
	// for(int a : v){
	// 	cout << a << " ";
	// }
	// cout << endl;

	v = change_vector_by_value(v);
	for(int a : v){
		cout << a << " ";
	}
	cout << endl;

}