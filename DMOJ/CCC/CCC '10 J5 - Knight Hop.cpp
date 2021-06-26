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

  map<pair<int,int>,vector<pair<int,int> > > graph;
  for (int i=1; i<=8; i++) {
    for (int j=1; j<=8; j++) {
      graph[make_pair(i,j)].push_back(make_pair(i-2,j-1));
      graph[make_pair(i,j)].push_back(make_pair(i-2,j+1));
      graph[make_pair(i,j)].push_back(make_pair(i-1,j-2));
      graph[make_pair(i,j)].push_back(make_pair(i-1,j+2));
      graph[make_pair(i,j)].push_back(make_pair(i+1,j-2));
      graph[make_pair(i,j)].push_back(make_pair(i+1,j+2));
      graph[make_pair(i,j)].push_back(make_pair(i+2,j-1));
      graph[make_pair(i,j)].push_back(make_pair(i+2,j+1));
    }
  }

  int x_1,y_1,x_2,y_2;
  scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);

  pair<int,int> start=make_pair(8-y_1+1,x_1);
  pair<int,int> end=make_pair(8-y_2+1,x_2);

  if (start==end) {
    printf("0\n");
    return 0;
  }

  list<pair<int,int> > queue;
  bool visited[9][9]={false};
  int distances[9][9]={0};
  queue.push_back(start);
  visited[start.first][start.second]=true;
  while (1) {
    pair<int,int> current=queue.front();
    queue.pop_front();
    for (int i=0; i<graph[current].size(); i++) {
      if (graph[current][i].first>0 && graph[current][i].first<9 && graph[current][i].second>0 && graph[current][i].second<9 && !visited[graph[current][i].first][graph[current][i].second]) {
        visited[graph[current][i].first][graph[current][i].second]=true;
        distances[graph[current][i].first][graph[current][i].second]=distances[current.first][current.second]+1;
        if (graph[current][i]==end) {
          printf("%d\n",distances[end.first][end.second]);
          return 0;
        }
        queue.push_back(graph[current][i]);
      }
    }
  }

}