#include<bits/stdc++.h>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int i,j,k,len1=a.size(),len2=b.size(),len3=c.size();
  vector<vector<vector<int>>>lcs(len1+1, vector<vector<int>>(len2+1, vector<int>(len3+1, 0)));
  for(i=1;i<=len1;i++)
  {
    for(j=1;j<=len2;j++)
    {
      for(k=1;k<=len3;k++)
      {
        if((a[i-1] == b[j-1]) && (b[j-1] == c[k-1]))
          lcs[i][j][k] = 1 + lcs[i-1][j-1][k-1];
        else
          lcs[i][j][k] = max(lcs[i-1][j][k], max (lcs[i][j-1][k], lcs[i][j][k-1]));
      }
    }
  }
  return lcs[len1][len2][len3];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
