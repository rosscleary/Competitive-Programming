#include <iostream>
#include <string>
using namespace std;
int main () {
    
string day;

cin>>day;

if (day=="Sunday")
    cout<<"Monday"<<endl;
    
if (day=="Monday")
    cout<<"Tuesday"<<endl;
    
if (day=="Tuesday")
    cout<<"Wednesday"<<endl;
    
if (day=="Wednesday")
    cout<<"Thursday"<<endl;
    
if (day=="Thursday")
    cout<<"Friday"<<endl;
    
if (day=="Friday")
    cout<<"Saturday"<<endl;
    
if (day=="Saturday")
    cout<<"Sunday"<<endl;

return 0;
}