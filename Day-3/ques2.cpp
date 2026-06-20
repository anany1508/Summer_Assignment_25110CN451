#include<iostream>
using namespace std;
int main()
{
    int num,count;
    cout<<"enter the number till which we have to find prime numbers ";
    cin>>num;

    if(num<2)
    {
        cout<<"invalid input";
    }
    else{
    for(int i=2;i<=num;i++)
    {
        count=0;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                count++;
                break;
            }
        }
        if(count ==0)
        {
            cout<<i<<endl;
        }
    }
    }
    return 0;
}