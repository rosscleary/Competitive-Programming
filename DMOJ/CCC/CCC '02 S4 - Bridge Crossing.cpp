#include <iostream> 
#include <string>
using namespace std;

int mem[101][2]={0};
int names_array[1000000]={0};

int min_time(int max_people, int num_of_people, int spot_in_line, int speeds[]) {

if (mem[spot_in_line][0]!=0) {
    return mem[spot_in_line][0];
    names_array[spot_in_line]=mem[spot_in_line][1];
}

else {

if (spot_in_line>num_of_people) {
    mem[spot_in_line][0]=0;
    return 0;
}
    
else {
if (num_of_people-spot_in_line<max_people) {
int temp_max=num_of_people-spot_in_line+1;

int smallest=1000000;
int group_size=0;
for (int i=1; i<=temp_max; i++){
int largest=0;
    for (int ii=spot_in_line; ii<=spot_in_line + (i-1); ii++){
    if (speeds[ii-1]>largest)
        largest=speeds[ii-1];
    }

if (min_time(max_people, num_of_people, spot_in_line+i,speeds) + largest<smallest) {
    smallest=min_time(max_people, num_of_people, spot_in_line+i,speeds) + largest;
    group_size=i;
}

}    

mem[spot_in_line][0]=smallest;
mem[spot_in_line][1]=group_size;
names_array[spot_in_line]=group_size;
return smallest;
      
}

else {   
int smallest=1000000;
int group_size=0;
for (int i=1; i<=max_people; i++){
int largest=0;
    for (int ii=spot_in_line; ii<=spot_in_line + (i-1); ii++){
    if (speeds[ii-1]>largest)
        largest=speeds[ii-1];
    }

if (min_time(max_people, num_of_people, spot_in_line+i,speeds) + largest<smallest) {
    smallest=min_time(max_people, num_of_people, spot_in_line+i,speeds) + largest;
    group_size=i;
}

}    

mem[spot_in_line][0]=smallest;
mem[spot_in_line][1]=group_size;
names_array[spot_in_line]=group_size;
return smallest;
      
}  
    
} 

}
  
}

int main () {
int max_people;
int num_of_people;
string *names;
int *speeds;

cin>>max_people;
cin>>num_of_people;

speeds=new int[num_of_people];
names=new string[num_of_people];

for (int i=0; i<=num_of_people-1; i++){
cin>>names[i];
cin>>speeds[i];
}

int spot_in_line=1;

cout<<"Total Time: "<<min_time(max_people, num_of_people, spot_in_line, speeds)<<endl;

int i=1;
while (names_array[i]!=0) {
    
    for (int ii=i; ii<=i+(names_array[i]-1); ii++)
    cout<<names[ii-1]<<" ";
    
cout<<endl; 
i=i+names_array[i];
}
    
return 0;
}