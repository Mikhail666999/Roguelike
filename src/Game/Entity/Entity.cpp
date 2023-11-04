#pragma once

class Map;

class Entity {
public:
	Position 	position;

	string 		name;
	int 		health;
	int 		mana;
	int 		speed = 1;

	char 		icon;

	Entity() 							{    position.x = 0, position.y = 0, icon = '&';                     }
	Entity( int x, int y, char i, int h )  : position( x, y ), icon(i), health(h) {}

	void 		Fill( int x, int y, char i, int h ) 
										{    position.x = x, position.y = y, icon = i, health = h;           }

	void 		MoveLeft()				{    position.x -= speed;                                            }
	void 		MoveRight()				{    position.x += speed;                                            }
	void 		MoveForward()			{    position.y -= speed;                                            }
	void 		MoveBackward()			{    position.y += speed;                                            }

	void 		SetName( string n ) 	{    name = n; 														 }
};