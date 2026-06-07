#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
        Node(int val)
        {
            data = val;
            next = NULL;

        }
};
class Queue
{
    Node* head;
    Node* tail;
    public:
        Queue()
        {
            head = tail = NULL;
        }
        void push(int val)
        {
            Node* n = new Node(val);
            if(head == NULL)
            {
                head = tail = n;
                return ;
            }
            tail->next = n;
            tail =n;
            
        }
        void pop()
        {
            if(head == NULL)
            {
                cout<<"Queue is empty"<<endl;
                return ;
            }
            Node* todelete = head;
            head = head->next;
            delete todelete;
        }
        int peek()
        {
            if(head == NULL)
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return head->data;
        }
        bool empty()
        {
            return head == NULL;
        }


};
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<"empty "<<q.empty()<<endl;
}