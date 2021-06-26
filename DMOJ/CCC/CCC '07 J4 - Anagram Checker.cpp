#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int Ull;

typedef pair<int,int> pi;
typedef pair<long long int,long long int> pll;

typedef char ch;
typedef string str;

typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<pair<int,int> > vpi;
typedef vector<pair<long long int,long long int> > vpll;

typedef vector<char> vc;
typedef vector<string> vstr;

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

  str s_1;
  str s_2;

  getline(cin,s_1);
  getline(cin,s_2);

  mci char_freq_1;

  for (int i=0; i<s_1.l(); i++)
  {
    if (s_1[i]!=' ') {
      char_freq_1[s_1[i]]++;
    }
  }

  mci char_freq_2;
  vc char_occured;

  for (int i=0; i<s_2.l(); i++)
  {
    if (s_2[i]!=' ') {
      if (char_freq_1[s_2[i]]==0)
      {
        pf("Is not an anagram.\n");
        return 0;
      }
      char_occured.pb(s_2[i]);
      char_freq_2[s_2[i]]++;
    }
  }

  for (int i=0; i<char_occured.size(); i++)
  {
    if (char_freq_1[char_occured[i]]!=char_freq_2[char_occured[i]])
    {
      pf("Is not an anagram.\n");
      return 0;
    }
  }

  pf("Is an anagram.\n");

  return 0;

}