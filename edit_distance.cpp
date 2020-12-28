#include<bits/stdc++.h>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int i,j,len1=str1.length(),len2=str2.length(),ans;
  vector<vector<int>>dp(len1+1, vector<int>(len2+1, 0));
  for(i=1;i<=len1;i++)
    dp[i][0]=i;
  for(i=1;i<=len2;i++)
    dp[0][i]=i;
  for(i=1;i<=len1;i++)
  {
    for(j=1;j<=len2;j++)
    {
      if(str1[i-1] == str2[j-1])
      {
        dp[i][j] = dp[i-1][j-1];
      }
      else
        dp[i][j] = min(1 + dp[i-1][j], min( 1 + dp[i][j-1], 1 + dp[i-1][j-1]));
    }
  }
  return dp[len1][len2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
