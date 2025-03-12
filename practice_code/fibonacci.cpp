// #include<iostream>
// using namespace std;
// int main()
// {
//     int n, n1=0, n2=1,n3;
//     cin >> n;
//     cout << n1 << " " << n2 << " ";
//     for(int i=0;i<n;i++)
//     {
//         n3=n1+n2;
//         cout << n3 << " ";
//         n1=n2;
//         n2=n3;
//     }
//     return 0;
// }
#include <iostream>
using namespace std;
int fibonacci(int n)
{
if(n<=1)
    {
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    int n;
    cout << "Enter the target number : ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << fibonacci(i) << " ";
    }
    return 0;
}