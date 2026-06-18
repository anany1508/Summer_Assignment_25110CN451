#include<iostream>
using namespace std;
int main()
{
    int num,pro;
    cout<<"enter a number";
    cin>>num;
    
    for(int i=1;i<=10;i++)
    {
        pro=i*num;
        cout<<pro<<endl;
    }
    return 0;
}
