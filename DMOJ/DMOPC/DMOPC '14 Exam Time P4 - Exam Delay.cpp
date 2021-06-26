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

  int V,E;
  cin>>V>>E;
  map<int,vector<pair<int,float> > > graph;
  float d,s;
  for (int i=1,m,n; i<=E; i++) {
    cin>>m>>n>>d>>s;
    graph[m].push_back(make_pair(n,d/s));
    graph[n].push_back(make_pair(m,d/s));
  }

  float dijkstra[1001][3]={0};
  dijkstra[1][0]=0;
  for (int i=2; i<=V; i++) {
    dijkstra[i][0]=INT_MAX;
  }
  while (1) {
    
    int min_time=INT_MAX;
    int curr_city=0;
    for (int i=1; i<=V; i++) {
      if (dijkstra[i][0]<min_time && !dijkstra[i][2]) {
        min_time=dijkstra[i][0];
        curr_city=i;
      }
    }
    if (!curr_city) {
      break;
    }
    dijkstra[curr_city][2]=1;

    for (int i=0; i<graph[curr_city].size(); i++) {
      if (dijkstra[curr_city][0]+graph[curr_city][i].second<dijkstra[graph[curr_city][i].first][0]) {
        dijkstra[graph[curr_city][i].first][0]=dijkstra[curr_city][0]+graph[curr_city][i].second;
        dijkstra[graph[curr_city][i].first][1]=dijkstra[curr_city][1]+1;
      }
      else {
        if (dijkstra[curr_city][0]+graph[curr_city][i].second==dijkstra[graph[curr_city][i].first][0]) {
          if (dijkstra[curr_city][1]+1<dijkstra[graph[curr_city][i].first][1]) {
            dijkstra[graph[curr_city][i].first][1]=dijkstra[curr_city][1]+1;
          }
        }
      }
    }

  }

  cout<<dijkstra[V][1]<<endl;
  cout<<round(((dijkstra[V][0]*60)/0.75)-(dijkstra[V][0]*60))<<endl;

  return 0;

}