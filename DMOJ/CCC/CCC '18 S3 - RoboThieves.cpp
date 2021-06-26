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

int n,m;
char grid[101][101];
map<int,vector<int> > graph;
bool valid_positions[101][101];
int shortest_path[10001]={0};

bool is_conveyer(int,int);
int end_position(int,int,vector<bool>);
int bfs(int);

int main () {

  cin>>n>>m;
  int start;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      cin>>grid[i][j];
      if (grid[i][j]=='S') {
        start=m*(i-1)+j;
      }
    }
  }

  memset(valid_positions,true,sizeof(valid_positions));
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      if (grid[i][j]=='W'|| is_conveyer(i,j)) {
        valid_positions[i][j]=false;
      }
      if (grid[i][j]=='C') {
        valid_positions[i][j]=false;
        int up=i;
        while (grid[up][j]!='W') {
          if (!is_conveyer(up,j)) {
            valid_positions[up][j]=false;
          }
          up--;
        }
        int down=i;
        while (grid[down][j]!='W') {
          if (!is_conveyer(down,j)) {
            valid_positions[down][j]=false;
          }
          down++;
        }
        int left=j;
        while (grid[i][left]!='W') {
          if (!is_conveyer(i,left)) {
            valid_positions[i][left]=false;
          }
          left--;
        }
        int right=j;
        while (grid[i][right]!='W') {
          if (!is_conveyer(i,right)) {
            valid_positions[i][right]=false;
          }
          right++;
        }
      }
    }
  }

  for (int i=2; i<n; i++) {
    for (int j=2; j<m; j++) {
      if (valid_positions[i][j]) {
        if (valid_positions[i-1][j]) {
          graph[m*(i-1)+j].push_back(m*(i-2)+j);
        }
        if (valid_positions[i+1][j]) {
          graph[m*(i-1)+j].push_back(m*i+j);
        }
        if (valid_positions[i][j-1]) {
          graph[m*(i-1)+j].push_back(m*(i-1)+j-1);
        }
        if (valid_positions[i][j+1]) {
          graph[m*(i-1)+j].push_back(m*(i-1)+j+1);
        }
      }
      if (is_conveyer(i-1,j)) {
        vector<bool> visited_start(n*m+1);
        int end_position_answer=end_position(i-1,j,visited_start);
        if (end_position_answer!=-1) {
          graph[m*(i-1)+j].push_back(end_position_answer);
        }
      }
      if (is_conveyer(i+1,j)) {
        vector<bool> visited_start(n*m+1);
        int end_position_answer=end_position(i+1,j,visited_start);
        if (end_position_answer!=-1) {
          graph[m*(i-1)+j].push_back(end_position_answer);
        }
      }
      if (is_conveyer(i,j-1)) {
        vector<bool> visited_start(n*m+1);
        int end_position_answer=end_position(i,j-1,visited_start);
        if (end_position_answer!=-1) {
          graph[m*(i-1)+j].push_back(end_position_answer);
        }
      }
      if (is_conveyer(i,j+1)) {
        vector<bool> visited_start(n*m+1);
        int end_position_answer=end_position(i,j+1,visited_start);
        if (end_position_answer!=-1) {
          graph[m*(i-1)+j].push_back(end_position_answer);
        }
      }
    }
  }

  bfs(start);

  for (int i=2; i<n; i++) {
    for (int j=2; j<m; j++) {
      if (grid[i][j]=='.' && valid_positions[m*(i-1)+j]) {
        if (shortest_path[m*(i-1)+j]) {
          cout<<shortest_path[m*(i-1)+j]<<endl;
        }
        else {
          cout<<"-1"<<endl;
        }
      }
    }
  }

  return 0;

}

bool is_conveyer(int row, int col) {

  if (grid[row][col]=='U' || grid[row][col]=='D' || grid[row][col]=='L' || grid[row][col]=='R') {
    return true;
  }

  return false;

}

int end_position(int row, int col, vector<bool> visited) {

  if (visited[m*(row-1)+col]) {
    return -1;
  }

  if ((grid[row][col]=='.' || grid[row][col]=='S') && valid_positions[row][col]) {
    return m*(row-1)+col;
  }

  vector<bool> visited_copy=visited;
  visited_copy[m*(row-1)+col]=true;
  if (grid[row][col]=='U') {
    return end_position(row-1,col,visited_copy);
  }
  if (grid[row][col]=='D') {
    return end_position(row+1,col,visited_copy);
  }
  if (grid[row][col]=='L') {
    return end_position(row,col-1,visited_copy);
  }
  if (grid[row][col]=='R') {
    return end_position(row,col+1,visited_copy);
  }

  return -1;

}

int bfs(int start) {

  list<int> queue;
  queue.push_back(start);
  bool visited[10001]={false};
  visited[start]=true;

  while (!queue.empty()) {
    int current=queue.front();
    queue.pop_front();
    for (int i=0; i<graph[current].size(); i++) {
      if (!visited[graph[current][i]]) {
        shortest_path[graph[current][i]]=shortest_path[current]+1;
        visited[graph[current][i]]=true;
        queue.push_back(graph[current][i]);
      }
    }
  }

  return -1;

}