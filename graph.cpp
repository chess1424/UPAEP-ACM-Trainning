#include <iostream>
#include <vector>
#include <queue>


using namespace std;

void bfs(vector< vector<int> > &graph, int start){
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	q.push(start);

	while(!q.empty()){
		int curr = q.front();

		if(!visited[curr]){
			cout << curr << " ";
			visited[curr] = true;
		}

		q.pop();
		for(auto n : graph[curr]){
			if(!visited[n])
				q.push(n);
		}
	}
}

void dfs(vector< vector<int> > &graph, int start){
	vector<bool> visited(graph.size(), false);
	stack<int> s;
	s.push(start);

	while(!s.empty()){
		int curr = s.front();

		if(!visited[curr]){
			cout << curr << " ";
			visited[curr] = true;
		}

		s.pop();
		for(auto n : graph[curr]){
			if(!visited[n])
				s.push(n);
		}
	}
}

int main(){
	vector< vector<int> > graph(7, vector<int>());

	int u, v;
	while(cin >> u >> v){
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs(graph, 5);
}