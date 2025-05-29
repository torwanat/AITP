#include<iostream>

using namespace std;

int main()
{
    int n,b,i,p;
    cin>>n;
    p=0;

    for(i=0;i<n;i++)
    {
        cin>>b;
        if(b%2==0)
        {
            p=p+1;
        }
    }

    cout<<p;
    return 0;
}
