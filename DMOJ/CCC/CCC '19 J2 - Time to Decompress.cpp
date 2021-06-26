#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int Ull;

typedef double d;

typedef char ch;
typedef string str;

typedef pair<int,int> pi;
typedef pair<long long int,long long int> pll;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<pair<int,int> > vpi;
typedef vector<pair<long long int,long long int> > vpll;

typedef vector<double> vd;
typedef vector<pair<double,double> > vpd;

typedef vector<char> vch;
typedef vector<string> vstr;

typedef map<int,vector<int> > mivi;
typedef map<long long int,vector<long long int> > mllvll;
typedef map<int,vector<pair<int,int> > > mivpi;
typedef map<long long int,vector<pair<long long int,long long int> > > mllvpll;

typedef map<char,int> mchi;
typedef map<char,long long int> mchll;
typedef map<char,bool> mchb;
typedef map<char,pair<int,int> > mchpi;
typedef map<char,pair<long long int,long long int> > mchpll;

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

  int L;
  scanf("%d",&L);

  while (L--)
  {
    int amount;
    ch c;
    sf("%d",&amount);
    cin>>c;
    while (amount--)
    {
      cout<<c;
    }
    pf("\n");
  }

  return 0;

}