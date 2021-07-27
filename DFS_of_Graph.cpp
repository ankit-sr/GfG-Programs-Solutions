/*
    Given a connected undirected graph. Perform a Depth First Traversal of the graph.
    Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

    Your task:
    You don’t need to read input or print anything. Your task is to complete the function dfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns  a list containing the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

    Expected Time Complexity: O(V + E)
    Expected Auxiliary Space: O(V)

    Constraints:
    1 ≤ V, E ≤ 104
*/

// Solution
#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	
	void dfs(int v, vector<int> &answer, vector<bool> &visited, vector<int> adj[])
	{
	    answer.push_back(v);
	    
	    visited[v] = true;
	    
	    for(auto i = adj[v].begin(); i != adj[v].end(); i++)
	    {
	        if(!visited[*i])
	        {
	            dfs( *i, answer, visited, adj);
	        }
	    }
	}
	
	vector<int> dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<bool> visited(V, false);
	    
	    vector<int> answer;
	    
	    dfs(0, answer, visited, adj);
	    
	    return answer;

	}
};