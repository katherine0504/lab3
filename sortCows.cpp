#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
   ifstream inFile("file.in", ios::in);
   int size;
   int total;

   if (!inFile)
   {
	  cerr << "Failed Opening." << endl;
	  exit (1);
   }

   inFile >> size;
   
   vector<int> v(size);
   
   for (int i=0; i<size; i++)
   {
	  inFile >> v.at(i);
   }

   int insert;
   int moveItem;

   for (int next=1; next<size; next++)
   {
	  insert= v.at(next);
	  moveItem= next;
	  while ((moveItem>0) &&(v.at(moveItem-1)>insert))
	  {
		 v.at(moveItem)= v.at(moveItem-1);
		 moveItem--;
	  }
	  v.at(moveItem)= insert;
   }

   total= v.at(size-1)+v.at(size-2)+v.at(size-3)+v.at(size-4)+v.at(size-5);

   cout << total << endl;


   return 0;
}

	  

