#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e6 + 1, M2 = 262144;

vector<int> arr;
vector<int> st;

int construct_st(int l, int r, int i) {
  if(l == r) {
    return st[i] = arr[l];
  }
  int mid = (l + r) / 2;
  st[i] = min(construct_st(l, mid, 2 * i + 1), construct_st(mid + 1, r, 2 * i + 2));
  return st[i];
}

int q_l, q_r;
int query(int l, int r, int i) {
  if(l >= q_l && r <= q_r) {
    return st[i];
  }
  if(r < q_l || l > q_r) {
    return M1;
  }
  int mid = (l + r) / 2;
  return min(query(l, mid, 2 * i + 1), query(mid + 1, r, 2 * i + 2));
}

int update_i, update_value;
void update(int l, int r, int i) {
  if(l == r) {
    st[i] = update_value;
    return;
  }
  int mid = (l + r) / 2;
  if(update_i <= mid) {
    update(l, mid, 2 * i + 1);
  } else {
    update(mid + 1, r, 2 * i + 2);
  }
  st[i] = min(st[2 * i + 1], st[2 * i + 2]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  arr.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  st.resize(M1);
  construct_st(0, N - 1, 0);

  while(M--) {
    char type;
    cin >> type;
    if(type == 'M') {
      cin >> update_i >> update_value;
      arr[update_i] = update_value;
      update(0, N - 1, 0);
    } else {
      cin >> q_l >> q_r;
      cout << query(0, N - 1, 0) << '\n';
    }
  }

  return 0;
}