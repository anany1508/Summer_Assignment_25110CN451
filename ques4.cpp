#include<iostream>
using namespace std;
int main()
{
     int num1,num2,pro1,pro2,count =0;
     cout<<"enter the 2 numbers whose lcm is to be calculated : ";
     cin>>num1>>num2;

     for(int i=1;i<10;i++)

     {
        pro1=i*num1;
        for(int j=1;j<=10;j++)
        {
            pro2=j*num2;
            if(pro1==pro2)
            {
                cout<<"the lcm of 2 given numers is "<<pro1<<endl;
                count++;
            }
        }
        if(count==1)
        {
            break;
        }
     }
     return 0;
}   