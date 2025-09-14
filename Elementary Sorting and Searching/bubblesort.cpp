// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int *BubbleSort(int *arr, int s)
{
    int size=s;
    for(int i=0 ;i<s;i++)
    { bool check=false;
        for(int j=0;j<s-i-1;j++)
        {
           
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                check=true;
            }
            
        }
        if(!check)
        {
            break;
        }
    }
    return arr;
    
}
int main() {
    int s=5;
    int arr[s]={5,6,3,2,1};
    int *arr1=BubbleSort(arr,s);
    for(int i=0 ;i<s;i++)
    {
        cout<<arr1[i]<<endl;
    }

    return 0;
}