#include<bits/stdc++.h>
using namespace std;

long long binary_search(const vector<long long> &a, long long x) {
  long long left = 0, right = (long long)a.size(),mid;
  while(left<right)
  {
    mid = left + (right-left)/2;
    if(a[mid] == x)
      return mid;
    if(x>a[mid])
      left=mid+1;
    else if(x<a[mid])
      right = mid-1;
  }
  if((left>=0) && (a[left]==x))
    return left;
  if((right<a.size()) && (a[right]==x))
    return right;
  if((mid>=0) && (mid<a.size()) && (a[mid]==x))
    return mid;
  return -1;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  long long m;
  std::cin >> m;
  vector<long long> b(m);
  for (long long i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  //sort(a.begin(), a.end());
  for (long long i = 0; i < m; ++i) {
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
