#include<iostream>
using namespace std;
void mer(int arr1[], int l, int m, int h)
{
    int i, j, k;
    int arr2[100];
    i=l;
    j=m+1;
    k=l;
    while(i<=m && j<=h)
    {
        if(arr1[i] < arr1[j])
        {
            arr2[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
            arr2[k]=arr1[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        arr2[k]=arr1[i];
        i++;
        k++;
    }
    while(j<=h)
    {
        arr2[k]=arr1[j];
        j++;
        k++;
    }
    for(int i=l; i<=h;i++)
    {
        arr1[i]=arr2[i];
    }
}
void MS(int a[], int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MS(a,low,mid);
        MS(a, mid+1, high);
        mer(a, low, mid, high);
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
    cout<<"Before merge sort : "<<endl;
    printarray(data, n);
    MS(data,0,n-1);
    cout<<endl<<"Data has been sorted by merge sort"<<endl<<"Sorted data are : "<<endl;
    printarray(data,n);
    return 0;
}
