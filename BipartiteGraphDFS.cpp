// check whether given graph is bipartite or not
// odd length cycle - not a bipartitee graph
// even length cycle / NO cycle - is a bipartite graph
#include<bits/stdc++.h>
using namespace std;

bool colorDFS(int source,vector<int>* edges,vector<int> &color){

	if(color[source] == -1)	color[source] = 1;

	for(auto adjacent : edges[source]){
		if(color[adjacent] == -1){
			color[adjacent] = 1 - color[source];
			if(!colorDFS(adjacent,edges,color)){
				return false;
			}
		}
		else if(color[adjacent] == color[source]){
			return false;
		}
	}
	return true;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n,m,src,dest;
	cin>>n>>m;

	vector<int>* edges = new vector<int>[n+1];
	vector<int> color(n+1,-1);

	for(int i=1;i<=m;i++){
		cin>>src>>dest;
		edges[src].push_back(dest);
		edges[dest].push_back(src);
	}

	for(int i=1;i<=n;i++){
		if(color[i] == -1){
			if(!colorDFS(i,edges,color)){
				cout<<"Not a bipartite graph";
				return 0;
			}
		}
	}

	cout<<"YES its a bipartite graph";
	return 0;
}