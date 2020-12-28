#include<bits/stdc++.h>
using namespace std;

long long merge(vector<int>& a, vector<int>& b, int left, int mid, int right)
{
  long long i = left , j = mid, k = left, con=0;
  while((i<mid) && (j<=right))
  {
    if(a[i] <= a[j])
    {
      b[k] = a[i];
      i++;
      k++;
    }
    else
    {
      b[k] = a[j];
      j++;
      k++;
      con = con + (mid-i);
    }
  }
  while(i<mid)
  {
    b[k] = a[i];
    i++;
    k++;
  }
  while(j<=right)
  {
    b[k] = a[j];
    j++;
    k++;
  }
  for(i=left;i<=right;i++)
    a[i] = b[i];
  return con;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {
  long long number_of_inversions = 0;
  if (left>=right)
    return number_of_inversions;
  int ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  number_of_inversions += merge(a,b,left,ave+1,right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  vector<int> b(n);
  std::cout << get_number_of_inversions(a, b, 0, n - 1) << '\n';
}
