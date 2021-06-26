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
  int num_quarters_start;
  int machine_1_count_start;
  int machine_2_count_start;
  int machine_3_count_start;
  scanf("%d",&num_quarters_start);
  scanf("%d",&machine_1_count_start);
  scanf("%d",&machine_2_count_start);
  scanf("%d",&machine_3_count_start);
  int quarter_count=num_quarters_start;
  int machine_1_count=machine_1_count_start+1;
  int machine_2_count=machine_2_count_start+1;
  int machine_3_count=machine_3_count_start+1;
  int play_counter=0;
  while (quarter_count>0) {
    if (machine_1_count%35==0) {
      quarter_count+=29;
      machine_1_count++;
      play_counter++;
    }
    else {
      quarter_count-=1;
      machine_1_count++;
      play_counter++;
    }
    if (quarter_count==0) {
      break;
    }
    if (machine_2_count%100==0) {
      quarter_count+=59;
      machine_2_count++;
      play_counter++;
    }
    else {
      quarter_count-=1;
      machine_2_count++;
      play_counter++;
    }
    if (quarter_count==0) {
      break;
    }
    if (machine_3_count%10==0) {
      quarter_count+=8;
      machine_3_count++;
      play_counter++;
    }
    else {
      quarter_count-=1;
      machine_3_count++;
      play_counter++;
    }
  }
  printf("Martha plays %d times before going broke.",play_counter);
}