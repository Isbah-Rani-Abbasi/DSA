// 5. Write a program to store employee salaries in a linked list. Sort salaries using Selection Sort on the
// linked list. Print the unsorted and sorted salary lists.

# include<iostream>
using namespace std;

class Node
{
    public:
    float value;
    Node *next;
    Node(float v)
    {
        value=v;
        next=nullptr;
    }
    Node()
    {
        value=0;
        next=nullptr;
    }
};

class LinkList
{
    public:
    Node *head;
    Node *tail;
    
    LinkList()
    {
        head=nullptr;
        tail=nullptr;
    }
    void Addtail(float v){
        Node *temp=new Node(v);
        if(head==nullptr)
        {
            head=tail=temp;
            return;
        }
        tail->next=temp;
        tail=temp;
        
    }
    void print()
    {
        Node *temp=head;
        while (temp!=nullptr)
        {
            cout<<temp->value<<endl;
            temp=temp->next;
        }
        
    }
    ~LinkList()
    {
        
        Node *temp;
        while (temp->next!=nullptr)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
    }
};
void SelectionSort(LinkList &l){
    for(Node *i=l.head;i!=nullptr;i=i->next){
        Node *min=i;
        for(Node *j=i->next;j!=nullptr;j=j->next){
            if(min->value>j->value){
                min=j;
            }
        }
        if(min!=i)
        {
           float temp=min->value;
           min->value=i->value;
           i->value=temp;
        }
    }
}
int main()
{
    LinkList l;
    l.Addtail(4);
    l.Addtail(3);
    l.Addtail(2);
    cout<<"Unsorted link list:"<<endl;
    l.print();
    SelectionSort(l);
    cout<<"Sorted link list in ascending order:"<<endl;
    l.print();
}

    