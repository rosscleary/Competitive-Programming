#include <bits/stdc++.h>
using namespace std;

vector<int> next_node;
vector<int> sizes;

int find(int node) {
  while(next_node[node] != node) {
    node = next_node[node];
  }
  return node;
}

void merge(int node_1, int node_2) {
  if(sizes[node_1] < sizes[node_2]) {
    swap(node_1, node_2);
  }
  sizes[node_1] += sizes[node_2];
  next_node[node_2] = node_1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  next_node.resize(N + 1), sizes.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    next_node[i] = i;
    sizes[i] = 1;
  }

  int M;
  cin >> M;
  while(M--) {
    int K_i;
    cin >> K_i;
    vector<int> class_members(K_i);
    for(int i = 0; i < K_i; i++) {
      cin >> class_members[i];
    }
    for(int i = 1; i < K_i; i++) {
      int find_1 = find(class_members[i]), find_2 = find(class_members[i - 1]);
      if(find_1 != find_2) {
        merge(find_1, find_2);
      }
    }
  }

  int find_1 = find(1);
  cout << sizes[find_1] << '\n';
  for(int i = 1; i <= N; i++) {
    if(find(i) == find_1) {
      cout << i << ' ';
    }
  }
  cout << '\n';

  return 0;
}