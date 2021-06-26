#include <iostream>
#include <iomanip>
using namespace std;
int main () {

int n;
double *iPtr;
int index;
int counter;
int temp;
double smallest;

cin>>n;

iPtr = new double[n];

for (index=0; index<=n-1; index++)
cin>>iPtr[index];

for (counter=1; counter<=n; counter++){
   	for (index=0; index<=n-2; index++){
   	if (iPtr[index]>iPtr[index+1]){
  	    	temp=iPtr[index];
  	    	iPtr[index]=iPtr[index+1];
  	    	iPtr[index+1]=temp;}
   	}
}

smallest=((iPtr[2]-iPtr[1])/2)+((iPtr[1]-iPtr[0])/2);
for (index=1; index<=n-2; index++){
if (((iPtr[index+1]-iPtr[index])/2)+((iPtr[index]-iPtr[index-1])/2)<smallest){
	smallest=((iPtr[index+1]-iPtr[index])/2)+((iPtr[index]-iPtr[index-1])/2);}
}

std::cout << std::fixed;
std::cout << std::setprecision(1);
std::cout << smallest<<endl;

return 0;
}