#include<iostream>
using namespace std;
int main()
{
    int num1,num2,num=0;
    cout<<"enter the numbers : ";
    cin>>num1>>num2;

    // if(num<0)
    // {
    //     cout <<"invalid input"
    // }
    for(int i=1;i<=num1;i++)
    {
        if(num1%i==0)
        {
            for(int j=1;j<=num2;j++)
            {
                if(num2%j==0)
                {
                    if(i==j)
                    {
                        if(num<i)
                        {
                            num=i;
                        }
                    }
                }
            }
        }
    }
    cout<<"the gcd of the 2 numbers given is "<<num<<endl;
    return 0;
}