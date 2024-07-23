// question:: Given two integers a and b, write a function lcmAndGcd() to
// compute their LCM and GCD. The function takes two integers a and b as input
// and returns a list containing their LCM and GCD.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  vector<long long> lcmAndGcd(long long A, long long B) {
    vector<long long> result;
    long long start = 2;
    long long tempA = A;
    long long tempB = B;
    long long lcm = 1;
    while (tempA > 1 || tempB > 1) {
      if (tempA % start == 0 || tempB % start == 0) {
        if (tempA % start == 0)
          tempA = tempA / start;
        if (tempB % start == 0)
          tempB = tempB / start;
        lcm = lcm * start;
      } else {
        start++;
      }
    }

    result.emplace_back(lcm);
    tempA = A;
    tempB = B;
    long long gcd = tempA * tempB;

    while (tempA > 0 && tempB > 0) {
      if (tempA > tempB)
        tempA = tempA % tempB;
      else
        tempB = tempB % tempA;
    }
    if (tempA == 0)
      gcd = tempB;
    else
      gcd = tempA;

    result.emplace_back(gcd);
    return result;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long A, B;

    cin >> A >> B;

    Solution ob;
    vector<long long> ans = ob.lcmAndGcd(A, B);
    cout << ans[0] << " " << ans[1] << endl;
  }
  return 0;
}
// } Driver Code Ends