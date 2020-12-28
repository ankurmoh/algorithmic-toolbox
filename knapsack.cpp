#include<bits/stdc++.h>
using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  int i,j,n=w.size(),current;
vector<vector<int>>dp(n+1, vector<int>(W+1,0));
//vector<int>dp(W+1,0);
for(i=1;i<=n;i++)
{
  current = w[i-1];
  for(j=1;j<=W;j++)
  {
    dp[i][j] = dp[i-1][j];
    //dp[j] = dp[j-1];
    if(j>=current)
    {
      //dp[j] = max(dp[j], current + dp[j-current]);
      dp[i][j] = max(dp[i][j], current + dp[i-1][j-current]);
    }
  }
}
return dp[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
