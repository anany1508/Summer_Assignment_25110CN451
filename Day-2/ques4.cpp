#include<iostream>
using namespace std;
int main()
{
    int num,rev_no=0,rem;
    cout<<"enter the number ";
    cin >>num;
    int num_or=num;
    while(num>0)
    {
        rem=num%10;
        rev_no=(rev_no*10)+rem;
        num=num/10;
    }
    if(num_or==rev_no)
    {
        cout<<"a palindrome number";
    }
    else{
        cout<<"not a palindrome number";
    }
    return 0;
}