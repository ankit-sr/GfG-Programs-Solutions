/* Midori like chocolates and he loves to try different ones. 
There are N shops in a market labelled from 1 to N and each shop 
offers a different variety of chocolate. Midori starts from ith shop
 and goes ahead to each and every shop. But as there are too many shops
 Midori would like to know how many more shops he has to visit. You have 
 been given L denoting number of bits required to represent N. You need to 
 return the maximum number of shops he can visit.
 */
 
 //Solution
 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int leftShops(long long int i, long long int L){
        long long int n = pow(2,L);
        return (n-i);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int i, L;
        cin >> i >> L;
        Solution ob;
        cout << ob.leftShops(i, L) << endl;
    }
    return 0;
}
