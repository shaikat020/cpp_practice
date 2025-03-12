#include<bits/stdc++.h>
#include<cmath>
using namespace std;

double func(double x)
{
    return 3*x- cos(x)-1;
}
double derived_func(double x)
{
    return 3 +sin(x);
}
void newton_raphson(double x)
{
    double h;
    h=func(x)/derived_func(x);
    do
    {
        h=func(x)/derived_func(x);
        x=x-h;
    }
    while(fabs(h)>=0.001);
    cout<<"The root is : " << x <<endl;
}
int main()
{
    double a;
    cout<<"Enter the initial : ";
    cin>>a;
    cout<< setprecision(2)<< fixed;

    newton_raphson(a);
    return 0;
}
