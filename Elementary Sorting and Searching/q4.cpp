// A local bookstore wants to organize its books by price in ascending order. Write a program that accepts
// the prices of n books and sorts them using Bubble Sort.
#include<iostream>
using namespace std;
void bubbleSort(float *price , int size)
{
    for(int i=0 ; i<size ;i++)
    {bool check=false;
        for(int j=0;j<size-i-1;j++)
        {
            if(price[j]>price[j+1])
            {
                float temp=price[j];
                price[j]=price[j+1];
                price[j+1]=temp;
                check=true;
            }
        }
       if(!check){
        break;
    } 
    }
}
int main()
{
    int size;
    cout<<"Enter no of books:"<<endl;
    cin>>size;
    float price[size];
    cout<<"Enter price:"<<endl;
    for(int i=0 ;i<size;i++)
    {
        cin>>price[i];
    }
    bubbleSort(price ,size);
    cout<<"Sorted array is here:"<<endl;
     for(int i=0 ;i<size;i++)
    {
        cout<<price[i]<<endl;
    }
}