// Coded by  Vinicius Santana https://github.com/viniciusdz
#include "pch.h"
#include "Node.h"

// Get  X position of current node;
int Node::getPositionX()
{
	return x;
}
// Set X position in current node; 
void Node::setPositionX(int x)
{
	this->x = x;
}
// Get  Y position of current node;
int Node::getPositionY()
{
	return y;
}
// Set  Y position of current node;
void Node::setPostionY(int y)
{
	this->y = y;
}
//Check current node is visited;
bool Node::visted()
{
	if (this->visited == true) {
		return true;
	}
	return false;
}
// Set current node visited;
void Node::setVisted()
{
	this->visited = true;
}
// Set previous node to current node;
void Node::setPrevious(Node * previous)
{
	this->previous = previous;
}
// Get  previous node of current node;
Node * Node::getPrevious()
{
	return previous;
}
// Node constructor;
Node::Node(int x, int y)
{
	this->x = x;
	this->y = y;
	this->visited = false;
	previous = nullptr;
}
// Node constructor;
Node::Node()
{
}
// Node constructor;
Node::~Node()
{
}
