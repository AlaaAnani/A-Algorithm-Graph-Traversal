#include <iostream>
#include "PQ.h"
using namespace std;

//Constructor
PQ::PQ( int n)
{

	a = new E[n]; // allocating space for PQ
	N = 0;
	itemMin = -99999; // Minimum Heap
	a[0].w = itemMin;  //putting infinity in the first place

}


//Destructor
PQ::~PQ()
{
	delete[]a;
	
};

// Insert element (v) in the heap and adjust heap
void PQ::insert(E v)
{
	N++;
	a[N] = v;
	upheap(N);
}

//Checking whether the PQ is empty or not
bool PQ::IsEmpty()
{
	return (N ==0);
}
 
//moving the element up
void PQ::upheap(int k)
{
	E v = a[k];
	while (a[k / 2].w >= v.w)
	{
		a[k] = a[k / 2];   k = k / 2;
	}
	a[k] = v;
}

// remove and return top of the heap, then adjust heap
E PQ::remove()
{
	E v = a[1];
	a[1] = a[N--]; downheap(1);
	return v;
}

//moving the element down
void PQ::downheap(int k)
{
	int j = 2 * k;     E v = a[k];
	while (j <= N) {
		if ((j < N) && (a[j].w > a[j + 1].w)) j++;
		if (v.w <= a[j].w) break;
		a[j / 2] = a[j];     j *= 2;
	}
	a[j / 2] = v;
}

