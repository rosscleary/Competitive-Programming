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

    int N;
    scanf("%d",&N);

    int sequence[105];
    for (int i=1; i<=N; i++) {
        scanf("%d",&sequence[i]);
    }

    sort(sequence+1,sequence+N+1);

    for (int i=1; i<=N; i++) {
        printf("%d ",sequence[i]);
    }
    printf("\n");

    return 0;

}