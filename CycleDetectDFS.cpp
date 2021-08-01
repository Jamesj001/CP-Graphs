#include<bits/stdc++.h>
using namespace std;
bool visited[10001];

bool cycle_dfs(int root,int parent,vector<int>* edges){

	visited[root] = 1;
	
	for(auto child : edges[root]){
		if(!visited[child]){
			if(cycle_dfs(child,root,edges))	return true;
		}
		else if(child != parent)	return true;
	}

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
	vector<int> dfs_res;

	for(int i=1;i<=m;i++){
		cin>>src>>dest;
		edges[src].push_back(dest);
		edges[dest].push_back(src);
	}

	bool ans = false;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			if(cycle_dfs(i,-1,edges)){
				ans = true;
				break;
			}
		}
	}
	if(ans) cout<<"YES";
	else	cout<<"NO";

	return 0;
}