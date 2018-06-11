#pragma once

#ifndef PQ_H
#define PQ_H

struct E
{
	int u;
	int v;
	int w;
};

class PQ
{
public:
	PQ(int n);  //Constructor
	~PQ();                  //Destructor
	void insert(E);	   // insert element into heap
	E remove();			// remove & return the top of the heap
	bool IsEmpty(); //checking wether PQ is empty or not
	


private:

	E *a;   //Heap array
	int N;	// index of last element in the array
	int itemMin; //Very small value at index 0
	void upheap(int k);
	void downheap(int k);
};
#endif // PQ_H

