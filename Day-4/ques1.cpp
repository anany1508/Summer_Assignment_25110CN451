#include<iostream>
using namespace std;
int main()
{
    int first=0,second=1,next ,terms;
    cout<<"enter the number of terms till where you what the fibonacci series: ";
    cin>>terms;
    cout<<"the required fibonacci series is :"<<endl;
    cout<<first<<endl<<second<<endl;

    for(int i=3;i<=terms;i++)
    {
        next=first+second;
        cout<<next<<endl;
        first=second;
        second=next;
    }
    return 0 ;
}