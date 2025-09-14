// okay so when we delete a pointer it is like pointer has now free the memory it was pointing but it still has address of that memory so write poiter equals to nullptr so now pointer is neither pointer to mamoery address nor it stores the memory address

# include<iostream>
using namespace std;

class Node{
public:
int val;
Node *next;
Node(int value)
{
    val=value;
    next=nullptr;
}
};

class Singly
{
    public:
    Node *head;
    Node *tail;
    Singly()
    {
        head=nullptr;
        tail=nullptr;
    }

    void addHead(int value)
    {
        Node *temp=new Node(value);
        if(head==nullptr)
        {
           head=temp;
           tail=temp;
           return;
        }
       temp->next=head;
       head = temp;
    }

    void addTail(int value)
    {
        Node *temp = new Node(value);
        if(head==nullptr)
        {
            head=temp;
            tail=temp;
            return;
        }
        tail->next=temp;
        tail=temp;
    }

    void addAfter(int afterval , int val)
    {
        if(head==nullptr)
        {
            cout<<"Link List is Empty"<<endl;
            return;
        }
        Node *temp=head;
        while(temp!=nullptr && temp->val!=afterval)
        {
            temp=temp->next;
        }
        if(temp==nullptr)
        {
            cout<<"Not found"<<endl;
            return;
        }
        Node *ptr=new Node(val);
        ptr->next=temp->next;
        temp->next=ptr;
        if(temp==tail)
        {
            tail=ptr;
        }
    }

    void deleteHead()
    {
        if(head==nullptr)
        {
            cout<<"Link list is empty"<<endl;
            return;
        }
        //okay so head and tail are of node type but points to 1st and last node respectively
        Node* temp = head;    // save the address of the current head node or the temp points to the addess which head points to
        head = head->next;    // move head forward to the next node
        delete temp;          // free the old head node from memory
        temp=nullptr;

    }
    void deleteTail()
    {
        if(head==nullptr)
        {
            cout<<"Link List is Empty"<<endl;
            return;
        }
          if(head == tail) {   // ✅ only one node
        delete head;           //if we write delete tail it will also work because both head nad tail points same address
        head = tail = nullptr;
        return;
    }
        Node *pre=nullptr;
        Node *temp=head;
        while (temp->next!=nullptr)
        {
            pre=temp;
            temp=temp->next;
        }
        pre->next=nullptr;
        tail=pre;
        delete temp;
        
    }

    void deleteAfter(int afterval)
    {
        if(head==nullptr)
        {
            cout<<"Link List is Empty"<<endl;
            return;
        }
         if(head == tail) {   // ✅ only one node
        cout << "Only one node, nothing to delete after\n";
        return;
         }
        Node *temp=head;
        while (temp->next!=nullptr&&temp->val!=afterval)
        // temp at [10]: temp->next points to [20] (≠ nullptr) → continue
        // temp at [20]: temp->next points to [30] (≠ nullptr) → continue
        // temp at [30]: temp->next points to nullptr (= nullptr) → STOP LOOP
        {
            temp=temp->next; 
        //head->10->20->30  , i write head=head->next , sohead is pointinf 10 
        //and head->next is pointing 20 so now head also points 20
        }
        if(temp->next==nullptr || temp==nullptr) 
        // temp->next==nullptr becomes true it means after val is last node
        //or if temp==nullptr becomes true if means there is no node with value dimilar to aftervall
          {
            cout<<"No value"<<endl;
            return;
          }    
          Node *curr=temp->next;
          temp->next=curr->next;      
          if(temp->next==nullptr || curr==tail)  
        //curr==tail means both curr and tail points same address
          {
            tail=temp;
          }                            
        delete curr;
        
    }

    void display()
    {
        if(head==nullptr)
        {
            cout<<"Link list is empty"<<endl;
            return;
        }
        Node *temp = head;
        while (temp!=nullptr)
        {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        
    }
};