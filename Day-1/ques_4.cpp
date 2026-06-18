#include<iostream>
using namespace std;
int main()
{
    int num,count=0;
    cout<<"enter a number";
    cin>>num;
    int num_org=num;
    while(num>0)
    {
        num=num/10;
        count++;

    }
    cout<<"the number of digits in "<<num_org<<" is "<<count<<endl;
    return 0;
}