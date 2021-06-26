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

  int p,g,r,o,total;
  scanf("%d%d%d%d%d",&p,&g,&r,&o,&total);

  int combo_counter=0;
  int min_tickets=INT_MAX;
  for (int i=0; i<=total/p; i++) {
    for (int j=0; j<=total/g; j++) {
      for (int k=0; k<=total/r; k++) {
        for (int l=0; l<=total/o; l++) {
          if (p*i+g*j+r*k+l*o==total) {
            printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n",i,j,k,l);
            min_tickets=min(min_tickets,i+j+k+l);
            combo_counter++;
          }
        }
      }
    }
  }

  printf("Total combinations is %d.\n",combo_counter);
  printf("Minimum number of tickets to print is %d.\n",min_tickets);

  return 0;

}