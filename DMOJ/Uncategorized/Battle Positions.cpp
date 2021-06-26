#include <iostream>
using namespace std;
int main () {

int num_stations;
int num_req_troops;
int num_waves;
int **changes;
int *stations;

cin>>num_stations;
cin>>num_req_troops;
cin>>num_waves;

changes = new int*[num_waves];

for (int i=0; i<=num_waves-1; i++)
changes[i]=new int[3];

for (int i=0; i<=num_waves-1; i++){
	for (int ii=0; ii<=2; ii++)
	cin>>changes[i][ii];
}

stations=new int[num_stations];

int *difference_array;

difference_array=new int[num_stations+1];

for (int i=0; i<=num_waves-1; i++){
difference_array[changes[i][0]]=difference_array[changes[i][0]]+changes[i][2];
difference_array[changes[i][1]+1]=difference_array[changes[i][1]+1]-changes[i][2];
}

for (int i=0; i<=num_waves; i++) { 

if (i==0) 
    stations[i]=difference_array[i]; 
  
else
    stations[i]=difference_array[i]+stations[i-1];

}

int counter=0;

for (int i=0; i<=num_stations-1; i++){
	if (stations[i]<num_req_troops)
	counter=counter+1;
}

cout<<counter<<endl;

return 0;
}