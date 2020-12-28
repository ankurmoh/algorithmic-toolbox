#include<bits/stdc++.h>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  int n=weights.size(),i,current;
  vector<pair< double, int>> temp;
  for(i=0;i<n;i++)
  {
    double frac = 1.0 * (1.0 * values[i]/ weights[i]);
    temp.push_back(make_pair(frac,i));
  }
  sort(temp.begin(),temp.end(), [](const pair<double,int>& p1, const pair<double,int>& p2)
{
  if(p1.first != p2.first)
    return p1.first>p2.first;
  return p1.second< p2.second;
});
// for(i=0;i<n;i++)
// {
//     cout<<temp[i].first<<" "<<temp[i].second<<endl;
// }
i=0;
while(i<n)
{
  current = temp[i].second;
  if(capacity == 0)
    break;
  else if(capacity>=weights[current])
  {
    capacity = capacity - weights[current];
    value = value + values[current];
    i++;
  }
  else if(capacity < weights[current])
  {
    double frac = 1.0 * (1.0 * capacity/weights[current]);
    value = value + values[current]*frac;
    break;
  }
}
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
