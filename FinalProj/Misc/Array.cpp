#include <iostream>
#include <string>
#include<sstream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    string fileName = "dataSetB.csv";
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
    ofstream outInsert;
    outInsert.open("smolDataB.csv");
    int num = 0;
    for(int i = 0; i < 400; i++)
    {
      outInsert << timeTester[num+100];
      outInsert << endl;
      num++;
    }
}