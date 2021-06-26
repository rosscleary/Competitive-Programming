#include <iostream>
#include <algorithm>
using namespace std;

long int max_value(long int n, long int weight_left, long int weight[], long int value[]) {
long int result;

if (weight_left==0 || n==0)
    return 0;
    
if (weight[n-1]>weight_left)
    result=max_value(n-1,weight_left,weight,value);
    
else {

result=max((max_value(n-1,weight_left,weight,value)),(max_value(n-1,weight_left-weight[n-1],weight,value)+value[n-1]));

}

return result;

}

int main () {
    
long int num_items;
long int *value;
long int *weight;
long int max_weight;

cin>>num_items;
cin>>max_weight;

value=new long int[num_items];
weight=new long int[num_items];

for (int i=0; i<=num_items-1; i++) {
cin>>weight[i];
cin>>value[i];
}

long int n=num_items;
long int weight_left=max_weight;

cout<<max_value(n,weight_left,weight,value)<<endl;

return 0;
}