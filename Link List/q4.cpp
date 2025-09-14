// Q4. Write a C++ program to keep track of a customer’s transactions. The program should allow the
// user to traverse forward and backward to view transaction history.
# include<iostream>
using namespace std;

class Node{
public:
int value;
Node *next;
Node *pre;
Node(int val)
{
    value = val;
    next =nullptr;
    pre = nullptr;
}
};

class DLL{
    public:
    Node *head;
    Node *tail;
    DLL()
    {
        head=tail=nullptr;
    }
    void addHead(int val)
    {
        Node *temp=new Node(val);
        if(head==nullptr)
        {
            head=tail=temp;
            return;
        }
        temp->next=head;
        head->pre=temp;
        temp->pre=nullptr;
        head=temp;
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
        temp->pre=tail;
        temp->next=nullptr;
        tail=temp;
        //a pre pointer points to whole previous node
    }
    void addAfter(int afterval , int val)
    {
        if(head==nullptr)
        {
            cout<<"List is epmty"<<endl;
            return;
        }
        Node *curr=head;
        while (curr!=nullptr&&curr->value!=afterval)
        {
            curr=curr->next;
        }
        if(curr==nullptr)
        {
            cout<<afterval<<" is not in link list"<<endl;
            return;
        }
        Node *temp=new Node(val);
        if(curr==tail)
        {
              curr->next=temp;
              temp->pre=curr;
              temp->next=nullptr;
              tail=temp;
            return;
        }
        curr->next->pre=temp;
        temp->next=curr->next;
        curr->next=temp;
        temp->pre=curr;
    }
    void deleteHead()
    {
      if(head==nullptr)
      {
        cout<<"Link list is empty"<<endl;
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
      head->pre=nullptr;
      delete temp;
      temp=nullptr;

    }
    void deleteTail()
    {
        if(head==nullptr)
        {
            cout<<"link List is empty"<<endl;
            return;
        }
        if(head==tail)
        {
            delete head;
            head=tail=nullptr;
            return;
        }
        Node *temp=tail;
        // temp->pre->next=nullptr;
        // temp->pre=nullptr;
        tail=temp->pre;
        tail->next=nullptr;
        delete temp;
        temp=nullptr;

    }
    void deleteAfter(int afterval)
    {
        if(head==nullptr)
        {
            cout<<"Link list is empty"<<endl;
            return;
        }
        if(head==tail)
        {
            cout<<"There is only 1 node, nothind to delte after"<<endl;
            return;
        }
        Node *curr=head;
        while (curr!=nullptr&&curr->value!=afterval)
        {
            curr=curr->next;
        }

         if(curr==nullptr)
        {
            cout<<afterval<<" not found"<<endl;
            return;
        }
        if(curr->next==nullptr)
        {
            cout<<"There is no value after "<<afterval<<endl;
            return;
        }
        if(curr->next==tail)
        {
            Node *temp=curr->next;
            curr->next=nullptr;
            tail=curr;
            delete temp;
            temp=nullptr;
            return;

        } 
        Node *temp=curr->next;
        curr->next=curr->next->next;
        curr->next->pre=curr;
        delete temp;
        temp=nullptr;


    }
    void display()
    {
        int choice;
        cout<<"1.forward display of transation"<<endl;
        cout<<"2.backward display of transation"<<endl;
        cin>>choice;
        if(choice==1){
        if(head==nullptr)
        {
            cout<<"Link list is epmty"<<endl;
            return;
        }
        Node *temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->value<<"->";
            temp=temp->next;
        }}

        else if(choice==2){
        if(head==nullptr)
        {
            cout<<"Link list is epmty"<<endl;
            return;
        }
        Node *temp=tail;
        while (temp!=nullptr)
        {
            cout<<temp->value<<"->";
            temp=temp->pre;
        }}
        else{
            cout<<"Invalid choice"<<endl;
        }
        
        
    }
};
int main()
{
     DLL transation;
    bool check=true;
    int n=0;
    int val,afterval;
    do
    {
        cout<<endl;
        cout<<"-1.End"<<endl;
        cout<<"0.Add transaction at Head"<<endl;
        cout<<"1.Add transaction Tail"<<endl;
        cout<<"2.Add transation After"<<endl;
        cout<<"3.Delete trasnation at Head"<<endl;
        cout<<"4.Delete trasnation Tail"<<endl;
        cout<<"5.Delete transaction After"<<endl;
        cout<<"6.Display transaction"<<endl;
        cin>>n;
        switch (n)
        {
        case -1:
            check=false;
            break;
        case 0:
        cout<<"Enter val which you want to add:"<<endl;
        cin>>val;
        transation.addHead(val);
        break;

        case 1:

        cout<<"Enter val which you want to add:"<<endl;
        cin>>val;
        transation.addTail(val);
        break;

        case 2:

        cout<<"Enter after val:"<<endl;
        cin>>afterval;
        cout<<"Enter val which you want to add:"<<endl;
        cin>>val;
        transation.addAfter(afterval,val);
        break;

        case 3:
        transation.deleteHead();
        break;

        case 4:
        transation.deleteTail();
        break;

        case 5:
        cout<<"Enter after val:"<<endl;
        cin>>afterval;
        transation.deleteAfter(afterval);
        break;

        case 6:
        transation.display();
        break;

        default:
            break;
        }

        
    } while (check);
}