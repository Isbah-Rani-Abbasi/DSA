// Q3. Write a C++ program using a circular linked list to manage reserved seats in a train coach. The
// program should traverse the list circularly to check seat availability.
# include<iostream>
using namespace std;
class Node
{
    public:
    int seats;
    Node *next;
    Node(int val)
    {
        seats=val;
        next=nullptr;
    }
};
class CLL
{
  public:
  Node *head;
  
  
  CLL()
  {
    head=nullptr;

  }
  void addSeats(int val)
  {
    Node *temp=new Node(val);
    if(head==nullptr)
    {
      head=temp;
      temp->next=head;
      return;
    }
    Node *curr=head;
    while (curr->next!=head)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=head;
    
  }

  void isSeatReserved(int s)
  {
    if(head==nullptr)
    {
        cout<<"Seat is not reserved"<<endl;
        return;
    }
    Node *temp=head;
    bool check=false;
    do
    {
        if(temp->seats==s)
        {
            check=true;
            break;
        }
        temp=temp->next;

    } while (temp!=head);
    
    if(check)
    {
        cout<<s<< "is reserved"<<endl;
    }
    else{
        cout<<s <<" is not reserved"<<endl;
    }

  }
  void Display()
  {
    if(head==nullptr)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    Node *curr=head->next;
    cout<<head->seats<<"->"<<endl;
    while (curr!=head)
    {
       cout<<curr->seats<<"->";
       curr=curr->next;
    }
  }
};
int main()
{
    bool choice=true;
    CLL train;
    int n;
    int s;
    do
    {
        cout<<"\n-1.Break"<<endl;
        cout<<"1.Add seat"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Check if given seat is reserved or not?"<<endl;
        cin>>n;
        switch (n)
        {
        case -1:
            choice=false;
            break;
        case 1:
        cout<<"Enter seat:"<<endl;
        cin>>s;
        train.addSeats(s);
        break;
        case 2:
        train.Display();
        break;
        case 3:
        cout<<"Enter seat:"<<endl;
        cin>>s;
        train.isSeatReserved(s);
        break;
        default:
            break;
        }
    } while (choice);
    
}