// Coded by  Vinicius Santana https://github.com/viniciusdz
#include "pch.h"
#include "Dfs.h"

// Return all places visited.
void Dfs::getState()
{
	for (int i = 0; i < Dfs::state.size(); i++) {
		cout << Dfs::state[i] << " ";
	}
}

//  Verify if one state was visited.
bool Dfs::verifyState(string inState)
{
	for (int i = 0; i < Dfs::state.size(); i++) {

		if (!(Dfs::state[i].compare(inState))) {
			return true;
		}
	}

	return false;
}

// Solve the maze with DFS
void Dfs::solver(string file)
{
	DataReader data;
	data.readFile(file);
	data.findStart();
	stack.push(data.firstNode);
	cout << "[MAPA]" << endl;
	data.printData();
	cout << endl;
	Dfs::state.push_back(to_string(data.firstNode->getPositionX())+":"+to_string(data.firstNode->getPositionY()));
	while(!Dfs::stack.empty()){
		while (true) {
			now = stack.top();
			now->setVisted();
			int lin = now->getPositionX();
			int col = now->getPositionY();
			//cout << "estou em " << lin << ":"  << col <<endl;
			if (!(data.getDataO(now->getPositionX(), now->getPositionY()).compare("G"))) {
				cout << endl;
				cout << "[INFO]: GOAL ENCONTRADO !!" << endl;
				cout << "[INFO]: LOCAIS VISITADOS : " << endl;
				getState();
				cout << endl;
				Node *aux;
				cout << "[INFO]: SOLUCAO ENCONTRADA:" << endl;
				for(stack; !stack.empty(); stack.pop()) {
					aux = stack.top();
					pathcost++;
					cout << aux->getPositionX() << ":" << aux->getPositionY() <<" ";
				}
				cout << endl;
				cout << "[INFO]: Custo de Pesquisa : " << searchcost << endl;
				cout << "[INFO]: Custo da Solucao : " << pathcost << endl;
				cout << "[INFO]: Custo total: " << (searchcost + pathcost) << endl;

				break;
			}
			else {
				//north case;
				if ((lin - 1) >= 0 && (lin - 1) < data.getLines() && !(data.isWall((lin - 1), col))) {
					if (!(verifyState(to_string(lin-1)+":"+to_string(col)))) {
						Node*  north = new Node();
						north->setPrevious(now);
						north->setPositionX((lin - 1));
						north->setPostionY(col);
						stack.push(north);
						Dfs::state.push_back(to_string(north->getPositionX()) + ":" + to_string(north->getPositionY()));
						cout << "[LOG]: Moveu norte para: " << north->getPositionX() << ":" << north->getPositionY() << endl;
						searchcost++;
						break;
					}
				}
				//case east;
				if ((col + 1) < data.getColumns() && !(data.isWall(lin, (col + 1)))) {
					if (!(verifyState(to_string(lin) + ":" + to_string(col+1)))) {
						Node* east = new Node();
						east->setPrevious(now);
						east->setPositionX(lin);
						east->setPostionY((col + 1));
						stack.push(east);
						Dfs::state.push_back(to_string(east->getPositionX()) + ":" + to_string(east->getPositionY()));
						cout << "[LOG]: Moveu leste para: " << east->getPositionX() << ":" << east->getPositionY() << endl;
						searchcost++;
						break;
					}
				}
				// case west
				if ((col - 1) >= 0 && (col - 1) < data.getColumns() && !(data.isWall(lin, (col - 1)))) {
					if (!(verifyState(to_string((lin))+ ":" + to_string((col-1))))) {
						Node*  west = new Node;
						west->setPrevious(now);
						west->setPositionX(lin);
						west->setPostionY((col - 1));
						stack.push(west);
						Dfs::state.push_back(to_string(west->getPositionX()) + ":" + to_string(west->getPositionY()));
						cout << "[LOG]: Moveu oeste para: " << west->getPositionX() << ":" << west->getPositionY() << endl;
						searchcost++;
						break;
					}
				}
				// case south 
				if ((lin + 1) < data.getLines() && !(data.isWall((lin + 1), col))) {
					if (!(verifyState(to_string(lin + 1) + ":" + to_string(col)))) {
						Node* south = new Node();
						south->setPrevious(now);
						south->setPositionX((lin + 1));
						south->setPostionY(col);
						stack.push(south);
						Dfs::state.push_back(to_string(south->getPositionX()) + ":" + to_string(south->getPositionY()));
						cout << "[LOG]: Moveu sul para: " << south->getPositionX() << ":" << south->getPositionY() << endl;
						searchcost++;
						break;
					}
				}
				// pop stack item
				if (true) {
					stack.pop();
					cout << "[LOG]: Pop realizado em: " << lin << ":" << col << endl;
					break;

				}
			}
		}
	}

}

Dfs::Dfs()
{
}


Dfs::~Dfs()
{
}
