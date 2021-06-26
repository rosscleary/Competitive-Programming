#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int graph[10000];
int seperation;

bool circle(int person, int p_2, vector <bool> visited, int sep_counter) {
  if (person==p_2) {
    seperation=sep_counter;
    return true;
  }
  if (visited[person]) {
    return false;
  }
  vector <bool> visited_copy=visited;
  visited_copy[person]=true;
  if (circle(graph[person],p_2,visited_copy,sep_counter+1)) {
    return true;
  }
  return false;
}

int main () {
  int n;
  cin>>n;
  int person,person_friend;
  for (int i=1; i<=n; i++) {
    cin>>person>>person_friend;
    graph[person]=person_friend;
  }
  while (true) {
    int p_1,p_2;
    cin>>p_1>>p_2;
    if (p_1==0) {
      break;
    }
    vector <bool> visited(10000);
    if (circle(p_2,p_1,visited,0) && circle(p_1,p_2,visited,0)) {
      cout<<"Yes "<<seperation-1<<endl;
    }
    else {
      cout<<"No"<<endl;
    }
  }
}