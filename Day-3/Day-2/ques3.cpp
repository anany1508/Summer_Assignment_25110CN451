
#include<iostream>
using namespace std;
int main()
{
    int num,pro=1,rem=0;
    cout<<"enter the number ";
    cin>>num;

    while(num>0)
    {
        rem=num%10;
        pro=pro*rem;
        num=num/10;
    }
    cout<<"the product of the digits is "<<pro<<endl;
    return 0;
}