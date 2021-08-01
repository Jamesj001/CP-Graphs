#include<bits/stdc++.h>
using namespace std;
bool visited[10001];
bool dfs_visited[10001];

//we have to use double visited array in case of directed graph

bool checkCycleDFS(int root,vector<int>* edges){
	visited[root] = 1;
	dfs_visited[root] = 1;

	for(auto node : edges[root]){
		if(!visited[node]){
			if(checkCycleDFS(node,edges)){
				return true;
			}
		}
		else if(dfs_visited[node]){
			return true;
		}
	}
	dfs_visited[root] = 0; //imp step
 	return false;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n,m,src,dest;
	cin>>n>>m;

	vector<int>* edges = new vector<int>[n+1];

	for(int i=1;i<=m;i++){
		cin>>src>>dest;
		edges[src].push_back(dest);
	}

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			if(checkCycleDFS(i,edges)){
				cout<<"YES\n";
				return 0;
			}
		}
	}
	cout<<"NO\n";
	return 0;
}

//sample IP:
// 9 10 n m
// 1 2 	edges
// 7 2
// 7 8
// 8 9
// 2 3
// 3 4
// 4 5
// 3 6
// 6 5
// 9 7