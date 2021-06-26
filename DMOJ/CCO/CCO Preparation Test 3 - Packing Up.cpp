#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> m_values, b_values;

bool bad(int i, int j, int k) {
  return (b_values[k] - b_values[i]) / (m_values[i] - m_values[k]) < (b_values[j] - b_values[i]) / (m_values[i] - m_values[j]);
}

void add(int m, int b) {
  m_values.push_back(m), b_values.push_back(b);
  while(m_values.size() >= 3 && bad(m_values.size() - 3, m_values.size() - 2, m_values.size() - 1)) {
    m_values.erase(m_values.end() - 2), b_values.erase(b_values.end() - 2);
  }
}

int pointer = 0;
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

  int N, L;
  cin >> N >> L;
  vector<int> C(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> C[i];
    C[i] += C[i - 1];
  }

  add(0, 0);
  int dp;
  for(int i = 1; i <= N; i++) {
    dp = (C[i] + i) * (C[i] + i - 2 * (L + 1)) + (L + 1) * (L + 1);
    dp += query(C[i] + i);
    add(-2 * (C[i] + i), (C[i] + i) * (C[i] + i + 2 * (L + 1)) + dp);
  }

  cout << dp << '\n';

  return 0;
}