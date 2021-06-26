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

int N, M;
int grid[100][100];

bool valid_position (int num_1, int num_2, int num_3, int row, int col)

{

  if (row >= 0 && col >= 0 && row < M && col < N && (grid[row][col] == num_1 || grid[row][col] == num_2 || grid[row][col] == num_3)) return true;

  return false;

}

int main ()

{

  sf("%d%d", &N, &M);

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      sf("%d", &grid[i][j]);
    }
  }

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      for (int k = 0; k < 10; k++)
      {

        list<pa<int,int> > q;
        bool visited[100][100] = {false};

        for (int l = 0; l < N; l++)
        {
          if (grid[0][l] == i || grid[0][l] == j || grid[0][l] == k)
          {
            q.pb(mp(0, l));
            visited[0][l] = true;
          }
        }

        while (!q.emp())
        {
          pa<int,int> curr = q.fr();
          q.pof();
          if (curr.fi == M - 1)
          {
            pf("%d %d %d\n", i, j, k);
            return 0;
          }
          if (valid_position(i, j, k, curr.fi + 1, curr.se) && !visited[curr.fi + 1][curr.se])
          {
            q.pb(mp(curr.fi + 1, curr.se));
            visited[curr.fi + 1][curr.se] = true;
          }
          if (valid_position(i, j, k, curr.fi - 1, curr.se) && !visited[curr.fi - 1][curr.se])
          {
            q.pb(mp(curr.fi - 1, curr.se));
            visited[curr.fi - 1][curr.se] = true;
          }
          if (valid_position(i, j, k, curr.fi, curr.se + 1) && !visited[curr.fi][curr.se + 1])
          {
            q.pb(mp(curr.fi, curr.se + 1));
            visited[curr.fi][curr.se + 1] = true;
          }
          if (valid_position(i, j, k, curr.fi, curr.se - 1) && !visited[curr.fi][curr.se - 1])
          {
            q.pb(mp(curr.fi, curr.se - 1));
            visited[curr.fi][curr.se - 1] = true;
          }
        }

      }
    }
  }

  pf("-1 -1 -1\n");

  return 0;

}