# include<iostream>
using namespace std;

int *ShellSort(int *arr,int size)
{
    int h=1;
    while (h<size/3)
    {
       h=3*h+1;
    }
    while (h>=1)
    {
        for(int i=h;i<size;i++)
        {
            int temp=arr[i];
            int j=i;

            while (j>=h && arr[j-h]>temp)
            {
                arr[j]=arr[j-h];
                j=j-h;
            }
            arr[j]=temp;
            
        }
        h=h/3;
    }
    return arr;

    
}
int main()
{
    int arr[5]={1,2,6,3,0};
    int *arr1=ShellSort(arr,5);
    for(int i=0 ;i<5;i++)
    {
        cout<<arr1[i]<<endl;
    }
}