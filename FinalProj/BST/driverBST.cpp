#include <iostream>
#include "BST.hpp"
#include <string>
#include<sstream>
#include <vector>
#include <fstream>
using namespace std;
using namespace chrono;
int main ()
{
  BST tree;
  string fileName = "dataSetB.csv";
  high_resolution_clock::time_point start, end;
  int timeTester[40000];
  float insert[400];
  float search[400];
  ifstream myFile;
  string line;
  myFile.open(fileName); 
  if(!myFile.is_open())
  {
    cerr << "Nah keep trying dawg" << endl;
  }
  bool flag = false;
  int count = 0;
  while(getline(myFile, line))
  {
      stringstream sub(line);
      string temp;
      while(getline(sub, temp, ','))
      {
        timeTester[count] = stoi(temp);
        count++;
      }
  }
    int i = 0;
    for(int iteration = 0; iteration < 400; iteration++)
    {
        duration<double> exTime;
        start = high_resolution_clock::now();
        for(int j = i; j < (i+100); j++)
        {
          tree.insert(timeTester[j]);
        }
        // tree.printTree(tree.getRoot());
        end = high_resolution_clock::now();
        exTime = duration_cast<microseconds>(end-start);
        insert[iteration] = exTime.count() / 100;
        i += 100;
    }
    int e = 0;
    for(int iteration = 0; iteration < 400; iteration++)
    {
        duration<double> exTime2;
        start = high_resolution_clock::now();
        for(int f = i; f < (i+100); f++)
        {
          tree.search(timeTester[rand() % 100]);
        }
        end = high_resolution_clock::now();
        exTime2 = duration_cast<microseconds>(end-start);
        search[iteration] = exTime2.count() / 100;
        cout << exTime2.count() / 100 << " seconds" << endl;
        e += 100;
    }
    ofstream outInsert;
    outInsert.open("BSTInsertB.csv");
    int num = 0;
    for(int i = 0; i < 400; i++)
    {
      outInsert << insert[i];
      outInsert << endl;
      num++;
    }
    outInsert.close();
    ofstream outSearch;
    outSearch.open("BSTSearchB.csv");
    for(int i = 0; i < 400; i++)
    {
      outSearch << search[i];
      outSearch << endl;
      num++;
    }
    outSearch.close();
}