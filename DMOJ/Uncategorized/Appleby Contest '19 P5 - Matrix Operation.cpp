#include <bits/stdc++.h>
using namespace std;

int N;
int grid[1500][1500];

int dp[1500][1500] = {0};
int dp_solved[1500][1500] = {false};

int valid_position (int curr_row, int curr_col, int new_row, int new_col)

{

  if (new_row >= 0 && new_row < N && new_col >= 0 && new_col < N && grid[new_row][new_col] > grid[curr_row][curr_col]) return true;

  return false;

}

int dp_solver (int row, int col)

{

  if (dp_solved[row][col]) return dp[row][col];

  bool pos_1 = (valid_position(row, col, row + 1, col));
  bool pos_2 = (valid_position(row, col, row - 1, col));
  bool pos_3 = (valid_position(row, col, row, col + 1));
  bool pos_4 = (valid_position(row, col, row, col - 1));

  if (pos_1 + pos_2 + pos_3 + pos_4 == 0) 
  {
    dp_solved[row][col] = true;
    return dp[row][col] = 0;
  }

  if (pos_1) dp[row][col] = max(dp[row][col], 1 + dp_solver(row + 1, col));
  if (pos_2) dp[row][col] = max(dp[row][col], 1 + dp_solver(row - 1, col));
  if (pos_3) dp[row][col] = max(dp[row][col], 1 + dp_solver(row, col + 1));
  if (pos_4) dp[row][col] = max(dp[row][col], 1 + dp_solver(row, col - 1));

  dp_solved[row][col] = true;
  return dp[row][col];

}

int main ()

{

  scanf("%d", &N);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++) scanf("%d", &grid[i][j]);
  }

  int answer = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (!dp_solved[i][j]) dp_solver(i, j);
      answer = max(answer, dp[i][j]);
    }
  }

  printf("%d\n", answer);

  return 0;

}