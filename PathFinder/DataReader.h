// Coded by  Vinicius Santana https://github.com/viniciusdz
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Node.h"

using namespace std;
class DataReader
{
private:
	vector <vector <string> > data;  // data object using the class "vector"
	int lines = 0; // object to store lines info.
	int columns = 0; // object to store columns info.
	string start[2];
	string goal = "G";
	string wall[2];
	


public:
	Node *firstNode;
	void addLine(); // Def of public method to increase number of lines. 
	void setColumns(int value); // Def of encapsulation method 
	int getLines(); // Def of encapsulation method
	int getColumns(); // Def of encapsulation method   
	void readFile(string fileName);  // Def of public method to read files
	void printData();  // Def of public method to print data of files.
	void findStart(); // Def of public method to find the start 
	string getDataO(int x, int y); // Get data in current position
	bool isGoal(int x,int y); // Check current position is the GOAL;
	bool isWall(int x, int y); // Check current position is WALL;
	vector <vector <string> > getData(); //Def of public method to getter data obj.
	DataReader();
	~DataReader();
};

