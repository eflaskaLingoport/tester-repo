#include<iostream>
#include <fstream>
#include <string>
#include<sstream>
#include <vector>
#include "hash.hpp"
using namespace std;
using namespace chrono;
int main()
{
  HashTable HT;
  string fileName = "dataSetA.csv";
  high_resolution_clock::time_point start, end, start2, end2;
  int timeTester[40000];
  float insert[400];
  float search[400];
  int numColInsert[400];
  int numColSearch[400];
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
        duration<double> exTime, exTime2;
        start = high_resolution_clock::now();
        for(int j = i; j < (i+100); j++)
        {
          HT.InsertQuad(timeTester[j]);
        }
        // HT.printTable();
        end = high_resolution_clock::now();
        exTime = duration_cast<microseconds>(end-start);
        numColInsert[iteration] = HT.getNumOfCollision();
        HT.resetColl();
        // cout << HT.getNumOfCollision() << endl;
        insert[iteration] = exTime.count() / 100;
        start2 = high_resolution_clock::now();
        for(int f = i; f < (i+100); f++)
        {
          HT.quadSearch(timeTester[rand() % (i+100)]);
        }
        end2 = high_resolution_clock::now();
        exTime2 = duration_cast<microseconds>(end2-start2);
        // cout << HT.getNumOfCollision() << endl;
        numColSearch[iteration] = HT.getNumOfCollision();
        HT.resetColl();
        search[iteration] = exTime2.count() / 100;
        i += 100;
    }
    ofstream outInsert;
    outInsert.open("QuadProbeInsertA.csv");
    int num = 0;
    for(int i = 0; i < 400; i++)
    {
      outInsert << insert[i] << ", ";
      outInsert << numColInsert[i];
      outInsert << endl;
      num++;
    }
    outInsert.close();
    ofstream outSearch;
    outSearch.open("QuadProbeSearchA.csv");
    for(int i = 0; i < 400; i++)
    {
      outSearch << search[i] << ", ";
      outSearch << numColSearch[i];
      outSearch << endl;
      num++;
    }
    outSearch.close();
}



  // for(int i = 0; i < 40000; i++)
  // {
  //   // cout << timeTester[i] << endl;
  //   HT.InsertQuad(timeTester[i]);
  // }
  // HT.printTable();
  // cout << HT.getNumOfCollision() << " collisions" << endl;
  // cout << HT.quadSearch(timeTester[423]) << endl;
  // cout << timeTester[898] << endl;