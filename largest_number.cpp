#include<bits/stdc++.h>
using namespace std;

string largest_number(vector<string> a) {
  sort(a.begin(),a.end(),[](const string& x, const string& y)
{
  // int i,len1=x.length(),len2=y.length(),lenx = min(len1,len2);
  // for(i=0;i<lenx;i++)
  // {
  //   if(x[i]>y[i])
  //     return true;
  //   else if(y[i]>x[i])
  //     return false;
  // }
  // if(lenx==len1)
  //   return true;
  // return false;
  string p = x + y;
  string q = y + x;
  if(p>q)
    return 1;
  return 0;
});
string ans="";
int i,n=a.size();
for(i=0;i<n;i++)
  ans=ans+a[i];
return ans;
}

int main() {
  int n;
  std::cin >> n;
   vector<string> a(n);
   //vector<int>temp(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
//   int n = 100;
// temp = {2, 8, 2, 3, 6, 4, 1, 1, 10, 6, 3, 3, 6, 1, 3, 8, 4, 6, 1, 10, 8, 4, 10, 4, 1, 3, 2, 3, 2, 6, 1, 5, 2, 9, 8, 5, 10, 8, 7, 9, 6, 4, 2, 6, 3,
//   8, 8, 9, 8, 2, 9, 10, 3, 10, 7, 5, 7, 1, 7, 5, 1, 4, 7, 6, 1, 10, 5, 4, 8, 4, 2, 7, 8, 1, 1, 7, 4, 1, 1, 9, 8, 6, 5, 9, 9, 3, 7, 6, 3, 10, 8, 10, 7, 2, 5, 1, 1, 9, 9, 5};
// for(int i=0;i<100;i++)
// {
//   a[i] = to_string(temp[i]);
// }
  std::cout << largest_number(a);
}
