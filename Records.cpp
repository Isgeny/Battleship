#include "Records.h"

Records::Records(int rows, int columns, const Rect& rect, double r, double g, double b, double a, bool visible, CallbackClicked callbackClicked) :
	Table(rows, columns, rect, r, g, b, a, visible, callbackClicked)
{
	readPlayersFromFile();
	for(int i = 1; i <= 10; i++)
	{
		Rect r;
		r.setX(rect.x() + cellWidth / 2);
		r.setY(rect.y() + i*cellHeight + cellHeight / 2 + 7);
		cells.push_back(new Label(std::to_string(i), GLUT_BITMAP_HELVETICA_18, 17, r, 0.0, 0.0, 1.0, 1.0, true));
	}
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
	std::ifstream input;
	input.open("Records.txt");
	for(int i = 0; !input.eof(); i++)
	{
		Player *temp = new Player;
		input >> *temp;
		this->addNewUser(temp);
	}
	input.close();
}

void Records::writePlayersToFile()
{
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
	players.push_back(player);
	Rect temp;
	temp.setX(rect.x() + cellWidth + cellWidth / 2 - player->getName().size() * 16 / 2);
	temp.setY(rect.y() + players.size()*cellHeight + cellHeight / 2 + 7);
	cells.push_back(new Label(player->getName(), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));

	temp.setX(rect.x() + 2*cellWidth + cellWidth / 2 - std::to_string(player->getWins()).size() * 16 / 2);
	temp.setY(rect.y() + players.size()*cellHeight + cellHeight / 2 + 7);
	cells.push_back(new Label(std::to_string(player->getWins()), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
	
	temp.setX(rect.x() + 3*cellWidth + cellWidth / 2 - std::to_string(player->getGames()).size() * 16 / 2);
	temp.setY(rect.y() + players.size()*cellHeight + cellHeight / 2 + 7);
	cells.push_back(new Label(std::to_string(player->getGames()), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));

	temp.setX(rect.x() + 4*cellWidth + cellWidth / 2 - std::to_string(player->getSteps()).size() * 16 / 2);
	temp.setY(rect.y() + players.size()*cellHeight + cellHeight / 2 + 7);
	cells.push_back(new Label(std::to_string(player->getSteps()), GLUT_BITMAP_HELVETICA_18, 17, temp, 0.0, 0.0, 1.0, 1.0, true));
}