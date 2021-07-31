/*
    Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
    Note: 'X' shape consists of one or more adjacent X's (diagonals not included)

    Example 1:

Input: grid = {{X,O,X},{O,X,O},{X,X,X}}
Output: 3
Explanation: 
The grid is-
X O X
O X O
X X X
So, X with same colour are adjacent to each 
other vertically for horizontally (diagonals 
not included). So, there are 3 different groups 
in the given grid.

Example 2:

Input: grid = {{X,X},{X,X}}
Output: 1
Expanation: 
The grid is- 
X X
X X
So, X with same colour are adjacent to each
other vertically for horizontally (diagonals
not included). So, there is only 1 group
in the given grid.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function xShape() which takes grid as input parameter and returns the count of total X shapes.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 100
*/

/* Link to the question : 
        https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1/?category[]=Graph&category[]=Graph&problemStatus=unsolved&difficulty[]=0&difficulty[]=1&page=1&query=category[]GraphproblemStatusunsolveddifficulty[]0difficulty[]1page1category[]Graph#        
*/

//Solution

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    void DFS(int x, int y, int row, int col, vector<vector<char>>& grid)
    {
        if( x<0 || x>=row || y<0 || y>=col || grid[x][y]!='X')
        {
            return;
        }
        
        grid[x][y] = '0';
        DFS(x-1, y, row, col, grid);
        DFS(x, y-1, row, col, grid);
        DFS(x, y+1, row, col, grid);
        DFS(x+1, y, row, col, grid);
        
        
    }
    
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 'X'){
                    DFS(i, j, row, col, grid);
                    count++;
                }
            }
        }
        return count;
    }
};