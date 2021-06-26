#include <iostream>
using namespace std;
int main () {

int r;
int c;
int k;
int **cat;
int **mem;

cin>>r;
cin>>c;
cin>>k;

cat=new int*[k];

for (int a=0; a<=k-1; a++)
cat[a]=new int[2];

for (int a=0; a<=k-1; a++){
cin>>cat[a][0];
cin>>cat[a][1];
}

mem=new int*[r+1];

for (int a=0; a<=r; a++)
mem[a]=new int[c+1];

for (int a=0; a<=r; a++){
    for (int b=0; b<=c; b++)
    mem[a][b]=0;
}

for (int a=0; a<=k-1; a++)
mem[(cat[a][0])][(cat[a][1])]=-1;

mem[1][1]=1;
for (int a=1; a<=r; a++){
    for (int b=1; b<=c; b++){
    if (mem[a][b]!=-1 && mem[a-1][b]!=-1)
        mem[a][b]=mem[a][b] + mem[a-1][b];
    
    if (mem[a][b]!=-1 && mem[a][b-1]!=-1)
        mem[a][b]=mem[a][b] + mem[a][b-1];
    }
}

cout<<mem[r][c]<<endl;

return 0;
}