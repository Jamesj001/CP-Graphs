#include<bits/stdc++.h>
using namespace std;
bool visited[10001];

void dfs(int root,vector<int>* edges,vector<int> &dfs_res){

	visited[root] = 1;
	dfs_res.push_back(root);
	for(auto child : edges[root]){
		if(!visited[child]){
			dfs(child,edges,dfs_res);
		}
	}
	return;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n,m,src,dest;
	cin>>n>>m;

	vector<int>* edges = new vector<int>[n+1];
	vector<int> dfs_res;

	for(int i=1;i<=m;i++){
		cin>>src>>dest;
		edges[src].push_back(dest);
		edges[dest].push_back(src);
	}

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i,edges,dfs_res);
		}
	}

	for(auto i : dfs_res){
		cout<<i<<" "; 
	}
	return 0;
}