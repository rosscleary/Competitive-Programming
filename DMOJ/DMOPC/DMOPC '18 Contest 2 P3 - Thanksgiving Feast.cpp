#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int Ull;
typedef pair<int,int> pi;
typedef pair<long long int,long long int> pll;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<pair<int,int> > vpi;
typedef vector<pair<long long int,long long int> > vpll;

typedef pair<double,double> pd;
typedef vector<double> vd;
typedef vector<pair<double,double> > vpd;

typedef pair<char,char> pch;
typedef vector<char> vch;
typedef vector<pair<char,char> > vpch;

typedef pair<string,string> pstr;
typedef vector<string> str;
typedef vector<pair<string,string> > vpstr;

typedef map<int,vector<int> > mivi;
typedef map<long long int,vector<long long int> > mllvll;
typedef map<int,vector<pair<int,int> > > mivpi;
typedef map<long long int,vector<pair<long long int,long long int> > > mllvpll;

typedef map<char,int> mchi;
typedef map<char,long long int> mchll;
typedef map<char,bool> mchb;
typedef map<char,char> mchch;
typedef map<char,string> mchstr;
typedef map<char,pair<int,int> > mchpi;
typedef map<char,pair<long long int,long long int> > mchpll;
typedef map<char,vector<char> > mchvch;

typedef map<string,int> mstri;
typedef map<string,long long int> mstrll;
typedef map<string,bool> mstrb;
typedef map<string,char> mstrch;
typedef map<string,string> mstrstr;
typedef map<string,pair<int,int> > mstrpi;
typedef map<string,pair<long long int,long long int> > mstrpll;
typedef map<string,vector<string> > mstrvstr;

typedef list<int> li;
typedef list<long long int> lll;
typedef list<pair<int,int> > lpi;
typedef list<pair<long long int,long long int> > lpll;

typedef list<char> lch;

typedef list<string> lstr;

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define l length
#define era erase
#define sub substr
#define app append
#define sz size
#define emp empty

const int mod=1000000007;
const int I_M=INT_MAX;
const int I_MI=INT_MIN;

const string alph_l("abcdefghijklmnopqrstuvwxyz");
const string alph_c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const string digits("0123456789");

// ---------- END OF TEMPLATE ----------

int N, M, K, A, B;
vector<int> gift_builds;
bool is_gift_build[200005] = {false};

mivi graph;

int dists_start[200005] = {0};
int dists_end[200005];


void bfs (int start, bool from_start)

{

  int gift_build_counter = 0;

  li q;
  bool visited[200005] = {false};
  
  q.pb(start);

  while (!q.emp())
  {
    int curr = q.front();
    q.pop_front();
    for (int i = 0; i < graph[curr].sz(); i++)
    {
      if (!visited[graph[curr][i]])
      {
        if (is_gift_build[graph[curr][i]]) gift_build_counter++;
        (from_start) ? dists_start[graph[curr][i]] = dists_start[curr] + 1 : dists_end[graph[curr][i]] = dists_end[curr] + 1;
        if (gift_build_counter == K) return;
        visited[graph[curr][i]] = true;
        q.pb(graph[curr][i]);
      }
    }
  }

}

int main ()

{

  sf("%d%d%d%d%d", &N, &M, &K, &A, &B);

  for (int i = 0, s; i < K; i++)
  {
    sf("%d", &s);
    gift_builds.pb(s);
    is_gift_build[s] = true;
  }

  for (int i = 0, a_i, b_i; i < M; i++)
  { 
    sf("%d%d", &a_i, &b_i);
    graph[a_i].pb(b_i);
    graph[b_i].pb(a_i);
  } 

  bfs(A, true);
  bfs(B, false);

  int answer = I_M;

  for (int i = 0; i < gift_builds.sz(); i++)
  {
    answer = min(answer, dists_start[gift_builds[i]] + dists_end[gift_builds[i]]);
  }

  pf("%d\n", answer);

  return 0;

}