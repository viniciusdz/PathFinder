// Coded by  Vinicius Santana https://github.com/viniciusdz
#pragma once
#include <stack>
#include <list>
#include "Node.h"
#include "DataReader.h"
#include <vector>
using namespace std;

class Dfs
{
private:
	stack<Node *> stack;
	Node *now;
	vector <string> path;
	vector <string> state;
	int searchcost=0;
	int pathcost=0;
public:
	void getState();
	bool verifyState(string inState);
	void solver(string file);
	Dfs();
	~Dfs();
};

