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
        }
        
    }
};