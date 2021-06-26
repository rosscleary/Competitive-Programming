#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <climits>
using namespace std;

int main () {

  int N,B;
  cin>>N>>B;
  int A[100001];
  int b_location;
  for (int i=1; i<=N; i++) {
    cin>>A[i];
    if (A[i]==B) {
      b_location=i;
    }
  }

  int prefix_differences[100001];
  int suffix_differences[100001];
  prefix_differences[b_location]=0;
  for (int i=b_location-1; i>=1; i--) {
    if (A[i]>B) {
      prefix_differences[i]=prefix_differences[i+1]+1;
    }
    else {
      prefix_differences[i]=prefix_differences[i+1]-1;
    }
  }
  suffix_differences[b_location]=0;
  for (int i=b_location+1; i<=N; i++) {
    if (A[i]>B) {
      suffix_differences[i]=suffix_differences[i-1]+1;
    }
    else {
      suffix_differences[i]=suffix_differences[i-1]-1;
    }
  }

  map<int,int> after_freq;
  for (int i=b_location; i<=N; i++) {
    after_freq[suffix_differences[i]]++;
  }

  long long num_sequences=0;
  for (int i=b_location; i>0; i--) {
    num_sequences+=after_freq[-1*prefix_differences[i]];
  }
  cout<<num_sequences<<endl;

  return 0;

}