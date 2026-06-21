#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int num_or,rem,num_org,range,num;
    cout<<"enter the range to check armstrong or not ";
    cin>>range;

    for(int i=1;i<=range;i++)
    {
        num=i;
    num_or=i;
    num_org=i;
    int count=0;
    while(num!=0)
    {
        num=num/10;
        count++;
    }
    int new_num=0;
    for(int j=1;j<=count;j++)
    {
        rem=num_or%10;
        new_num=new_num+round(pow(rem,count));
        num_or=num_or/10;
    }
    if(new_num==num_org){
            cout<<new_num<<endl;
    }
    
    }
    return 0;
}