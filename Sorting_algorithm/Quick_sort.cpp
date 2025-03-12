#include<iostream>
using namespace std;
int part(int a[], int first, int last)
{
    int pivot=a[last];
    int i=first-1;
    for(int j=first;j<last;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[last]);
    return i+1;
}
void quicksort(int a[], int first, int last)
{
    if(first<last)
    {
        int pi=part(a,first,last);
        quicksort(a,first,pi-1);
        quicksort(a,pi+1,last);
    }
}
void printarray(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int data[]={40,23,20,67,5,8};
    int n=sizeof(data)/sizeof(data[0]);
    cout<<"Before quick sort : "<<endl;
    printarray(data, n);
    quicksort(data,0,n-1);
    cout<<endl<<"Data has been sorted by quick sort"<<endl<<"Sorted data are : "<<endl;
    printarray(data,n);
    return 0;
}