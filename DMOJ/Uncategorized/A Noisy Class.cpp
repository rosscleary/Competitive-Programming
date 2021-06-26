#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;

map < int,vector <int> > graph;
bool is_cycle=false;
bool searched[10001]={false};

void graph_search(int curr_point, vector <bool> visited) {

  if (visited[curr_point]) {
    is_cycle=true;
    return;
  }

  if (graph[curr_point].size()==0) {
    return;
  }

  for (int i=0; i<graph[curr_point].size(); i++) {
    vector <bool> visited_copy=visited;
    visited_copy[curr_point]=true;
    if (!searched[graph[curr_point][i]]) {
      graph_search(graph[curr_point][i],visited_copy);
    }
  }

  searched[curr_point]=true;

}

int main () {

  int n,m;
  cin>>n>>m;

  int p_1,p_2;
  for (int i=1; i<=m; i++) {
    cin>>p_1>>p_2;
    graph[p_1].push_back(p_2);
  }
  
  for (int i=1; i<=n; i++) {
    if (!searched[i]) {
      vector <bool> visited_start(n+1);
      graph_search(i,visited_start);
    }
    if (is_cycle) {
      break;
    }
  }

  if (!is_cycle) {
    cout<<"Y"<<endl;
  }
  else {
    cout<<"N"<<endl;
  }

  return 0;

}