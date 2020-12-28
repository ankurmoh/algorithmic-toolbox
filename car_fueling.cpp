#include<bits/stdc++.h>
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
  stops.push_back(dist);
  stops.insert(stops.begin(),0);
  int i=0,n=stops.size(),current,minstop=0,currentcapacity = tank,next;
  for(i=1;i<n;i++)
  {
      if(stops[i]-stops[i-1]>tank)
        return -1;
  }
  i=0;
  while(i<n)
  {
    current = i;
    if(current >= n-1)
    {
      return minstop;
    }
    next = i+1;
    while(next<n)
    {
      if(stops[next]-stops[current]<=currentcapacity)
      {
        currentcapacity = currentcapacity - (stops[next]-stops[current]);
        current=next;
        next=next+1;
      }
      else
        break;
    }
    if(current >= n-1)
        return minstop;
    i=current;
    minstop++;
    currentcapacity=tank;
  }
  if(current>=n-1)
    return minstop;
  return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (int i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
