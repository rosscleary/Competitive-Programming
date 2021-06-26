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

map<int,vector<int> > graph;
int room_counter=0;
int rooms[626]={0};

void bfs(int);

int main () {

  int flooring_amount,r,c;
  cin>>flooring_amount>>r>>c;
  char grid[28][28];
  for (int i=0; i<28; i++) {
    for (int j=0; j<28; j++) {
      grid[i][j]='I';
    }
  }
  for (int i=1; i<=r; i++) {
    for (int j=1; j<=c; j++) {
      cin>>grid[i][j];
    }
  }

  for (int i=1; i<=r; i++) {
    for (int j=1; j<=c; j++) {
      if (grid[i][j]=='.') {
        if (grid[i+1][j]=='.') {
          graph[(i-1)*c+j].push_back(i*c+j);
        }
        if (grid[i-1][j]=='.') {
          graph[(i-1)*c+j].push_back((i-2)*c+j);
        }
        if (grid[i][j+1]=='.') {
          graph[(i-1)*c+j].push_back((i-1)*c+j+1);
        }
        if (grid[i][j-1]=='.') {
          graph[(i-1)*c+j].push_back((i-1)*c+j-1);
        }
      }
    }
  }

  for (int i=1; i<=r; i++) {
    for (int j=1; j<=c; j++) {
      if (grid[i][j]=='.') {
        if (!rooms[(i-1)*c+j]) {
          room_counter++;
          rooms[(i-1)*c+j]=room_counter;
          bfs((i-1)*c+j);
        }
      }
    }
  }

  int room_frequency[626]={0};
  for (int i=1; i<=r; i++) {
    for (int j=1; j<=c; j++) {
      room_frequency[rooms[(i-1)*c+j]]++;
    }
  }
  
  sort(room_frequency+1,room_frequency+626);
  int floored_rooms_counter=0;
  int remainder;
  int flooring_left=flooring_amount;
  for (int i=625; i>=1; i--) {
    if (room_frequency[i]<=flooring_left) {
      floored_rooms_counter++;
      flooring_left-=room_frequency[i];
    }
    else {
      break;
    }
  }
  remainder=flooring_left;
  floored_rooms_counter=min(floored_rooms_counter,room_counter);

  if (floored_rooms_counter==1) {
    cout<<"1 room, "<<remainder<<" square metre(s) left over"<<endl;
  }
  else {
    cout<<floored_rooms_counter<<" rooms, "<<remainder<<" square metre(s) left over"<<endl;
  }

  return 0;

}

void bfs(int start) {

  list<int> queue;
  bool visited[626]={false};
  queue.push_back(start);

  while (!queue.empty()) {
    int current=queue.front();
    queue.pop_front();
    for (int i=0; i<graph[current].size(); i++) {
      if (!visited[graph[current][i]]) {
        visited[graph[current][i]]=true;
        queue.push_back(graph[current][i]);
        rooms[graph[current][i]]=room_counter;
      }
    }
  }

}