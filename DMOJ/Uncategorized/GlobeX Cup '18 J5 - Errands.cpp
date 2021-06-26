#include <bits/stdc++.h>
using namespace std;
int dist[100001];
vector<int> houses[100001];
int n, m, q, c, a, b;
void BFS(int st){
  bool visit[100001]={false};
  queue <int> q;
  visit[st]=true;
  dist[st]=0;
  q.push(st);
  while (!q.empty()){
    int cur=q.front();
    q.pop();
    for (int i=0; i<houses[cur].size(); i++){
      if (visit[houses[cur][i]]==false){
        visit[houses[cur][i]]=true;
        dist[houses[cur][i]]=dist[cur]+1;
        q.push(houses[cur][i]);
      }
    }
  }
}
int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>q>>c;
  memset(dist, -1, sizeof dist);
  while (m--){
    cin>>a>>b;
    houses[a].push_back(b);
    houses[b].push_back(a);
  }
  BFS(c);
  while (q--){
    cin>>a>>b;
    if (dist[a]==-1||dist[b]==-1)
    cout<<"This is a scam!"<<endl;
    else
    cout<<dist[a]+dist[b]<<endl;
  }
return 0;}