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
#define ll long long
using namespace std;

int main () {

  int N,X;
  scanf("%d%d",&N,&X);
  int A[100];
  for (int i=0; i<N; i++) {
    scanf("%d",&A[i]);
  }
  sort(A,A+N);

  int answer_counter=0;
  for (int i=0; i<N-2; i++) {
    for (int j=i+1; j<N-1; j++) {
      for (int k=j+1; k<N; k++) {
        int set[3];
        set[0]=A[i];
        set[1]=A[j];
        set[2]=A[k];
        sort(set,set+3);
        if (set[1]==X) {
          answer_counter++;
        }
      }
    }
  }

  printf("%d\n",answer_counter);

  return 0;

}