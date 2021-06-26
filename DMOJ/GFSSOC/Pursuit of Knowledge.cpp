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
int shortest_distances[1001][1001]={0};

int bfs(int);

int main () {
    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,t;
  cin>>n>>m>>t;
  for (int i=1,a,b; i<=m; i++) {
    cin>>a>>b;
    graph[a].push_back(b);
  }

  for (int i=1; i<=n; i++) {
    bfs(i);
  }

  int q;
  cin>>q;
  for (int i=1,a,b; i<=q; i++) {
    cin>>a>>b;
    int query_answer=t*shortest_distances[a][b];
    if (query_answer){
      cout<<query_answer<<endl;
    }
    else {
      cout<<"Not enough hallways!"<<endl;
    }
  }

  return 0;

}

int bfs(int start) {

  list<int> queue;
  queue.push_back(start);
  bool visited[1001]={false};

  while (!queue.empty()) {
    int current=queue.front();
    queue.pop_front();
    for (int i=0; i<graph[current].size(); i++) {
      if (!visited[graph[current][i]]) {
        shortest_distances[start][graph[current][i]]=shortest_distances[start][current]+1;
        queue.push_back(graph[current][i]);
        visited[graph[current][i]]=true;
      }
    }
  }

  return 0;

}