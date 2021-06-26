#include <bits/stdc++.h>

using namespace std;

// Variable Types
#define ll long long int
#define Ull unsigned long long int
#define dou double
#define bo bool
#define ch char
#define str string
#define pa pair

// Data Structure Types
#define ve vector
#define li list
#define ma map

// Input and Output
#define sf scanf
#define pf printf

// Pair Functions
#define fi first
#define se second
#define mp make_pair

// String, Vector, Map, List Functions
#define le length
#define era erase
#define sub substr
#define app append
#define pb push_back
#define sz size
#define cl clear
#define emp empty
#define pof pop_front
#define fr front

const int mod=1000000007;

const string alph_l("abcdefghijklmnopqrstuvwxyz");
const string alph_c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const string digits("0123456789");

// ---------- END OF TEMPLATE ----------

int R, C;
char grid[40][40];

bool visited[40][40] = {false};

bool valid_square (int row, int col)

{

  if (row >= 0 && col >= 0 && row < R && col < C && grid[row][col] != '#' && !visited[row][col]) return true;

  return false;

}

int main ()

{

  sf("%d%d", &R, &C);

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++) cin >> grid[i][j];
  }

  li<pa<int, int> > q;
  int rooms[40][40] = {0};

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      int digit_find = digits.find(grid[i][j]);
      if (digit_find > 0 && digit_find < 6)
      {
        q.pb(mp(i, j));
        visited[i][j] = true;
        rooms[i][j] = grid[i][j] - '0';
      }
    }
  }

  while (!q.emp())
  {
    pa<int, int> curr = q.front();
    q.pop_front();
    if (valid_square(curr.fi + 1, curr.se))
    {
      q.pb(mp(curr.fi + 1, curr.se));
      visited[curr.fi + 1][curr.se] = true;
      rooms[curr.fi + 1][curr.se] = rooms[curr.fi][curr.se];
    }
    if (valid_square(curr.fi - 1, curr.se))
    {
      q.pb(mp(curr.fi - 1, curr.se));
      visited[curr.fi - 1][curr.se] = true;
      rooms[curr.fi - 1][curr.se] = rooms[curr.fi][curr.se];
    }
    if (valid_square(curr.fi, curr.se + 1))
    {
      q.pb(mp(curr.fi, curr.se + 1));
      visited[curr.fi][curr.se + 1] = true;
      rooms[curr.fi][curr.se + 1] = rooms[curr.fi][curr.se];
    }
    if (valid_square(curr.fi, curr.se - 1))
    {
      q.pb(mp(curr.fi, curr.se - 1));
      visited[curr.fi][curr.se - 1] = true;
      rooms[curr.fi][curr.se - 1] = rooms[curr.fi][curr.se];
    }
  }

  int room_areas[6] = {0};

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++) room_areas[rooms[i][j]]++;
  }

  for (int i = 1; i <= 5; i++) pf("%d\n", room_areas[i]);

  return 0;

}