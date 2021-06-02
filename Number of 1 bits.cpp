// Given a positive integer N, print count of set bits in it. 

// Solution

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBits(int n) {
        vector<int> v;
        int i=0;
        while(n>0){
            v.push_back(n%2);
            n = n/2;
            i++;
        }
        int x = count(v.begin(), v.end(), 1);
        return x;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

