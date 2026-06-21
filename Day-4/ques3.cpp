#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int num,count=0,num_or,rem,new_num=0,num_org;
    cout<<"enter the number to check armstrong or not ";
    cin>>num;

    num_or=num;
    num_org=num;
    while(num!=0)
    {
        num=num/10;
        count++;
    }
    
    for(int i=1;i<=count;i++)
    {
        rem=num_or%10;
        new_num=new_num+round(pow(rem,count));
        num_or=num_or/10;
    }
    if(new_num==num_org)
    {
        cout<<"an armstrong number";

    }
    else{
        cout<<"not an armstrong number";
    }
    return 0;
}