#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e9;

struct edge {
  int node_1, node_2, weight;
};

int M;
vector<edge> edges;

bool sort_fun(edge edge_1, edge edge_2) {
  return edge_1.weight < edge_2.weight;
}
vector<int> roots, sizes;
int root(int node) {
  while(node != roots[node]) {
    node = roots[node];
  }
  return node;
}
void merge(int node_1, int node_2) {
  if(sizes[node_1] < sizes[node_2]) {
    swap(node_1, node_2);
  }
  roots[node_2] = node_1, sizes[node_1] += sizes[node_2];
}
int mst() {
  sort(edges.begin(), edges.end(), sort_fun);
  roots.clear(), sizes.clear(), roots.resize(M + 1), sizes.resize(M + 1);
  for(int i = 0; i <= M; i++) {
    roots[i] = i, sizes[i] = 1;
  }
  int edge_cnt = 0, ans = 0;
  for(auto i: edges) {
    int find_1 = root(i.node_1), find_2 = root(i.node_2);
    if(find_1 != find_2) {
      edge_cnt++, ans += i.weight;
      merge(find_1, find_2);
    }
  }

  if(edge_cnt < M - 1) {
    return M1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> M;

  map<set<int>, vector<int>> edge_pens;
  map<set<int>, int> weights;
  for(int i = 1; i <= M; i++) {
    int e_p;
    cin >> e_p;
    vector<int> edge_nums(e_p), edge_weights(e_p);
    for(int i = 0; i < e_p; i++) {
      cin >> edge_nums[i];
    }
    for(int i = 0; i < e_p; i++) {
      cin >> edge_weights[i];
    }
    edge_nums.push_back(edge_nums[0]);
    for(int j = 1; j <= e_p; j++) {
      edge_pens[{edge_nums[j], edge_nums[j - 1]}].push_back(i);
      weights[{edge_nums[j], edge_nums[j - 1]}] = edge_weights[j - 1];
    }
  }

  for(auto i: edge_pens) {
    if(i.second.size() == 2) {
      edges.push_back({i.second[0], i.second[1], weights[i.first]});
    }
  }
  int ans = mst();
  for(auto i: edge_pens) {
    if(i.second.size() == 1) {
      edges.push_back({0, i.second[0], weights[i.first]});
    }
  }
  ans = min(ans, mst());

  cout << ans << '\n';

  return 0;
}