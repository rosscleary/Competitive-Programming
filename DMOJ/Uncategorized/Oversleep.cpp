#include <bits/stdc++.h>
using namespace std;

int N, M;
char grid[40][40];
bool visited[40][40] = {false};

bool valid_position (int row, int col)

{

  if (row >= 0 && col >= 0 && row < N && col < M && grid[row][col] != 'X' && !visited[row][col]) 
    return true;

  return false;

}

int main() 

{

  scanf("%d%d", &N, &M);

  pair<int, int> start, end;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++) 
    {
      cin >> grid[i][j];
      if (grid[i][j] == 's') 
        start = make_pair(i, j);
      if (grid[i][j] == 'e') 
        end = make_pair(i, j);
    }
  }

  list<pair<int,int> > q;
  int dists[40][40] = {0};
  visited[start.first][start.second] = true;

  q.push_back(make_pair(start.first, start.second));

  while (!q.empty())
  {
    pair<int, int> curr = q.front();
    q.pop_front();
    if (valid_position(curr.first + 1, curr.second)) 
    {
        q.push_back(make_pair(curr.first + 1, curr.second));
        dists[curr.first + 1][curr.second] = dists[curr.first][curr.second] + 1;
        visited[curr.first + 1][curr.second] = true;
    }
    if (valid_position(curr.first - 1, curr.second)) 
    {
        q.push_back(make_pair(curr.first - 1, curr.second));
        dists[curr.first - 1][curr.second] = dists[curr.first][curr.second] + 1;
        visited[curr.first - 1][curr.second] = true;
    }
    if (valid_position(curr.first, curr.second + 1)) 
    {
        q.push_back(make_pair(curr.first, curr.second + 1));
        dists[curr.first][curr.second + 1] = dists[curr.first][curr.second] + 1;
        visited[curr.first][curr.second + 1] = true;
    }
    if (valid_position(curr.first, curr.second - 1)) 
    {
        q.push_back(make_pair(curr.first, curr.second - 1));
        dists[curr.first][curr.second - 1] = dists[curr.first][curr.second] + 1;
        visited[curr.first][curr.second - 1] = true;
    }
  }

  printf("%d\n", dists[end.first][end.second]-1);

  return 0;

}