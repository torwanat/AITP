#include <iostream>
#include <cmath>
using namespace std;
double e=0.00001;
int i,n=100;
double f(double x)
{
    return pow((x-5),3);
}
double siecznych(double a,double b)
{
double c;
i++;
    c=a-f(a)*(b-a)/(f(b)-f(a));
    b=a;
    if (fabs(c-b)<e){
        return c;
    }
    else
        a=c;
        if (i<=n){
        return siecznych(a,b);
        }
        else
        return -1;
        }
int main()
{
    double a,b;
    cin>>a;
    cin>>b;
    i=0;
    cout<<siecznych(a,b)<<endl;
    return 0;
}
