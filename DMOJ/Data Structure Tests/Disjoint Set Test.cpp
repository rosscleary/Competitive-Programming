#include <bits/stdc++.h>
using namespace std;

vector<int> next_node;
vector<int> sizes;

int find_root(int node) {
  while(next_node[node] != node) {
    node = next_node[node];
  }
  return node;
}

void merge(int node_1, int node_2) {
  if(sizes[node_1] < sizes[node_2]) {
    swap(node_1, node_2);
  }
  next_node[node_2] = node_1;
  sizes[node_1] += sizes[node_2];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  next_node.resize(N + 1), sizes.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    next_node[i] = i, sizes[i] = 1;
  }

  int M;
  cin >> M;
  vector<int> ans;
  for(int i = 1; i <= M; i++) {
    int u_i, v_i;
    cin >> u_i >> v_i;
    int root_1 = find_root(u_i), root_2 = find_root(v_i);
    if(root_1 != root_2) {
      ans.push_back(i);
      merge(root_1, root_2);
    }
  }

  if(ans.size() < N - 1) {
    cout << "Disconnected Graph\n";
    return 0;
  } 
  for(int i: ans) {
    cout << i << '\n';
  }

  return 0;
}