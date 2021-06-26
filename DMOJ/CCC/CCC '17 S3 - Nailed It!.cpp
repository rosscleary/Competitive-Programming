#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int main () {
  int n;
  scanf("%d",&n);
  int number_frequencies[2001]={0};
  int number;
  for (int i=1; i<=n; i++) {
    scanf("%d",&number);
    number_frequencies[number]++;
  }
  int board_lengths[4001]={0};
  for (int sum=2; sum<=4000; sum++) {
    for (int choice_1=1; choice_1<=sum/2; choice_1++) {
      if (choice_1<=2000 && sum-choice_1<=2000) {
        if (choice_1==sum-choice_1) {
          board_lengths[sum]+=number_frequencies[choice_1]/2;
        }
        else {
          board_lengths[sum]+=min(number_frequencies[choice_1],number_frequencies[sum-choice_1]);
        }
      }
    }
  }
  sort(board_lengths,board_lengths+4001);
  int best_length=board_lengths[4000];
  int best_length_frequency=1;
  for (int i=3999; i>=1; i--) {
    if (board_lengths[i]!=board_lengths[i+1]) {
      break;
    }
    best_length_frequency++;
  }
  printf("%d ",best_length);
  printf("%d",best_length_frequency);
}