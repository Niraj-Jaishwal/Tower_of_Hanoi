/*
Name : Niraj Kumar Jaishwal
Student ID: 4792755
Email: nkj5@uakron.edu
Program: Tower of Hanoi
*/

#include <iostream>
#include "towers.h"
#include "mystack.h"

using namespace std;

//constructor
Towers::Towers(int n)
{
    numDisk = n;
    peg1 = new MyStack<int>(n);
    peg2 = new MyStack<int>(n);
    peg3 = new MyStack<int>(n);
}

//Destructor
Towers::~Towers()
{
    delete peg1;
    delete peg2;
    delete peg3;
}

//operator = overloading
Towers& Towers::operator=(const Towers & other)
{
    if(this != &other)
    {
        numDisk = other.numDisk;
        *peg1 = *other.peg1;
        *peg2 = *other.peg2;
        *peg3 = *other.peg3;
    }
    return *this;
}

//Initialize start-tower by putting discs in, then print out the status of three towers after initialized
void Towers::setDisks()
{
    for( int i = numDisk; i > 0; i--)
    {
        peg1->push(i);
    }
    plotPegs();
}

//move n discs from tower s to tower d by using a temporary tower t
void Towers::move(int n, MyStack<int>*s,MyStack<int>*t, MyStack<int>* d)
{
    if(n == 1)
    {
        moveOne(s,d);
        plotPegs();
        return;
    }
    move(n-1,s,d,t);
    moveOne(s,d);
    plotPegs();
    move(n-1, t, s, d);
}

//move one disc from tower s to tower d
void Towers::moveOne(MyStack<int>* s, MyStack<int> * d)
{
    int disk = s->top();
    s->pop();
    d->push(disk);
}

//display disks on the three pegs in the console window (stdout)
//DO NOT MODIFY THIS FUNCTION
void Towers::plotPegs()
{
  	if (peg1==NULL || peg2==NULL || peg3==NULL) return;

	int n1=peg1->size();
	int n2=peg2->size();
	int n3=peg3->size();
	int numDisk = n1+n2+n3;

	MyStack<int> tmp1(*peg1);
	MyStack<int> tmp2(*peg2);
	MyStack<int> tmp3(*peg3);

	//plot
	for (int i=0; i<numDisk; i++) {
		//peg1
		if (numDisk-n1-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m1 = tmp1.top();
			tmp1.pop();
			for (int j=0; j<m1; j++)
				cout << "*";
			for (int j=m1; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg2
		if (numDisk-n2-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m2 = tmp2.top();
			tmp2.pop();
			for (int j=0; j<m2; j++)
				cout << "*";
			for (int j=m2; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg3
		if (numDisk-n3-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m3 = tmp3.top();
			tmp3.pop();
			for (int j=0; j<m3; j++)
				cout << "*";
			for (int j=m3; j<numDisk; j++)
				cout << " ";
		}
		cout<<endl;
	}
	cout << "_________________________________________\n";
}
