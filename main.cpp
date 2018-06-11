/*
This project is created by ALAA ANANI as part of the Data Structres and Algorithms CS210 Course.
December 14, 2017.
Copyrgiht © 2017 ALAA ANANI. All rights are reserved.
*/



#include "PQ.h"
#include "Sets.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>



using namespace std;
int N; //size of the matrix
int **M;//to create 2d dynamic array
ifstream source; int nonzeroedges = 0; E *edgeArr; 



void readfile();
void printMatrix();
void storeEdges();

PQ pQ(nonzeroedges+1000);
Sets set(N+1000);
void traverse();


int main()
{
	
	readfile();
	printMatrix();
	storeEdges();
	traverse();


	system("pause");
	
	
}



void readfile()
{
	
	string s;
	cout << "Entre file name" << endl;
	cin >> s;
	source.open(s.c_str());
	 
	source >> N;
	

	//create matrix
	M = new int *[N];
	for (int i = 0; i < N; i++)
		M[i] = new int[N];
	//read matrix from file
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			source >> M[i][j];
			
		}

	source.close();


}

void printMatrix()
{
	int A = 65;
	cout << "Adjacency matrix" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << setw(3) << char(A) << " ";
		++A;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "____";
	}
	cout << endl;
	int B = 65;
	for (int i = 0; i < N; i++)
	{
		cout << char(B) << "|";
		for (int j = 0; j < N; j++)
			cout << setw(3) <<  M[i][j] << " ";
		cout << endl;
		++B;
	}

	cout << "Number of vertices = " << N << endl << endl;

}

void storeEdges()
{
	int Maxsize = N*(N - 1) / 2;
	edgeArr = new E [Maxsize];
	
	 
 for(int i=0;i<N;i++)
	for (int j = 0; j < N && j !=i; j++)
	{
		
		if (M[i][j] != 0 || M[i][j] != 00 )
		{
			edgeArr[nonzeroedges].u = i;
			edgeArr[nonzeroedges].v = j;
			edgeArr[nonzeroedges].w = M[i][j];
			nonzeroedges++;
		}

	}

 cout << "Number of non-zero edges = " << nonzeroedges << endl << endl;

 cout << "These edges are" << endl << endl;

 for (int i = 0; i < nonzeroedges; i++)
	 cout << char(edgeArr[i].u + 65) << " " << char(edgeArr[i].v + 65) << " " << edgeArr[i].w << endl;



}


void traverse()
{
	E a; int sum = 0;

	for (int i = 0; i < nonzeroedges ; i++)
		pQ.insert(edgeArr[i]);
	
	cout << "The minimum spanning tree is = " << endl;
	int CompletePath = 0;

	//repeat this until there are N-1 edges in the spanning tree
	for(int i=0; i < nonzeroedges ; i++)
	{
		
		a = pQ.remove();
		if (CompletePath == N - 1)
			break;
			//if a cycle is detected
			if (set.SimpleFind(a.u -1 ) == set.SimpleFind(a.v - 1))
			{

				cout << "Cycle detected between " << char(a.v + 65) << " " << char(a.u + 65) << endl;				

			}
			else // if no cycle is detected, union and cout the edge
			{
				CompletePath++;
				//since indexes start from 0 in the set class, I insert the vertix - 1
				set.SimpleUnion(a.u - 1, a.v - 1);
				
				
				sum += a.w;
				cout << char(a.v + 65) << "  " << char(a.u + 65) << " " << a.w << endl;
				

			}
		
			
			
	}

	cout << endl << "The minimum total cost = " << sum << endl;
	

}
