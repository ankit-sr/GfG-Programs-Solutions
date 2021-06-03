
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to return the count of the number of elements in
    //the intersection of two arrays.
    int NumberofElementsInIntersection (int a[], int b[], int n, int m )
    {
        int count = 0;
        set<int> s1, s2;
        for(int i=0; i<n; i++){
            s1.insert(a[i]);
        }
        for(int i=0; i<m; i++){
            s2.insert(b[i]);
        }
        for(set<int>::iterator i = s1.begin(); i!=s1.end(); i++){
            for(set<int>::iterator j=s2.begin(); j!=s2.end(); j++){
                if(*i == *j)
                    count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n], b[m];
		for(int i=0; i<n; i++)
			cin>>a[i];

		for(int i=0; i<m; i++)
			cin>>b[i];
		Solution ob;
		cout << ob.NumberofElementsInIntersection(a,b,n,m) << endl;
	}
	return 0;
}  // } Driver Code Ends