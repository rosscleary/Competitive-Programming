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

  int N, H;
  sf("%d%d", &N, &H);

  pair<char,int> game_moves[2010];

  for (int i = 1; i <= 2 * N - 1; i += 2)
  {
    char type;
    int d;
    cin >> type;
    sf("%d", &d);
    game_moves[i] = mp(type, d);
  }

  for (int i = 2; i <= 2 * N; i += 2)
  {
    char type;
    int d;
    cin >> type;
    sf("%d", &d);
    game_moves[i] = mp(type, d);
  }

  int charlie_health = H;
  int bot_health = H;

  for (int i = 1; i <= 2 * N; i++)
  {

    if (i % 2 == 1)
    {
      if (i != 1)
      {
        if (game_moves[i].f == 'A' && game_moves[i-1].f != 'D') bot_health -= game_moves[i].s;
        if (game_moves[i].f == 'D' && game_moves[i+1].f != 'A') charlie_health -= game_moves[i].s;
      }
      if (i == 1)
      {
        if (game_moves[i].f == 'A') bot_health -= game_moves[i].s;
        if (game_moves[i].f == 'D' && game_moves[i+1].f != 'A') charlie_health -= game_moves[i].s;
      }
    }

    if (charlie_health <= 0)
    {
      pf("DEFEAT\n");
      return 0;
    }
    if (bot_health <= 0)
    {
      pf("VICTORY\n");
      return 0;
    }

    if (i % 2 == 0)
    {
      if (i != 2 * N)
      {
        if (game_moves[i].f == 'A' && game_moves[i-1].f != 'D') charlie_health -= game_moves[i].s;
        if (game_moves[i].f == 'D' && game_moves[i+1].f != 'A') bot_health -= game_moves[i].s;
      }
      if (i == 2 * N)
      {
        if (game_moves[i].f == 'A' && game_moves[i-1].f != 'D') charlie_health -= game_moves[i].s;
        if (game_moves[i].f == 'D') bot_health -= game_moves[i].s;
      }
    }

    if (charlie_health <= 0)
    {
      pf("DEFEAT\n");
      return 0;
    }
    if (bot_health <= 0)
    {
      pf("VICTORY\n");
      return 0;
    }

  }

  pf("TIE\n");

  return 0;

}