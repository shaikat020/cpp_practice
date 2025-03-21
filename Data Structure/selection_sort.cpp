#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int smallest=i;
        for(int j=i+1;j<n;j++)
        {
            if (arr[j]<arr[smallest])
            {
                smallest=j;
            }
        }
        swap(arr[i],arr[smallest]);
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
    cout<<"Before selection sort : "<<endl;
    printarray(data, n);
    selection_sort(data,n);
    cout<<endl<<"Data has been sorted by selection sort"<<endl<<"Sorted data are : "<<endl;
    printarray(data,n);
    return 0;
}
