// An HR manager has a list of employee salaries. Use Selection Sort to sort them in descending order. Then search
// for a specific salary using Linear Search. If multiple employees earn the same salary, return the first and last
// occurrence.
# include<iostream>
using namespace std;
void SelectionSort(float *salaries , int size)
{
    for(int i=0;i<size;i++)
    {
        int max=i;
        for(int j=i+1;j<size;j++)
        {
            if(salaries[max]<salaries[j])
            {
                max=j;
            }
        }
        if(max!=i)
        {
            float temp = salaries[i];
            salaries[i]=salaries[max];
            salaries[max]=temp;
        }
    }
    
    
}
void LinearSearch(float *salaries,float find,int size)
{
    int first=-1;
    int last=-1;
    for(int i=0 ;i<size;i++)
    {
      if(salaries[i]==find)
      {
        if(first==-1)
        {
            first=i;
        }
        last=i;
      }
    }
    if(first==-1)
    {
        cout<<find<<" not found."<<endl;
    }
    else if(first==last)
    {
       cout<<"only one occurence of "<<find<<" at index "<<first<<endl;
    }
    else{
        cout<<"first occurence of "<<find<<" is at index "<<first<<" and last occurence of "<<find<<" is at index "<<last<<endl;
    }
}
int main()
{
    int size;
    float find;
    cout<<"Enter no of slaaries:"<<endl;
    cin>>size;
    float salaries[size];
    cout<<"Enter salaries:"<<endl;
    for(int i=0 ;i<size;i++)
    {
        cin>>salaries[i];
    }
    SelectionSort(salaries ,size);
    cout<<"Sorted array is here:"<<endl;
     for(int i=0 ;i<size;i++)
    {
        cout<<salaries[i]<<endl;
    }
    cout<<"Enter the salary you want to find:"<<endl;
    cin>>find;
    LinearSearch(salaries,find,size);

    
}