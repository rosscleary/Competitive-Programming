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
using namespace std;

int r,c;
map<int,vector<int> > graph;

int bfs();

int main () {

  int t;
  cin>>t;

  for (int test_case=1; test_case<=t; test_case++) {
    graph.clear();
    cin>>r>>c;
    char grid[21][21];
    for (int i=1; i<=r; i++) {
      for (int j=1; j<=c; j++) {
        cin>>grid[i][j];
      }
    }
    for (int i=1; i<=r; i++) {
      for (int j=1; j<=c; j++) {
        if (grid[i][j]=='+') {
          if (i!=1) {
            graph[c*(i-1)+j].push_back(c*(i-2)+j);
          }
          if (i!=r) {
            graph[c*(i-1)+j].push_back(c*i+j);
          }
          if (j!=1) {
            graph[c*(i-1)+j].push_back(c*(i-1)+j-1);
          }
          if (j!=c) {
            graph[c*(i-1)+j].push_back(c*(i-1)+j+1);
          }
        }
        if (grid[i][j]=='|') {
          if (i!=1) {
            graph[c*(i-1)+j].push_back(c*(i-2)+j);
          }
          if (i!=r) {
            graph[c*(i-1)+j].push_back(c*i+j);
          }
        }
        if (grid[i][j]=='-') {
          if (j!=1) {
            graph[c*(i-1)+j].push_back(c*(i-1)+j-1);
          }
          if (j!=c) {
            graph[c*(i-1)+j].push_back(c*(i-1)+j+1);
          }
        }
      }
    }

    if (r==1 && c==1) {
      cout<<"1"<<endl;
    }
    else {
      if (grid[r][c]=='*') {
        cout<<"-1"<<endl;
      }
      else {
        cout<<bfs()<<endl;
      }
    }

  }

  return 0;

}

int bfs() {

  list<int> queue;
  queue.push_back(1);
  bool visited[401]={false};
  visited[1]=true;
  int shortest_path[401]={0};
  shortest_path[1]=1;

  while (!queue.empty()) {
    int current=queue.front();
    queue.pop_front();
    for (int i=0; i<graph[current].size(); i++) {
      if (!visited[graph[current][i]]) {
        visited[graph[current][i]]=true;
        queue.push_back(graph[current][i]);
        shortest_path[graph[current][i]]=shortest_path[current]+1;
        if (graph[current][i]==r*c) {
          return shortest_path[r*c];
        }
      }
    }
  }

  return -1;

}