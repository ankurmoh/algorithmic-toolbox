#include<bits/stdc++.h>
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
int i,sz = right;
if(right == 0)
  return 0;
if(right == 1)
  return 1;
sort(a.begin(), a.end());
for(i=0;i<=sz/2;i++)
{
  if((i + sz/2 < sz) && (a[i] == a[i + sz/2]))
    return 1;
}
return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
