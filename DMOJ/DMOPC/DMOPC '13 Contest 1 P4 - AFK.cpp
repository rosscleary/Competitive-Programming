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

  int t;
  scanf("%d",&t);
  while (t--) {

    int l,w;
    scanf("%d%d",&l,&w);
    bool grid[52][52]={false};
    int start,end;
    for (int i=1; i<=w; i++) {
      for (int j=1; j<=l; j++) {
        char position_state;
        cin>>position_state;
        if (position_state=='O') {
          grid[i][j]=true;
        }
        else {
          if (position_state=='C') {
            grid[i][j]=true;
            start=(i-1)*l+j;
          }
          else {
            if (position_state=='W') {
              grid[i][j]=true;
              end=(i-1)*l+j;
            }
          }
        }
      }
    }

    map<int,vector<int> > graph;
    for (int i=1; i<=w; i++) {
      for (int j=1; j<=l; j++) {
        if (grid[i-1][j]) {
          graph[(i-1)*l+j].push_back((i-2)*l+j);
        }
        if (grid[i+1][j]) {
          graph[(i-1)*l+j].push_back(i*l+j);
        }
        if (grid[i][j-1]) {
          graph[(i-1)*l+j].push_back((i-1)*l+j-1);
        }
        if (grid[i][j+1]) {
          graph[(i-1)*l+j].push_back((i-1)*l+j+1);
        }
      }
    }

    list<int> queue;
    queue.push_back(start);
    bool visited[2704]={false};
    int distances[2704]={0};
    while (!queue.empty()) {
      int current=queue.front();
      queue.pop_front();
      for (int i=0; i<graph[current].size(); i++) {
        if (!visited[graph[current][i]]) {
          distances[graph[current][i]]=distances[current]+1;
          visited[graph[current][i]]=true;
          queue.push_back(graph[current][i]);
        }
      }
    }

    if (distances[end]==0 || distances[end]>=60) {
      printf("#notworth\n");
    }
    else {
      printf("%d\n",distances[end]);
    }

  }

  return 0;

}