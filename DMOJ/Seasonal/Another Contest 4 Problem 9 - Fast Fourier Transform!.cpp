//fast Fourier
#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

vector<int> f(int n){
  vector <int> v;
  long long int prod,p,r;
  int j=1;
  v.push_back(1);
  for (int i=1;i <n;i++){
    j=1;
    p=(j*v[i-1])%998244353;
    r=(j*(i+1))%998244353;
    //cout<<p<<" "<<r<<endl;
    prod=(p*r)%998244353;
    v.push_back((int)prod);
  }
  return v;

}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  vector<int> x;
  long long int *b;
  cin>>n;
  x=f(n);
  for(int i=0;i<x.size();i++){
    cout<<x[i]<<endl;
}
  
    return 0;
}