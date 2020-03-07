#include<iostream>
#include<vector>

using namespace std;

//f(1) = 1 f(2) =1
vector<long> v(51);


long fb(int n){
	if(v[n] != 0) return v[n];

	v[n] = fb(n-1) + fb(n-2);
	return v[n];
	// if(n == 1 || n == 2) return 1;
	// return fb(n - 1) + fb(n -2);
}


long fb2(int n){
	for(int i = 3; i <= n; i++){
		v[i] = v[i-1] + v[i-2];
	}

	return v[n];
}

//1 1 2 3 5 8 13


long f(int n){

	if(n < 0) return 0;

    if(v[n] != 0) return v[n];

    if(n == 0){
      v[n] = 1;
      return v[n];
    }

    v[n] = f(n - 1) + f(n - 2) + f (n - 3);

    return v[n];
}

int main(){
	//v[1] = 1;
	//v[2] = 1;
	cout << f(50) << endl;

	return 0;
}