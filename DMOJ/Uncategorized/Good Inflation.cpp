#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> m_values, b_values;

bool invalid(int i, int j, int k) {
  return (b_values[k] - b_values[i]) * (m_values[i] - m_values[j]) < (b_values[j] - b_values[i]) * (m_values[i] - m_values[k]);
}

void add(int m, int b) {
  m_values.push_back(m), b_values.push_back(b);

  while(m_values.size() > 2 && invalid(m_values.size() - 3, m_values.size() - 2, m_values.size() - 1)) {
    m_values.erase(m_values.end() - 2), b_values.erase(b_values.end() - 2);
  }
}

int query(int x) {
  int l = 0, r = m_values.size() - 1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int less_1 = -1;
    if(mid - 1 >= 0) {
      less_1 = m_values[mid - 1] * x + b_values[mid - 1];
    }
    int equal = m_values[mid] * x + b_values[mid];
    int more_1 = -1;
    if(mid + 1 < m_values.size()) {
      more_1 = m_values[mid + 1] * x + b_values[mid + 1];
    }
    if(less_1 < equal && more_1 < equal) {
      return equal;
    }
    if(less_1 > equal) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return m_values[l] * x + b_values[l];
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> a(N + 1), d(N + 1);
  for(int i = N; i > 0; i--) {
    cin >> a[i] >> d[i];
  }

  add(0, 0);
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    int dp_value = a[i] - i * d[i] + query(d[i]);
    add(i, dp_value);
    ans = max(ans, dp_value);
  }

  cout << ans << '\n';

  return 0;
}