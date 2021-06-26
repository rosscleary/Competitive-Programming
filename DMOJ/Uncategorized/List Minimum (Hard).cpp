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
  int size;
  scanf("%d",&size);
  int numbers[100000];
  for (int i=0; i<size; i++) {
    scanf("%d",&numbers[i]);
  }
  sort(numbers,numbers+size);
  for (int i=0; i<size; i++) {
    printf("%d\n",numbers[i]);

  }
}