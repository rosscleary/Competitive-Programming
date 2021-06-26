#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e9;

int N;
vector<vector<pair<int, int>>> adj;

vector<bool> seen_all;
vector<int> curr_tree_nodes;

int longest_diam = -1;

unordered_map<int, int> bfs(int start) {
  queue<int> q;
  unordered_map<int, bool> seen;
  unordered_map<int, int> dist;
  q.push(start), seen[start] = true;
  dist[start] = 0;
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    if(!seen_all[curr]) {
      seen_all[curr] = true;
      curr_tree_nodes.push_back(curr);
    }
    for(pair<int, int> i: adj[curr]) {
      if(!seen[i.first]) {
        seen[i.first] = true, q.push(i.first), dist[i.first] = dist[curr] + i.second;
      }
    }
  }

  return dist;
}

int longest(unordered_map<int, int> dist) {
  int longest_value = -1, longest_i;
  for(int i: curr_tree_nodes) {
    if(dist[i] > longest_value) {
      longest_value = dist[i], longest_i = i;
    }
  }

  return longest_i;
}

int radius(int start) {
  int end_1 = longest(bfs(start));
  int end_2 = longest(bfs(end_1));
  unordered_map<int, int> bfs_1 = bfs(end_1), bfs_2 = bfs(end_2);

  int ans = M1;
  for(int i: curr_tree_nodes) {
    ans = min(ans, max(bfs_1[i], bfs_2[i]));
  }

  longest_diam = max(longest_diam, bfs_1[end_2]);

  curr_tree_nodes.clear();
  return ans;
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
  adj.resize(N);
  for(int i = 0; i < M; i++) {
    adj[A[i]].push_back({B[i], T[i]}), adj[B[i]].push_back({A[i], T[i]});
  }

  seen_all.resize(N);
  vector<int> radii;
  for(int i = 0; i < N; i++) {
    if(!seen_all[i]) {
      radii.push_back(radius(i));
    }
  }

  sort(radii.begin(), radii.end());
  int size = radii.size();
  int ans;
  if(size == 1) {
    ans = radii[0];
  } else if(size == 2) {
    ans = radii[0] + radii[1] + L;
  } else {
    ans = max(radii[size - 1] + radii[size - 2] + L, radii[size - 2] + radii[size - 3] + 2 * L);
  }
  ans = max(ans, longest_diam);
  
  return ans;
}