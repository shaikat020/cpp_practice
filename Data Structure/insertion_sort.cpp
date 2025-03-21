#include<iostream>
using namespace std;
void insertion_sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    cout<<"Before insertion sort : "<<endl;
    printarray(data, n);
    insertion_sort(data,n);
    cout<<endl<<"Data has been sorted by insertion sort"<<endl<<"Sorted data are : "<<endl;
    printarray(data,n);
    return 0;
}
