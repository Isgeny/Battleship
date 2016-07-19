#include "Records.h"

Records::Records(int rows, int columns, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked) :
	Table(rows, columns, rect, r, g, b, a, visible, callbackClicked)
{
	readPlayersFromFile();
	updateRecords();
}

Records::~Records()
{
	writePlayersToFile();
	for(auto it = players.begin(); it != players.end(); it++)
		delete (*it);
}

void Records::draw()
{
	if(visible)
	{
		Table::draw();
	}
}

void Records::readPlayersFromFile()
{
	//������ ������� �� �����
	std::ifstream input;
	input.open("Records.txt", std::ios::in);
	std::string temp;
	std::getline(input, temp);
	if(temp.empty())
		return;
	input.seekg(0);
	while(!input.eof())
	{
		Player *temp = new Player;
		input >> *temp;
		this->addNewUser(temp);
	}
	input.close();
}

void Records::writePlayersToFile()
{
	//������ ������� � ����
	std::ofstream output;
	output.open("Records.txt");
	for(int i = 0; i < players.size(); i++)
	{
		output << *players[i];
		if(i + 1 != players.size())
			output << '\n';
	}
	output.close();
}

void Records::addNewUser(Player* player)
{
	//��������� ������ ������ � ������� ��������
	players.push_back(new Player(*player));
	sortByPoints();
}

Player* Records::findPlayer(const std::string& name)
{
	//���� ������ �� ����� � ��������� ��� ���������
	for(auto it = players.begin(); it != players.end(); it++)
	{
		if((*it)->getName() == name)
		{
			return *it;
		}
	}
	return nullptr;
}

void Records::updateRecords()
{
	//������ ������
	Table::deleteData();
	//���������� �����
	this->addData(0, 0, "POS.");
	this->addData(0, 1, "NAME");
	this->addData(0, 2, "POINTS");
	this->addData(0, 3, "WINS");
	this->addData(0, 4, "GAMES");
	//����������� ������� 1..10
	for(int i = 1; i <= 10; i++)
	{
		Rect r;
		r.setX(rect.x() + cellWidth/2 - std::to_string(i).size()*16/2);
		r.setY(rect.y() + i*cellHeight + cellHeight/2 + 7);
		cells.push_back(new Label(std::to_string(i), GLUT_BITMAP_HELVETICA_18, 17, r, 0.0, 0.0, 1.0, 1.0, true));
	}
	//����������� ������
	for(int i = 0; i < players.size(); i++)
	{
		Rect temp;
		//�����
		temp.setX(rect.x() + cellWidth + cellWidth/2 - players[i]->getName().size() * 16/2);
		temp.setY(rect.y() + cellHeight + i*cellHeight + cellHeight/2 + 7);
		cells.push_back(new Label(players[i]->getName(), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
		//����
		temp.setX(rect.x() + 2*cellWidth + cellWidth/2 - std::to_string(players[i]->getPoints()).size() * 16/2);
		temp.setY(rect.y() + cellHeight + i*cellHeight + cellHeight/2 + 7);
		cells.push_back(new Label(std::to_string(players[i]->getPoints()), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
		//������
		temp.setX(rect.x() + 3*cellWidth + cellWidth/2 - std::to_string(players[i]->getWins()).size() * 16/2);
		temp.setY(rect.y() + cellHeight + i*cellHeight + cellHeight/2 + 7);
		cells.push_back(new Label(std::to_string(players[i]->getWins()), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
		//����
		temp.setX(rect.x() + 4*cellWidth + cellWidth/2 - std::to_string(players[i]->getGames()).size() * 16/2);
		temp.setY(rect.y() + cellHeight + i*cellHeight + cellHeight/2 + 7);
		cells.push_back(new Label(std::to_string(players[i]->getGames()), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
	}
}

void Records::sortByPoints()
{
	Player* temp;
	for(int i = 0; i < players.size() - 1; i++)
	{
		for(int j = i + 1; j < players.size(); j++)
		{
			if(players[j]->getPoints() > players[i]->getPoints())
			{
				temp = players[i];
				players[i] = players[i+1];
				players[i+1] = temp;
			}
		}
	}
	updateRecords();
}