#pragma once

class Camera {
public:
	bool 		PlayerIsCamera = false;
	Position 	position;
	int 		fx;
	int 		fy;
	int 		width;
	int 		height;

	Camera();
	Camera( int px, int py, int xx, int yy, int w, int h );

	void 		SetFactorXY( int x, int y );
	void 		Fill( int px, int py, int xx, int yy, int w, int h );
	void 		Draw( Engine &engine, Map &map );
};

Camera::Camera() 
{
	position.x = 1;
	position.y = 1;
	fx = 0;
	fy = 0;
	width = 90;
	height = 30;
}

Camera::Camera( int px, int py, int xx, int yy, int w, int h ) 
{
	position.x = px;
	position.y = py;
	fx = xx;
	fy = yy;
	width = w;
	height = h;
}

void Camera::Fill( int px, int py, int xx, int yy, int w, int h ) 
{
	position.x = px;
	position.y = py;
	fx = xx;
	fy = yy;
	width = w;
	height = h;
}

void Camera::Draw( Engine &engine, Map &map )
{
	int xx;
	int yy;

	// Walls
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			xx = x + fx;
			yy = y + fy;
			if ( xx > 0 && xx < MAP_SIZE && yy > 0 && yy < MAP_SIZE )
				engine.MvAddChar( x + position.x, y + position.y, map.place[x + fx][y + fy][MAP_PLACE_WALLS] );
			else  
				engine.MvAddChar( x + position.x, y + position.y, ' ' );
			// if ( xx > 0 && xx < MAP_SIZE ) {
			// 	if (yy > 0 && yy < MAP_SIZE ) {
			// 		engine.MvAddChar( x + position.x, y + position.y, map.place[x + fx][y + fy][MAP_PLACE_WALLS] );
			// 	}
			// }
			// else { 
			// 	engine.MvAddChar( x + position.x, y + position.y, ' ' );
			// }
		}
	}

	// Characters
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			xx = x + fx;
			yy = y + fy;
			if (  map.place[x + fx][y + fy][MAP_PLACE_CHARACTERS] != ' ' ) 
				if ( xx > 0 && xx < MAP_SIZE && yy > 0 && yy < MAP_SIZE )
					engine.MvAddChar( x + position.x, y + position.y, map.place[x + fx][y + fy][MAP_PLACE_CHARACTERS] );
		}
	}
}

void Camera::SetFactorXY( int x, int y ) 
{
	fx = x;
	fy = y;
}