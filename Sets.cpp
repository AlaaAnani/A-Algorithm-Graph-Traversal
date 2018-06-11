// File: Sets.cpp
// Disjoint Sets class implementation

#include <iostream>
using namespace std;

// Make a union between set(i) and set(j)	
void Sets::SimpleUnion(int i, int j)
{
	int sum = c[i] + c[j];
	if (c[i] > c[j]) { p[j] = i; c[i] = sum; }
	else { p[i] = j; c[j] = sum; }
}


// Find the parent set of subset(i)
int Sets::SimpleFind(int i)
{
	while (p[i] >= 0) i = p[i];
	return i;
}

// Display parent array
void Sets::dispSets() const
{
	for (int i = 1; i <= n; i++)
		cout << char(i+65) << ":" << char(p[i]+65) << ":" << c[i] << " ";
	cout << endl;
}

