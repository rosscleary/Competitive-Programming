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
#include <cstdlib>
#include <ctime>

using namespace std;

#define ll long long

const ll mod=1000000007;
const string alph_l("abcdefghijklmnopqrstuvwxyz");
const string alph_c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const string digits("0123456789");

int m,n;

char grid[1005][1005];

bool valid_location (int row, int col)

{

  if (row<=n && row>0 && col<=m && col>0 && grid[row][col]!='#')
  {
    return true;
  }

  return false;

}


int main () 

{

  scanf("%d%d",&m,&n);

  pair<int,int> start;

  for (int i=1; i<=n; i++)
  {
    for (int j=1; j<=m; j++)
    {
      cin>>grid[i][j];
      if (grid[i][j]=='1')
      {
        start=make_pair(i,j);
      }
    }
  }

  list<pair<int,int> > q;
  bool visited[1005][1005]={false};
  q.push_back(start);
  visited[start.first][start.second]=true;

  vector<int> valid_rooms;

  while (!q.empty())
  {
    pair<int,int> curr=q.front();
    q.pop_front();
    if (digits.find(grid[curr.first][curr.second])>0 && digits.find(grid[curr.first][curr.second])<10)
    {
      valid_rooms.push_back(grid[curr.first][curr.second]-'0');
    }
    if (!visited[curr.first+1][curr.second] && valid_location(curr.first+1,curr.second))
    {
      q.push_back(make_pair(curr.first+1,curr.second));
      visited[curr.first+1][curr.second]=true;
    }
    if (!visited[curr.first-1][curr.second] && valid_location(curr.first-1,curr.second))
    {
      q.push_back(make_pair(curr.first-1,curr.second));
      visited[curr.first-1][curr.second]=true;
    }
    if (!visited[curr.first][curr.second+1] && valid_location(curr.first,curr.second+1))
    {
      q.push_back(make_pair(curr.first,curr.second+1));
      visited[curr.first][curr.second+1]=true;
    }
    if (!visited[curr.first][curr.second-1] && valid_location(curr.first,curr.second-1))
    {
      q.push_back(make_pair(curr.first,curr.second-1));
      visited[curr.first][curr.second-1]=true;
    }
  }

  sort(valid_rooms.begin(),valid_rooms.end());

  for (int i=0; i<valid_rooms.size(); i++)
  {
    printf("%d ",valid_rooms[i]);
  }

  printf("\n");

  return 0;

}