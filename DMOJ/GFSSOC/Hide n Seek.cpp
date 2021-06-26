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

map<int,vector<int> > graph;

int min_time(int, vector <int>);
int bfs(int, int);

int main () {

  int n,m,t;
  cin>>n>>m>>t;

  bool grid[25][25]={false};
  char position;
  int start;
  vector <int> hider_positions;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      cin>>position;
      if (position=='G') {
        start=m*(i-1)+j;
        grid[i][j]=true;
      }
      else {
        if (position=='H') {
          grid[i][j]=true;
          hider_positions.push_back(m*(i-1)+j);
        }
        else {
          if (position=='.') {
            grid[i][j]=true;
          }
        }
      }
    }
  }

  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      if (grid[i-1][j] && i>1) {
        graph[m*(i-1)+j].push_back(m*(i-2)+j);
      }
      if (grid[i+1][j] && i<n) {
        graph[m*(i-1)+j].push_back(m*i+j);
      }
      if (grid[i][j+1] && j<m) {
        graph[m*(i-1)+j].push_back(m*(i-1)+j+1);
      }
      if (grid[i][j-1] && j>1) {
        graph[m*(i-1)+j].push_back(m*(i-1)+j-1);
      }
    }
  }

  cout<<min_time(start,hider_positions)<<endl;

  return 0;

}

int min_time(int current_position, vector <int> hiders_left) {
  
  if (!hiders_left.size()) {
    return 0;
  }

  int min_time_sub=1000000000;
  for (int i=0; i<hiders_left.size(); i++) {
    vector<int> hiders_left_copy=hiders_left;
    hiders_left_copy.erase(hiders_left_copy.begin()+i);
    int time=bfs(current_position,hiders_left[i])+min_time(hiders_left[i],hiders_left_copy);
    if (time<min_time_sub) {
      min_time_sub=time;
    }
  }

  return min_time_sub;

}

int bfs(int start, int end) {

  list<int> queue;
  queue.push_back(start);
  bool visited[450]={false};
  int min_time[450]={0};

  while (!queue.empty()) {
    int current=queue.front();
    queue.pop_front();

    for (int i=0; i<graph[current].size(); i++) {
      if (!visited[graph[current][i]]) {
        queue.push_back(graph[current][i]);
        visited[graph[current][i]]=true;
        min_time[graph[current][i]]=min_time[current]+1;
        if (graph[current][i]==end) {
          return min_time[graph[current][i]];
        }
      }
    }

  }

  return 1000000000;

}