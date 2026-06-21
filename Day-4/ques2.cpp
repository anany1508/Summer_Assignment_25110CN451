#include<iostream>
using namespace std;
int main()
{
    int first=0,second=1,next ,terms;
    cout<<"enter the term: ";
    cin>>terms;
    if(terms==1)
    {
        cout<<first;
    }
    else{
    if(terms==2)
   {
    cout<<second;
   }
   else{
   
    for(int i=3;i<=terms;i++)
    {
        next=first+second;

        first=second;
        second=next;
    }
    cout<<next;
    return 0 ;
}
}
}