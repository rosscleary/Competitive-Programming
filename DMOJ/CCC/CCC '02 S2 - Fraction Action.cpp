#include <iostream>
using namespace std;
int main () {
    
int num_1;
int num_2;

cin>>num_1;
cin>>num_2;

int whole=num_1/num_2;

int remain=num_1-(whole*num_2);

int div_num;

for (int i=remain; i>=1; i--) {
    
if (remain%i==0 && num_2%i==0) {
    div_num=i;
    break;
}
    
}

if (remain==0)
    cout<<whole<<endl;

else {

    if (whole==0)
        cout<<remain/div_num<<"/"<<num_2/div_num<<endl;
    else
        cout<<whole<<" "<<remain/div_num<<"/"<<num_2/div_num<<endl;

}

return 0;

}