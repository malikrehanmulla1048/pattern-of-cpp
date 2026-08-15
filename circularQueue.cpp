#include<iostream>
#include <queue>
using namespace std;
class CircularQueue
{
    int* arr;
    int front;
    int rear;
    int size;
    public:
        CircularQueue(int s)
        {
            arr = new int[s];
            size = s;
            front = rear = -1;
        }
        void push(int val)
        {
            if((rear + 1) % size == front) //also can be written as rear == size-1 
            {
                cout<<"Queue is full"<<endl;
                return ;
            }
            if(front == -1)
            {
                front = rear = 0;
                arr[rear] = val;
                return ;
            }
            rear = (rear + 1) % size;
            arr[rear] = val;
        }
        void pop()
        {
            if(front == -1)
            {
                cout<<"Queue is empty"<<endl;
                return ;
            }
            if(front == rear)
            {
                front = rear = -1;
                return ;
            }
            front = (front + 1) % size;
        }
        int peek()
        {
            if(front == -1)
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return arr[front];
        }
        bool empty()
        {
            return front == -1;
        }
};
int main()
{
    CircularQueue q(5);
    q.push(1);
    q.push(2);
    //q.push(3);
    //q.push(4);
    //q.push(5);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    
    q.pop();
    cout<<q.peek()<<endl;
    return 0;
}