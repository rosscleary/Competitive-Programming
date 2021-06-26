#include <iostream>
#include <algorithm>
using namespace std;

int mem[3005][105][105][2];
bool mem_if[3005][105][105][2];

int most_sugar(int n, int m, int pies1[], int pies2[], int first_pies, int use, int buffer, int last) {

if (mem_if[first_pies][use][buffer][last]==true)
    return mem[first_pies][use][buffer][last];

if (first_pies>n-1 && buffer<=use)
    return 0;

int result_1=0;
int result_2=0;
int result_3=0;
int result_4=0;
int best=0;

if (last==0) {

if (first_pies<=n-1)    
    result_1=pies1[first_pies]+most_sugar(n,m,pies1,pies2,first_pies+1,use,buffer,1);

if (buffer<=use)
    result_2=pies2[use]+most_sugar(n,m,pies1,pies2,first_pies,use-1,buffer,1);

if (first_pies<=n-1)
    result_3=most_sugar(n,m,pies1,pies2,first_pies+1,use,buffer,0);

if (buffer<=use)
    result_4=most_sugar(n,m,pies1,pies2,first_pies,use,buffer+1,0); 

best=max(max(result_1,result_2),max(result_3,result_4));
    
}

else {

if (first_pies<=n-1)    
    result_1=most_sugar(n,m,pies1,pies2,first_pies+1,use,buffer,0);

if (buffer<=use)
    result_2=most_sugar(n,m,pies1,pies2,first_pies,use,buffer+1,0);  

best=max(result_1,result_2);
      
}

mem_if[first_pies][use][buffer][last]=true;
mem[first_pies][use][buffer][last]=best;
return best;  
    
}

int main () {
    
int n;

cin>>n;

int *pies1=new int[n];

for (int i=0; i<=n-1; i++)
cin>>pies1[i];

int m;

cin>>m;

int *pies2=new int[m];

for (int i=0; i<=m-1; i++)
cin>>pies2[i];

sort(pies2,pies2+m);

int first_pies=0;

int use=m-1;
int buffer=0;

int last=0;

cout<<most_sugar(n,m,pies1,pies2,first_pies,use,buffer,last)<<endl;

return 0;

}