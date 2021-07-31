/*
    Given a weighted, undirected and connected graph of V vertices and E edges. 
    The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

    Your task:
    Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and an adjacency matrix adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and second integer w denotes that the distance between edge i and j is w.
    

    Expected Time Complexity: O(ElogV).
    Expected Auxiliary Space: O(V2).
    

    Constraints:
    2 ≤ V ≤ 1000
    V-1 ≤ E ≤ (V*(V-1))/2
    1 ≤ w ≤ 1000
    Graph is connected and doesn't contain self loops & multiple edges.
*/

/*
    Link to the question:
        https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1    
*/

// Solution

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	vector<int> parent, rank;
	
	void make_set(int v){
	    parent[v] = v;
	    rank[v] = 0;
	}
	
	int find_set(int v){
	    if(parent[v] == v)
	        return v;
	    return parent[v] = find_set(parent[v]);
	}
	
	void union_set(int u, int v){
	    int a = find_set(u);
	    int b = find_set(v);
	    
	    if(a != b){
	        if(rank[a] < rank[b])
	            swap(a, b);
	            
	        parent[b] = a;
	        
	        if(rank[a] == rank[b])
	            rank[a]++;
	    }
	}
	

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> res;
        for(int i = 0; i < V; i++)
        {
            vector<int> temp;
            for(int j = 0; j < adj[i].size(); j++)
            {
                vector<int> x = adj[i][j];
                temp.push_back(x[1]);
                temp.push_back(min(i, x[0]));
                temp.push_back(max(i, x[0]));
                res.push_back(temp);
                temp.clear();
            }
        }
       
        sort(res.begin(), res.end());
       
        vector<vector<int>> graph;
        for(int i = 0; i < res.size(); i+=2)
            graph.push_back(res[i]);
        
        int cost = 0;    
        parent.resize(V);
        rank.resize(V);
        for(int i=0; i<V; i++)
        {
            make_set(i);
        }
        
        for(vector<int> e : graph){
            if(find_set(e[1]) != find_set(e[2])){
                cost += e[0];
                union_set(e[1], e[2]);
            }
        }
        
        return cost;
    }
};
