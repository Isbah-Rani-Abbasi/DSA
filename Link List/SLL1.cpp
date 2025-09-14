#include<iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node *next;
    Node(int val)
    {
        value=val;
        next=nullptr;
    }
};
class SLL
{
    public:
    Node *head;
    Node *tail;
    SLL(){
        head=tail=nullptr;
    }

    void addHead(int val)
    {
        Node *temp=new Node(val);
        if(head==nullptr)
        {
            head=tail=temp;     
            return;
            //Now both head and tail points to node 1
        }
        temp->next=head;
        head=temp;
        //temp point kar raha hai node with val , hea=temp ab head bhi us address ko point kare ga jisko temp 
        //kar raha hai yaani node with val.
    }
    void addTail(int val)
    {
        Node *temp=new Node(val);
        if(head==nullptr)
        {
            head=tail=temp;
            return;
        }
        tail->next=temp;
        tail=temp;
    }
    void addAfter(int afterval , int val)
    {
        if(head==nullptr)
        {
            cout<<"there is no node to add After , kindly use addHead(int val) first"<<endl;
            return;
        }
        Node *curr=head;
        while (curr!=nullptr && curr->value!=afterval)
        {
            curr=curr->next;
        }
        if(curr==nullptr)
        {
            cout<<afterval<<" is not in list so we cant add "<<val<<" in list."<<endl;
            return;
        }
        Node *temp = new Node(val);
        temp->next=curr->next;
        curr->next=temp;
        if(curr==tail)
        {
            tail=temp;
        }
        
        
        //delete curr means now current is not have authority or landmark over an adress it means computer can
        //utilize that memory but curr still has address of that memory so we use curr=nullptr so neither pointing
        //to and address nor store an address    
    }
    void deleteHead()
    {
        if(head==nullptr)
        {
            cout<<"Link List is empty , nothing to delete"<<endl;
            return;
        }
        if(head==tail)
        {
            delete head;
            head=tail=nullptr;
            return;
        }
        Node *temp=head;
        head=head->next;
        delete temp;
        temp=nullptr;
        //delete temp is freeing memory of node 1 now computer use it , 
        //and temp=nullptr is erasing that memory address from temp
        //if we cant do this node1 memory stays accupied no one will able to use it even it is not
        //part of link list
    }
    void deleteTail()
    {
        if(head==nullptr)
        {
            cout<<"Link list is empty , nothng to delete"<<endl;
            return;
        }
        if(head==tail)
        {
            delete tail;
            head=tail=nullptr;
            return;
            //if ptr a , ptr b, ptr c point to x memory address and 
            //we write delete ptr a now x memory is free although we dont write delete ptr b and delte ptr c
        }
        Node *curr=head;
        Node *pre=nullptr;
        while(curr->next!=nullptr)
        {
            pre=curr;
            curr=curr->next;
        }
        pre->next=nullptr;
        tail=pre;
        delete curr;
        curr=nullptr;
        pre=nullptr;
        //now pre is not pointing to 2nd last node of link list


    }
    void deleteAfter(int afterval)
    {
         if(head==nullptr)
        {
            cout<<"Link list is empty , nothng to delete"<<endl;
            return;
        }
        if(head==tail)
        {
            cout<<"There is nothing to delete after."<<endl;
            delete tail;
            head=tail=nullptr;
            return;
            //if ptr a , ptr b, ptr c point to x memory address and 
            //we write delete ptr a now x memory is free although we dont write delete ptr b and delte ptr c
        }
        Node *curr=head;
        while (curr!=nullptr && curr->value!=afterval)
        {
            curr=curr->next;
        }
        if(curr==nullptr)
        {
            cout<<"The "<<afterval<<" not found in link list"<<endl;
            return;
        }
        if(curr->next==nullptr)
        {
          cout<<"The given value is last node ,nothing to delte after"<<endl;
          return;
        }
        
        Node *temp=curr->next;
        curr->next=temp->next;
        if(temp==tail)
        {
            tail=curr;
        }
        delete temp;
        temp=nullptr;
        curr=nullptr;
        
    }
    void Display()
    {
        if(head==nullptr)
        {
            cout<<"link list is empty"<<endl;
            return;
        }
        Node *curr=head;
        while (curr!=nullptr)
        {
          cout<<curr->value<<"->";
          curr=curr->next;
        }
        
    }
};
int main()
{
    SLL l;
    bool check=true;
    int n=0;
    int val,afterval;
    do
    {
        cout<<endl;
        cout<<"-1.End"<<endl;
        cout<<"0.Add Head"<<endl;
        cout<<"1.Add Tail"<<endl;
        cout<<"2.Add After"<<endl;
        cout<<"3.Delete Head"<<endl;
        cout<<"4.Delete Tail"<<endl;
        cout<<"5.Delete After"<<endl;
        cout<<"6.Display"<<endl;
        cin>>n;
        switch (n)
        {
        case -1:
            check=false;
            break;
        case 0:
        cout<<"Enter val which you want to add:"<<endl;
        cin>>val;
        l.addHead(val);
        break;

        case 1:

        cout<<"Enter val which you want to add:"<<endl;
        cin>>val;
        l.addTail(val);
        break;

        case 2:

        cout<<"Enter after val:"<<endl;
        cin>>afterval;
        cout<<"Enter val which you want to add:"<<endl;
        cin>>val;
        l.addAfter(afterval,val);
        break;

        case 3:
        l.deleteHead();
        break;

        case 4:
        l.deleteTail();
        break;

        case 5:
        cout<<"Enter after val:"<<endl;
        cin>>afterval;
        l.deleteAfter(afterval);
        break;

        case 6:
        l.Display();
        break;

        default:
            break;
        }

        
    } while (check);
    
}