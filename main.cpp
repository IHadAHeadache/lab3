#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "clock.h"
using namespace std;
void insertion_sort(vector<int> & v)
{
  int insert, moveItem;
  for(int next=1;next<v.size();++next) 
    {  
      insert = v.at(next);
      moveItem = next;
      while((moveItem>0) && (v.at(moveItem-1) > insert))
         { 
           v.at(moveItem) = v.at(moveItem-1);
           --moveItem;
         } 
      v.at(moveItem) = insert;
    } 
} 
int main(void)
{
  int cows;
  ifstream inFile("file.in", ios::in);
  if(!inFile)
  {
    cerr << "Failed opening" << endl;
    exit(1);
  }
  inFile >> cows;
  vector<int> weight(cows);
  for(int i = 0; i < cows; ++i)
  {
    inFile >> weight.at(i);
  }
  sort(weight.begin(), weight.end());
  cout << weight.at(cows-1) + weight.at(cows-2) + weight.at(cows-3) + weight.at(cows-4) + weight.at(cows-5) << endl;
} 
