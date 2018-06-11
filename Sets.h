// File: Sets.h
// Definition of Disjoint Sets Class

#ifndef SETS_H
#define SETS_H

// Specification of the class
class Sets
{
private:
	int *p, *c, n;
public:
	Sets(int Size) : n(Size)	// Constructor 
	{
		p = new int[n + 1]; c = new int[n + 1];
		for (int i = 0; i <= n; i++) { p[i] = -1; c[i] = 1; }
	}


	~Sets()		// Destructor 
	{
		delete[] p; delete[] c;
	}

	void SimpleUnion(int i, int j);
	int SimpleFind(int i);
	void dispSets() const;
};

#endif // SETS_H
#include "Sets.cpp"  
