#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>* edges,vector<int> &visited,stack<int> &sp){
	visited[node] = 1;

	for(auto adjacent : edges[node]){
		if(!visited[adjacent]){
			dfs(adjacent,edges,visited,sp);
		}
	}
	sp.push(node);
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


	int n,m,src,dest;
	cin>>n>>m;

	vector<int>* edges = new vector<int>[n];
	vector<int> visited(n,0);
	stack<int> sp;

	for(int i=1;i<=m;i++){
		cin>>src>>dest;
		edges[src].push_back(dest);
	}

	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(i,edges,visited,sp);
		}
	}

	while(!sp.empty()){
		cout<<sp.top()<<" ";
		sp.pop();
	}
	return 0;
}