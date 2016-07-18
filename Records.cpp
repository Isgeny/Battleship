#include "Records.h"

Records::Records(int rows, int columns, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked) :
	Table(rows, columns, rect, r, g, b, a, visible, callbackClicked)
{
	readPlayersFromFile();
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
	//Чтение игроков из файла
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
	//Запись игроков в файл
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
	//Добавляем нового игрока в таблицу рекордов
	players.push_back(player);
	updateRecords();
}

Player* Records::findPlayer(const std::string& name)
{
	//Ищем игрока по имени и возращаем его указатель
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
	//Чистка текста
	Table::deleteData();
	//Заполнение шапки
	this->addData(0, 0, "POS.");
	this->addData(0, 1, "NAME");
	this->addData(0, 2, "WINS");
	this->addData(0, 3, "GAMES");
	this->addData(0, 4, "STEPS");
	//Расстановка позиций 1..10
	for(int i = 1; i <= 10; i++)
	{
		Rect r;
		r.setX(rect.x() + cellWidth/2 - std::to_string(i).size()*16/2);
		r.setY(rect.y() + i*cellHeight + cellHeight/2 + 7);
		cells.push_back(new Label(std::to_string(i), GLUT_BITMAP_HELVETICA_18, 17, r, 0.0, 0.0, 1.0, 1.0, true));
	}
	//Расстановка текста
	for(int i = 0; i < players.size(); i++)
	{
		Rect temp;
		//Имена
		temp.setX(rect.x() + cellWidth + cellWidth / 2 - players[i]->getName().size() * 16 / 2);
		temp.setY(rect.y() + cellHeight + i*cellHeight + cellHeight/2 + 7);
		cells.push_back(new Label(players[i]->getName(), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
		//Победы
		temp.setX(rect.x() + 2*cellWidth + cellWidth / 2 - std::to_string(players[i]->getWins()).size() * 16 / 2);
		temp.setY(rect.y() + cellHeight + i*cellHeight + cellHeight / 2 + 7);
		cells.push_back(new Label(std::to_string(players[i]->getWins()), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
		//Игры
		temp.setX(rect.x() + 3*cellWidth + cellWidth / 2 - std::to_string(players[i]->getGames()).size() * 16 / 2);
		temp.setY(rect.y() + cellHeight + i*cellHeight + cellHeight / 2 + 7);
		cells.push_back(new Label(std::to_string(players[i]->getGames()), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
		//Шаги
		temp.setX(rect.x() + 4*cellWidth + cellWidth / 2 - std::to_string(players[i]->getSteps()).size() * 16 / 2);
		temp.setY(rect.y() + cellHeight + i*cellHeight + cellHeight / 2 + 7);
		cells.push_back(new Label(std::to_string(players[i]->getSteps()), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
	}
}