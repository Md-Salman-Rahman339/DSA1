#include<bits/stdc++.h>
using namespace std;

class myStack{
    int* ptr;
    int max_capacity;
    int a_size;



public:

  myStack(int g){
    ptr=new int[g];
    max_capacity=g;
    a_size=0;
  }
  void push(int g){
    if(a_size==max_capacity){
        cout<<"Stack is full"<<endl;

    }
    ptr[a_size]=g;
    cout<<"element "<<g<<"pushed in stack"<<endl;
    a_size++;
  }
  void pop(){
    if(a_size==0){
        cout<<"Stack is empty"<<endl;
        return;

    }
    
    a_size--;
  }
  int top(){
    if(a_size==0){
        cout<<"Cannot give the top element"<<endl;
        return -1;
    }
    cout<<ptr[a_size-1]<<endl;
  }
   int size()
    {
        return a_size;
    }

    int empty()
    {
        if (a_size == 0)
        {
            cout << "Stack is Empty!" << endl;
            return 1;
        }

        cout << "Stack is not Empty!" << endl;
        return 0;
    }
    void emptyStack(){
        while (a_size>0)
        {
            cout<<"Element"<<ptr[a_size-1]<<"Popped"<<endl;
            a_size--;
        }
        cout<<"Stack is now empty"<<endl;
        
    }
};

int main(){

myStack s1(7);
s1.push(1);
s1.push(2);
s1.push(3);
s1.push(4);
s1.emptyStack();
return 0;
}