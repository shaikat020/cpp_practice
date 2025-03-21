#include<iostream>
using namespace std;
void bubble_sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void printarray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int data[]={40,23,20,67,5,8};
    int n=sizeof(data)/sizeof(data[0]);
    cout<<"Before bubble sort : "<<endl;
    printarray(data, n);
    bubble_sort(data,n);
    cout<<endl<<"Data has been sorted by bubble sort"<<endl<<"Sorted data are : "<<endl;
    printarray(data,n);
    return 0;
}
