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

int main ()

{

  int N;
  sf("%d", &N);

  pi points[100];

  for (int i = 0, x, y; i < N; i++)
  {
    sf("%d%d", &x, &y);
    points[i] = mp(x, y);
  }

  int answer = I_M;

  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      int new_size = pow(max(abs(points[i].f - points[j].f), abs(points[i].s - points[j].s)), 2);
      answer = min(answer, new_size);
    }
  }

  pf("%d\n", answer);

  return 0;

}