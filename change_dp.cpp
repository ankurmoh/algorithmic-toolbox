#include <bits/stdc++.h>
using namespace std;

int get_change(int m) {
  //write your code here
  vector<int>dp(m+1,INT_MAX);
  vector<int>coins = {1,3,4};
  int i,j;
  dp[0]=0;
    for(j=1;j<=m;j++)
    {
        for(i=0;i<3;i++)
        {
          if((j>=coins[i]) && (dp[j-coins[i]]!=INT_MAX))
          {
            dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
          }
        }
    }
  if(dp[m] == INT_MAX)
    return -1;
  return dp[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
