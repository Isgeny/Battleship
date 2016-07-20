#include "About.h"

About::About() : GraphicsItem()
{
	aboutGame.push_back("Battleship is a guessing game for");
	aboutGame.push_back("2 players. Players place 10 ships");
	aboutGame.push_back("on a 10x10 field. Players have 2,");
	aboutGame.push_back("field for offense and defense.");
	aboutGame.push_back("After ships have been positioned,");	
	aboutGame.push_back("the game proceeds in a series of.");
	aboutGame.push_back("rounds In each round, each player");	
	aboutGame.push_back("makes shot to the opponent's grid.");
	aboutGame.push_back("If it is a miss, player marks his");
	aboutGame.push_back("grid with a dot. If it is a hit,");
	aboutGame.push_back("player mark own field with a red");
	aboutGame.push_back("cross. The game ends once a player");
	aboutGame.push_back("has sunk all opponent's ships.");

	aGame = new Label("ABOUT GAME", GLUT_BITMAP_TIMES_ROMAN_24, 15, Rect(150, 30, 0, 0));
	aboutDev  = new Label("ABOUT DEVELOPER", GLUT_BITMAP_TIMES_ROMAN_24, 15, Rect(530, 30, 0, 0));
	dev	= new Label("DEVELOPER: ISAEV E. A.", GLUT_BITMAP_HELVETICA_18, 15, Rect(455, 60, 0, 0));
	univer = new Label("UNIVERSITY: TPU", GLUT_BITMAP_HELVETICA_18, 15, Rect(455, 120, 0, 0));
	group = new Label("GROUP: 8I52", GLUT_BITMAP_HELVETICA_18, 15, Rect(455, 180, 0, 0));
	email = new Label("EMAIL: jack091196@gmail.com", GLUT_BITMAP_HELVETICA_18, 15, Rect(455, 240, 0, 0));
}

About::~About()
{
	delete aGame;
	delete aboutDev;
	delete dev;
	delete univer;
	delete group;
	delete email;
}

void About::draw()
{
	if(visible)
	{
		for(int i = 0; i < aboutGame.size(); i++)
		{
			for(int j = 0; j < aboutGame[i].size(); j++)
			{
				glColor4d(0.0, 0.0, 1.0, 1.0);
				glRasterPos2d(15 + j * 12, 2*CELL_SZ + i*CELL_SZ / 1.5);
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, aboutGame[i][j]);
			}
		}
		aGame->draw();
		aboutDev->draw();
		dev->draw();
		univer->draw();
		group->draw();
		email->draw();
		glColor4d(r, g, b, a);
		glLineWidth(3);
		glBegin(GL_LINES);
		glVertex2d(WIN_WIDTH/2, 30);
		glVertex2d(WIN_WIDTH/2, WIN_HEIGHT - 120);
		glEnd();
	}
}

void About::setVisible(bool visible)
{
	GraphicsItem::setVisible(visible);
	aGame->setVisible(visible);
	aboutDev->setVisible(visible);
	dev->setVisible(visible);
	univer->setVisible(visible);
	group->setVisible(visible);
	email->setVisible(visible);
}
