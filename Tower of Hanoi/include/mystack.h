#ifndef MYSTACK_H
#define MYSTACK_H

//***************************************//
//static stack template                  //
//finish all functions                   //
//***************************************//

#include <iostream>
using namespace std;

template <class T>
class MyStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int numElem;		//index of the top element in the stack array

public:
   // Constructor
   MyStack(int);	//pass in an int: tells the maximum size of the stack

   // Copy constructor
   MyStack(const MyStack &);

   //operator= overloading
   MyStack& operator=(const MyStack &);

   // Destructor
   ~MyStack();

   // Stack operations
   void push(T);	//add an item to the stack by passing in a value
   T pop();	//pop a value out by returning the value
   T top();	//return the value at the top position in the stack
   bool isFull() const;	//tell if the stack is full
   bool isEmpty() const;	//tell if the stack is empty
   int size() const;	//tell how many items are in the stack
};

//Constructor
template <class T>
MyStack<T>::MyStack(int size)
{
    stackArray = new T[size];
    stackSize = size;
    numElem = -1;
}

//copy constructor
template <class T>
MyStack<T>::MyStack(const MyStack &other)
{
    stackSize = other.stackSize;
    numElem = other.numElem;
    stackArray = new T[stackSize];
    for(int i = 0; i <= numElem; i++)
    {
        stackArray[i] = other.stackArray[i];
    }
}

//operator = overloading
template <class T>
MyStack<T> & MyStack<T>::operator = (const MyStack<T> & other)
{
    if(this != & other)
    {
        delete [] stackArray;
        stackSize = other.stackSize;
        numElem = other.numElem;
        stackArray = new T[stackSize];
        for(int i = 0; i <= numElem; i++)
        {
            stackArray[i] = other.stackArray[i];
        }
    }
    return *this;
}

//Destructor
template <class T>
MyStack<T>::~MyStack()
{
    delete [] stackArray;
}

//Stack Operations
//Push
template <class T>
void MyStack<T>::push(T value)
{
    if(isFull())
    {
        cout << "Error: stack is full.\n";
    }
    else
    {
        numElem++;
        stackArray[numElem] = value;
    }
}

//Pop
template <class T>
T MyStack<T>::pop()
{
    if(isEmpty())
    {
        cout << "Error: stack is empty.\n";
        return T();
    }
    else
    {
        T value = stackArray[numElem];
        numElem--;
        return value;
    }
}

//top
template <class T>
T MyStack<T>::top()
{
    if(isEmpty())
    {
        cout << "Error: Stack is empty.\n";
        return T();
    }
    else
    {
        return stackArray[numElem];
    }
}

//check if stack is full
template <class T>
bool MyStack<T>::isFull() const
{
    return (numElem == stackSize - 1);
}

//check if stack if empty
template <class T>
bool MyStack<T>::isEmpty() const
{
    return (numElem == -1);
}

//return the size
template <class T>
int MyStack<T>::size() const
{
    return (numElem + 1);
}

#endif
