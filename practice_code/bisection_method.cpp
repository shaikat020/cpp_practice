#include<bits/stdc++.h>
using namespace std;
double fun(double x)
{
    return (x*x*x) - 4;
}
double bisection(double a, double b, double diff)
{
    if(fun(a)* fun(b)>=0)
    {
        cout<<"Invalid Interval!!!";
        return 0;
    }
    double c;
    while((b-a)>=diff)
    {
        c=(a+b)/2;
        if(fun(c)==0)
        {
            break;
        }
        if(fun(a)*fun(c)<0)
        {
            b=c;
        }
        else
        {
            a=c;
        }
    }
    return c;
}
int main()
{
    double a, b, difference;
    cout<<"Enter the value of a : ";
    cin>>a;//1
    b=a+1;//2
    cout<<"The interval is : ["<<a<<", "<<b<<"]"<<endl;
    cout<<endl<<"Enter the difference : ";
    cin>>difference;
    double root=bisection(a,b,difference);
    cout<< setprecision(2)<< fixed;
    cout<<"Root is = "<<root<<endl;
    return 0;
}
