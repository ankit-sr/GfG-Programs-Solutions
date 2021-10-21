/*
    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 
*/


// Solution

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	stack<int> st;
	
	void dfs(int v, vector<int> trans[], vector<bool> &visited){
	    
	    visited[v] = true;
	    for(auto i = trans[v].begin(); i != trans[v].end(); i++){
	        if(!visited[*i])
	            dfs(*i, trans, visited);
	    }
	}
	void dfs_topo(int v, vector<int> adj[], vector<bool> &visited){
	    
	    visited[v] = true;
	    for(auto i = adj[v].begin(); i != adj[v].end(); i++){
	        if(!visited[*i])
	            dfs_topo(*i, adj, visited);
	    }
	    st.push(v);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        for (int i = 0; i< V; i++){
            if(!visited[i])
                dfs_topo(i, adj, visited);
        }
        
        vector<int> trans[V];
        for(int i = 0; i< V; i++){
	        for(auto j=adj[i].begin(); j!=adj[i].end(); j++){
	            trans[*j].push_back(i);
	        }
	    }
        
        visited.assign(V, false);
        int count = 0;
        while(!st.empty()){
            int v = st.top();
            st.pop();
            
            if(!visited[v]){
                dfs(v, trans, visited);
                count++;
            }
        }
        return count;
    }
};