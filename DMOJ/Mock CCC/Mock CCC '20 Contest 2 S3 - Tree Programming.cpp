#include <bits/stdc++.h>
using namespace std;

const int M1 = 128;

struct edge {
  int u, v, k;
};

vector<vector<int>> heads, sizes;

int head(int mask, int node) {
  if(node == heads[mask][node]) {
    return node;
  }
  return heads[mask][node] = head(mask, heads[mask][node]);
}

void merge(int mask, int node_1, int node_2) {
  int node_1_head = head(mask, node_1), node_2_head = head(mask, node_2);
  if(sizes[mask][node_1_head] > sizes[mask][node_2_head]) {
    swap(node_1, node_2);
  }
  heads[mask][node_1_head] = heads[mask][node_2_head];
  sizes[mask][node_2_head] += sizes[mask][node_1_head];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;
  vector<edge> edges(M);
  for(int i = 0; i < M; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].k;
  }

  heads.resize(M1 + 1, vector<int>(N + 1)), sizes.resize(M1 + 1, vector<int>(N + 1));
  for(int i = 0; i <= M1; i++) {
    for(int j = 1; j <= N; j++) {
      heads[i][j] = j, sizes[i][j] = 1;
    }
    for(int j = 0; j < M; j++) {
      if((i | edges[j].k) == i) {
        merge(i, edges[j].u, edges[j].v);
      }
    }
  }

  while(Q--) {
    int a_j, b_j;
    cin >> a_j >> b_j;
    for(int i = 0; i <= M1; i++) {
      if(head(i, a_j) == head(i, b_j)) {
        cout << i << '\n';
        break;
      }
    }
  }

  return 0;
}