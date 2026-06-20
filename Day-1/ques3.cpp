#include<iostream>
using namespace std;
int main()
{
    int num,pro=1;
    cout<<"enter a number ";
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        pro=pro*i;
    }
    cout<<"the factorial of "<<num<<" is "<<pro<<endl;
    return 0;
}