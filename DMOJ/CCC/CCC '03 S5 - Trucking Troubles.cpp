#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <climits>
using namespace std;

int main () {

  int c,r,d;
  cin>>c>>r>>d;

  map<int,vector<pair<int,int> > > graph;
  for (int i=1,x,y,w; i<=r; i++) {
    cin>>x>>y>>w;
    graph[x].push_back(make_pair(y,w));
    graph[y].push_back(make_pair(x,w));
  }
  vector<int> dest_cities;
  for (int i=1,d_c; i<=d; i++) {
    cin>>d_c;
    dest_cities.push_back(d_c);
  }

  vector<pair<int,bool> > weight_used(c+1);
  weight_used[1].first=INT_MAX;
  weight_used[1].second=0;
  for (int i=2; i<=c; i++) {
    weight_used[i].first=INT_MIN;
    weight_used[i].second=0;
  }
  while (1) {

    int max_weight=INT_MIN;
    int max_city=0;
    for (int i=1; i<=c; i++) {
      if (weight_used[i].first>max_weight && !weight_used[i].second) {
        max_weight=weight_used[i].first;
        max_city=i;
      }
    }
    if (!max_city) {
      break;
    }
    weight_used[max_city].second=true;

    for (int i=0; i<graph[max_city].size(); i++) {
      weight_used[graph[max_city][i].first].first=max(weight_used[graph[max_city][i].first].first,min(weight_used[max_city].first,graph[max_city][i].second));
    }

  }

  int min_dest=INT_MAX;
  for (int i=0; i<dest_cities.size(); i++) {
    min_dest=min(min_dest,weight_used[dest_cities[i]].first);
  }
  cout<<min_dest<<endl;

  return 0;

}