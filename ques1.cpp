#include<iostream>
using namespace std;
int main()
{
    int num,count=0;
    cout<<"enter the numer to check whether prime or not";
    cin>>num;

    if(num==2)
    {
        cout<<"prime number";
    }
    else{
    if(num<=1)
    {
        cout<<"neither prime nor composite";
    }
    else{
    for(int i=2;i<num;i++)
    {
        if(num%i==0)
        {
            count++;
            cout<<"not prime";
            break;
        }
    }
    if(count==0)
    {
        cout<<"prime";
    }
    }
    }
    return 0;
}