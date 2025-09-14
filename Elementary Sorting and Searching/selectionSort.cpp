// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int *SelectionSort(int *arr, int size)
{
   for(int i=0;i<size;i++)
   {
       int index=i;
       for(int j=i+1;j<size;j++)
       {
           if(arr[index]>arr[j])
           {
               index=j;
           }
       }
       int temp=arr[i];
       arr[i]=arr[index];
       arr[index]=temp;
   }
    return arr;
}
int main() {
    int s=10;
    int arr[s]={100,9,101,4,203,5,303,5,603,2};
    int *arr1=InsertionSort(arr,s);
    for(int i=0 ;i<s;i++)
    {
        cout<<arr1[i]<<endl;
    }

    return 0;
}