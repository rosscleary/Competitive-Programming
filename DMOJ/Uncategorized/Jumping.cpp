#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e12;

vector<int> m_values, b_values;

bool bad(int i, int j, int k) {
  return (m_values[i] - m_values[k]) * (b_values[j] - b_values[i]) < (m_values[i] - m_values[j]) * (b_values[k] - b_values[i]);
}

void add(int m, int b) {
  m_values.push_back(m), b_values.push_back(b);
  while(m_values.size() >= 3 && bad(m_values.size() - 1, m_values.size() - 2, m_values.size() - 3)) {
    m_values.erase(m_values.end() - 2), b_values.erase(b_values.end() - 2);
  }
}

int pointer;
int query(int x) {
  if(pointer >= m_values.size()) {
    pointer = m_values.size() - 1;
  }

  while(pointer < m_values.size() - 1 && m_values[pointer] * x + b_values[pointer] > m_values[pointer + 1] * x + b_values[pointer + 1]) {
    pointer++;
  }

  return m_values[pointer] * x + b_values[pointer];
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, C;
  cin >> N >> C;
  vector<vector<char>> grid(C, vector<char>(N));
  for(int i = 0; i < C; i++) {
    for(int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }

  vector<int> dp(C);
  for(int i = 0; i < C; i++) {
    if(grid[i][N - 1] == '1') {
      add(-2 * i, i * i);
    }
  }

  for(int i = N - 2; i >= 0; i--) {
    dp.clear(), dp.resize(C);
    pointer = 0;
    for(int j = 0; j < C; j++) {
      if(grid[j][i] == '1') {
        dp[j] = j * j + query(j);
      }
    }
    m_values.clear(), b_values.clear();
    for(int j = 0; j < C; j++) {
      if(grid[j][i] == '1') {
        add(-2 * j, j * j + dp[j]);
      }
    }
  }

  int ans = M1;
  for(int i = 0; i < C; i++) {
    if(grid[i][0] == '1') {
      ans = min(ans, dp[i]);
    }
  }

  cout << ans << '\n';

  return 0;
}