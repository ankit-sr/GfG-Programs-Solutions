/*
    Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
    Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
    

    Example 1:

    Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
    Output: 5
    Explanation: The grid is-
    1 1 1 0
    0 0 1 0
    0 0 0 1
    The largest region of 1's is colored
    in orange.
    Example 2:

    Input: grid = {{0,1}}
    Output: 1
    Explanation: The grid is-
    0 1
    The largest region of 1's is colored in 
    orange.

    Your Task:
    You don't need to read or print anyhting. Your task is to complete the function findMaxArea() which takes grid as input parameter and returns the area of the largest region of 1's.


    Expected Time Complexity: O(n*m)
    Expected Auxiliary Space: O(n*m)
    

    Constraints:
    1 ≤ n, m ≤ 500
*/

//  Solution

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    
    public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &count)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        
        count++;
        grid[i][j] = 0;
        dfs(grid, i-1, j-1, count);
        dfs(grid, i-1, j, count);
        dfs(grid, i-1, j+1, count); 
        
        dfs(grid, i, j-1, count);
        dfs(grid, i, j+1, count);
        
        dfs(grid, i+1, j-1, count);
        dfs(grid, i+1, j, count);
        dfs(grid, i+1, j+1, count);
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int area = 0;
        // vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                int count = 0;
                if (grid[i][j] == 1){
                    dfs(grid, i, j, count);
                }
                area = max(area, count);
            }
        }
        return area;
}
};