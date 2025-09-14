
#include <iostream>
using namespace std;
int *InsertionSort(int *arr, int s)
{
    int size=s;
    for(int i=1 ;i<s;i++)
    {
        for(int j=i;j>0;j--)
        {
           
            if(arr[j-1]>arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
               
            }
            else {break;}
          
            
        }
      
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
