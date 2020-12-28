#include<bits/stdc++.h>
using namespace std;

int partition3(vector<int> &A) {
int i,j,n=A.size(),sum=0,current;
for(i=0;i<n;i++)
{
  sum=sum + A[i];
}
if(sum%3!=0)
  return 0;
sum=sum/3;
vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
for(i=0;i<=n;i++)
{
  dp[i][0] = true;
}
for(i=1;i<=sum;i++)
{
  dp[0][i]=false;
}
for(i=1;i<=n;i++)
{
  current = A[i-1];
  for(j=1;j<=sum;j++)
  {
    dp[i][j] = dp[i-1][j];
    if(j>=current)
    {
      dp[i][j] = dp[i][j] || dp[i-1][j-current];
    }
  }
}
if(dp[n][sum]==true)
  return 1;
return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
