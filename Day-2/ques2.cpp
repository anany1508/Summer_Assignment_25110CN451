
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int num ,rem,count=0,rev_no=0;
    cout<<"enter the number ";
    cin>>num;
    int num_or=num;
    
    while(num>0)
    {
        num=num/10;
        count++;
    }

    while(num_or>0)
    {
        rem=num_or%10;
        count--;
        rev_no=rev_no+rem*(round(pow(10,count)));
        num_or=num_or/10;
    }
    cout<<"the reversed  number is "<<rev_no<<endl;
    return 0;
}
