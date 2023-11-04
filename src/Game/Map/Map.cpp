// #pragma once 

#include "../Entity/Entity.cpp"

class Map {
public:
	char 		place[MAP_SIZE][MAP_SIZE][3];

	Map();
	Map( char s );

	void 		WallsFill( char s );
	void 		WallsAddRoom( char s1, char s2, int x, int y, int w, int h, int thickness );
	void 		WallsFillSquare( char s, int x, int y, int w, int h );
	void 		CharacterFill( char s );
	bool 		IsMap( int x, int y );
};

Map::Map()
{
	WallsFill( '0' );
	CharacterFill( ' ' );
}

Map::Map( char s )
{
	WallsFill( s );
	CharacterFill( ' ' );
}

void Map::CharacterFill( char s ) 
{
	for (int y = 0; y < MAP_SIZE; ++y)
	{
		for (int x = 0; x < MAP_SIZE; ++x)
		{
			place[x][y][MAP_PLACE_CHARACTERS] = s;
		}
	}
}

void Map::WallsFill( char s )
{
	for (int y = 0; y < MAP_SIZE; ++y)
	{
		for (int x = 0; x < MAP_SIZE; ++x)
		{
			place[x][y][MAP_PLACE_WALLS] = s;
		}
	}
}
void Map::WallsAddRoom( char s1, char s2, int x, int y, int w, int h, int thickness ) 
{
	WallsFillSquare( s1, x, y, w, h );
	WallsFillSquare( s2, x + thickness, y + thickness, w - thickness*2, h - thickness*2 );
}

void Map::WallsFillSquare( char s, int xx, int yy, int w, int h ) 
{
	for (int y = yy; y < yy + h; ++y)
	{
		for (int x = xx; x < xx + w; ++x)
		{
			place[x][y][MAP_PLACE_WALLS] = s;
		}
	}
}

bool Map::IsMap( int x, int y ) 
{
	return ( x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE );
}