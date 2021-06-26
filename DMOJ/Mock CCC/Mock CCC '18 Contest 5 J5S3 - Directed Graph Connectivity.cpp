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
#define ll long long
using namespace std;

int main () {

  int N,M;
  scanf("%d%d",&N,&M);
  map<int,vector<int> > graph;
  vector<pair<int,int> > edges;
  for (int i=0,x,y; i<M; i++) {
    scanf("%d%d",&x,&y);
    graph[x].push_back(y);
    edges.push_back(make_pair(x,y));
  }

  for (int i=0; i<edges.size(); i++) {
    
    list<int> queue;
    bool visited[51]={false};
    queue.push_back(1);
    while (!queue.empty()) {
      int current=queue.front();
      queue.pop_front();
      for (int j=0; j<graph[current].size(); j++) {
        bool current_edge=false;
        if (current==edges[i].first && graph[current][j]==edges[i].second) {
          current_edge=true;
        }
        if (!visited[graph[current][j]] && !current_edge) {
          queue.push_back(graph[current][j]);
          visited[graph[current][j]]=true;
        }
      }
    }

    if (visited[N]) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }

  }

  return 0;

}