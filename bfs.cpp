#include<bits/stdc++.h>
using namespace std;
bool visited[10001];

void bfs(int root,vector<int>* edges,vector<int> &bfs_res){

	queue<int> q;
	q.push(root);
	visited[root] = 1;

	while(!q.empty()){
		int node = q.front();
		q.pop();
		bfs_res.push_back(node);
		for(auto child : edges[node]){
			if(!visited[child]){
				q.push(child);
				visited[child] = 1;
			}
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

	vector<int>*edges = new vector<int>[n+1];
	vector<int> bfs_res;

	for(int i=1;i<=m;i++){
		cin>>src>>dest;
		edges[src].push_back(dest);
		edges[dest].push_back(src);
	}

	for(int i=1;i<=n;i++){
		if(!visited[i]){
			bfs(i,edges,bfs_res);
		}
	}

	for(auto i : bfs_res)	cout<<i<<" ";

	return 0;
}