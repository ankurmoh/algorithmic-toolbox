#include<bits/stdc++.h>
using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
int i,j,len1=a.size(),len2=b.size();
vector<vector<int>>lcs(len1+1, vector<int>(len2+1, 0));
for(i=1;i<=len1;i++)
{
  for(j=1;j<=len2;j++)
  {
    if(a[i-1] == b[j-1])
      lcs[i][j]=1+lcs[i-1][j-1];
    else
      lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
  }
}
return lcs[len1][len2];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
