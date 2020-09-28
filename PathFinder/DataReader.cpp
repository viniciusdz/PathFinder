#include "pch.h"
#include "DataReader.h"


DataReader::DataReader()
{
}

DataReader::~DataReader()
{
}
// This method incrase lines number while ReadFile method read file.
void DataReader::addLine()
{
	lines++;
}
// This method set number of columns read by ReadFile Method
void DataReader::setColumns(int value)
{
	columns = value;
}
// This method return lines number.
int DataReader::getLines()
{
	return lines;
}
// This method return columns number.
int DataReader::getColumns()
{
	return columns;
}
// This method read a .txt file matrix parsing the character "," 
void DataReader::readFile(string fileName)
{
	ifstream infile(fileName);
	string line;
	string str;
	while (getline(infile, line))
	{
		istringstream ss(line);
		vector <string> record;
		while (getline(ss, str, ',')) {
			record.push_back(str);
		}
		data.push_back(record);
		DataReader::addLine();
		DataReader::setColumns(record.size());
	}
}
// This method print the data of txt file.
void DataReader::printData()
{
	for (size_t i = 0; i < lines; i++) {
		for (size_t j = 0; j < columns; j++) {
			cout << "[" << data[i][j] << "]";
		}
		cout << endl;
	}
}
void DataReader::findStart(){
	this->firstNode = nullptr;
	start[0] = "S";
	start[1] = " S";
	for (size_t i = 0; i < lines; i++) {
		for (size_t j = 0; j < columns; j++) {
			string aux = data[i][j];
			if (!(data[i][j].compare(start[0]))) {
				this->firstNode = new Node(i, j);
			}
			if (!(data[i][j].compare(start[1]))) {
				this->firstNode = new Node(i, j);
			}
		}
		
	}
}
string DataReader::getDataO(int x, int y)
{
	return data[x][y];
}
bool DataReader::isGoal(int x, int y)
{
	if (!(data[x][y].compare(goal))) {
		return true;
	}
	return false;
}
bool DataReader::isWall(int x, int y)
{
	wall[0] = "0";
	wall[1] = " 0";
	if (!(data[x][y].compare(wall[0]))) {
		return true;
	}
	if (!(data[x][y].compare(wall[1]))) {
		return true;
	}
	return false;
}
// Return  "data" obj of ReadData Class.
vector<vector<string>> DataReader::getData()
{
	return DataReader::data;
}
