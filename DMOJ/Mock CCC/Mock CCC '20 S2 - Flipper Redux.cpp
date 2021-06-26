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

int N;
int grid[2005][2005];

int row_state (int row) {

    for (int i=2; i<=N; i++) {
        if (grid[row][i]!=grid[row][i-1]) {
            return -1;
        }
    }

    if (grid[row][N]==0) {
        return 0;
    }

    return 1;

}

int main () {

    scanf("%d",&N);

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            scanf("%d",&grid[i][j]);
        }
    }

    vector<int> col_changes;
    for (int i=1; i<=N; i++) {
        if (grid[1][i]==1) {
            col_changes.push_back(i);
            for (int j=2; j<=N; j++) {
                if (grid[j][i]==1) {
                    grid[j][i]=0;
                }
                else {
                    grid[j][i]=1;
                }
            }
        }
    }

    vector<int> row_changes;
    for (int i=2; i<=N; i++) {
        int row_state_sub=row_state(i);
        if (row_state_sub==-1) {
            printf("-1\n");
            return 0;
        }
        if (row_state_sub==1) {
            row_changes.push_back(i);
        }
    }

    int row_change_size=row_changes.size();
    int col_change_size=col_changes.size();

    printf("%d\n",row_change_size+col_change_size);

    for (int i=0; i<col_change_size; i++) {
        printf("C %d\n",col_changes[i]);
    }
    for (int i=0; i<row_change_size; i++) {
        printf("R %d\n",row_changes[i]);
    }

    return 0;

}