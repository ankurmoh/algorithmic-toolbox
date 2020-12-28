#include<bits/stdc++.h>
using namespace std;

vector<int> optimal_sequence(int n) {
vector<int>res;
if(n==1)
{
  res = {1};
  return res;
}
vector<int>dp(n+1);
dp[0]=0;
dp[1]=0;
int i,a,b,c,mini;
for(i=2;i<=n;i++)
{
  dp[i] = dp[i-1] + 1;
  if(i%2==0)
    dp[i] = min(dp[i], dp[i/2] + 1);
  if(i%3==0)
    dp[i] = min(dp[i], dp[i/3] + 1);
}
for(i=n;i>1;)
{
  res.push_back(i);
  if(dp[i] ==  dp[i-1] + 1)
  {
    i=i-1;
  }
  else if((i%2==0) && (dp[i] == 1 + dp[i/2]))
  {
    i=i/2;
  }
  else if((i%3==0) && (dp[i] == 1 + dp[i/3]))
  {
    i=i/3;
  }
}
res.push_back(1);
reverse(res.begin(),res.end());
return res;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
