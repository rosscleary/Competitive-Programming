#include <bits/stdc++.h>
using namespace std;

double dist(pair<double, double> point_1, pair<double, double> point_2) {
  return sqrt(pow(point_1.first - point_2.first, 2) + pow(point_1.second - point_2.second, 2));
}

vector<int> heads, sizes;

int head(int node) {
  while(heads[node] != node) {
    node = heads[node];
  }
  return node;
}

void merge(int node_1, int node_2) {
  if(sizes[node_1] > sizes[node_2]) {
    swap(node_1, node_2);
  }
  heads[node_1] = heads[node_2];
  sizes[node_2] += sizes[node_1];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<pair<double, double>> buildings(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> buildings[i].first >> buildings[i].second;
  }
  int M;
  cin >> M;
  set<pair<int, int>> existing_buildings;
  heads.resize(N + 1), sizes.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    heads[i] = i, sizes[i] = 1;
  }
  while(M--) {
    int building_1, building_2;
    cin >> building_1 >> building_2;
    if(building_1 > building_2) {
      swap(building_1, building_2);
    }
    existing_buildings.insert({building_1, building_2});
    merge(head(building_1), head(building_2));
  }

  vector<pair<double, pair<int, int>>> edges;
  for(int i = 1; i < N; i++) {
    for(int j = i + 1; j <= N; j++) {
      if(!existing_buildings.count({i, j})) {
        edges.push_back({dist(buildings[i], buildings[j]), {i, j}});
      }
    }
  }

  sort(edges.begin(), edges.end());
  double ans_1 = 0;
  vector<pair<int, int>> ans_2;
  for(int i = 0; i < edges.size(); i++) {
    int head_1 = head(edges[i].second.first), head_2 = head(edges[i].second.second);
    if(head_1 != head_2) {
      ans_1 += edges[i].first, ans_2.push_back({edges[i].second.first, edges[i].second.second}), merge(head_1, head_2);
    }
  }

  cout << setprecision(2) << fixed << ans_1 << '\n';
  for(auto i: ans_2) {
    cout << i.first << ' ' << i.second << '\n';
  }

  return 0;
}