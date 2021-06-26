#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e9 + 1;

struct node {
  int min_value, gcd_value, freq;
};

vector<int> arr;
vector<node> st;

void construct(int l, int r, int i) {
  if(l == r) {
    st[i] = {arr[l], arr[l], 1};
    return;
  }
  int mid = (l + r) / 2;
  int next_i_1 = 2 * i + 1, next_i_2 = 2 * i + 2;
  construct(l, mid, next_i_1), construct(mid + 1, r, next_i_2);
  st[i].min_value = min(st[next_i_1].min_value, st[next_i_2].min_value);
  st[i].gcd_value = __gcd(st[next_i_1].gcd_value, st[next_i_2].gcd_value);
  st[i].freq += (st[next_i_1].gcd_value == st[i].gcd_value) * st[next_i_1].freq;
  st[i].freq += (st[next_i_2].gcd_value == st[i].gcd_value) * st[next_i_2].freq;
}

void update(int update_i, int update_value, int l, int r, int i) {
  if(update_i < l || update_i > r) {
    return;
  }
  if(l == r) {
    st[i] = {update_value, update_value, 1};
    return;
  }

  int mid = (l + r) / 2;
  int next_i_1 = 2 * i + 1, next_i_2 = 2 * i + 2;
  update(update_i, update_value, l, mid, next_i_1), update(update_i, update_value, mid + 1, r, next_i_2);
  st[i].min_value = min(st[next_i_1].min_value, st[next_i_2].min_value);
  st[i].gcd_value = __gcd(st[next_i_1].gcd_value, st[next_i_2].gcd_value);
  st[i].freq = 0;
  st[i].freq += (st[next_i_1].gcd_value == st[i].gcd_value) * st[next_i_1].freq;
  st[i].freq += (st[next_i_2].gcd_value == st[i].gcd_value) * st[next_i_2].freq;
}

node query(int q_l, int q_r, int l, int r, int i) {
  if(r < q_l || l > q_r) {
    return {M1, 0, 0};
  }
  if(l >= q_l && r <= q_r) {
    return st[i];
  }

  int mid = (l + r) / 2;
  int next_i_1 = 2 * i + 1, next_i_2 = 2 * i + 2;
  node ans_1 = query(q_l, q_r, l, mid, next_i_1), ans_2 = query(q_l, q_r, mid + 1, r, next_i_2);
  node ans = {0, 0, 0};
  ans.min_value = min(ans_1.min_value, ans_2.min_value);
  ans.gcd_value = __gcd(ans_1.gcd_value, ans_2.gcd_value);
  ans.freq += (ans_1.gcd_value == ans.gcd_value) * ans_1.freq;
  ans.freq += (ans_2.gcd_value == ans.gcd_value) * ans_2.freq;

  return ans;
} 

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  arr.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  st.resize(4 * N);
  construct(0, N - 1, 0);

  while(M--) {
    char type;
    cin >> type;
    if(type == 'C') {
      int x, v;
      cin >> x >> v;
      x--, arr[x] = v, update(x, v, 0, N - 1, 0);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      node ans = query(l, r, 0, N - 1, 0);
      if(type == 'M') {
        cout << ans.min_value;
      } else if(type == 'G') {
        cout << ans.gcd_value;
      } else {
        cout << ans.freq;
      }
      cout << '\n';
    }
  }

  return 0;
}