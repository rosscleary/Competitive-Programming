#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int Ull;

typedef pair<int,int> pi;
typedef pair<long long int,long long int> pll;

typedef string str;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<pair<int,int> > vpi;
typedef vector<pair<long long int,long long int> > vpll;

typedef map<int,vector<int> > mivi;
typedef map<long long int,vector<long long int> > mllvll;
typedef map<int,vector<pair<int,int> > > mivpi;
typedef map<long long int,vector<pair<long long int,long long int> > > mllvpll;

typedef map<char,int> mci;
typedef map<char,long long int> mcll;
typedef map<char,bool> mcb;
typedef map<char,pair<int,int> > mcpi;
typedef map<char,pair<long long int,long long int> > mcpll;

typedef map<string,int> mstri;
typedef map<string,long long int> mstrll;
typedef map<string,bool> mstrb;
typedef map<string,pair<int,int> > mstrpi;
typedef map<string,pair<long long int,long long int> > mstrpll;

typedef list<int> li;
typedef list<long long int> lll;
typedef list<pair<int,int> > lpi;
typedef list<pair<long long int,long long int> > lpll;

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define l length
#define e erase
#define sub substr
#define app append

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
  sf("%d",&N);

  int pink_counter=0;

  while (N--)
  {
    int R,G,B;
    sf("%d%d%d",&R,&G,&B);
    if (R>=240 && G<=200 && B>=95 && B<=220)
    {
      pink_counter++;
    }
  }

  pf("%d\n",pink_counter);

  return 0;

}