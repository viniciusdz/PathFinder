// Coded by  Vinicius Santana https://github.com/viniciusdz
#pragma once
using namespace std;
#include <iostream>
class Node
{
private:
	Node* node;
	Node*  previous;
	int x, y;
	bool visited;
	

public:
	int getPositionX();
	void setPositionX(int x);
	int getPositionY();
	void setPostionY(int y);
	bool visted();
	void setVisted();
	void setPrevious(Node* previous);
	Node* getPrevious();
	Node(int x, int y);
	
	Node();
	~Node();
};

