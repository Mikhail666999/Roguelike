#include "src/header.h"

using namespace Config;

Engine 	engine;
Entity	player;
Map 	map;
Camera 	camera;

int key = 0;

void UI()
{
	
	// string s = ;
	engine.MvPrint( 0, 5,( "code: \'" + str( key ) + "\'" ) );
	if ( debug ) 
	{
		engine.MvPrint( 0, 0, ( "roguelike/keypad( 1 / 0 ): " + str( roguelike_command ) + "\n" ) );

		engine.Print( "Player x = " + str( player.position.x ) + "\n" );
		engine.Print( "Player y = " + str( player.position.y ) + "\n" );
		engine.Print( "Player speed = " + str( player.speed ) );
	}
	else 
	{
		engine.MvPrint( 0, 0, "Name: " + player.name );
	}
}

void GameLoop() 
{
	engine.CursorInVisible();

	player.Fill( 16, 10, '@', 20 );

	map.WallsFill( '.' );
	map.WallsAddRoom( '#', '.', 1, 1, 15, 6, 1 );

	camera.Fill( 20, 1, 90, 30 );

	roguelike_command = true;
	debug = true;

	while ( engine.IsOpen() ) 
	{
		// 	START DRAW
		engine.ScreenClear();
		
		map.place[player.position.x][player.position.y][MAP_PLACE_CHARACTERS] = player.icon;

		camera.fx = player.position.x - camera.width / 2;
		camera.fy = player.position.y - camera.height / 2;

		UI();
		camera.Draw( engine, map );

		engine.ScreenDraw();
		map.place[player.position.x][player.position.y][MAP_PLACE_CHARACTERS] = ' ';
		// 	END DRAW

		// INPUT
		key = engine.inp();

		// Roguelike
		if ( roguelike_command ) 
		{
			switch ( key ) 
			{
				case (int) Config::RoguelikeKey::Left:
					player.MoveLeft();
					break;

				case (int) Config::RoguelikeKey::Right:
					player.MoveRight();
					break;

				case (int) Config::RoguelikeKey::Forward:
					player.MoveForward();
					break;

				case (int) RoguelikeKey::Backward:
					player.MoveBackward();
					break;

				case (int) RoguelikeKey::RForward:
					player.MoveRight();
					player.MoveForward();
					break;

				case (int) RoguelikeKey::LForward:
					player.MoveLeft();
					player.MoveForward();
					break;

				case (int) RoguelikeKey::RBackward:
					player.MoveRight();
					player.MoveBackward();
					break;

				case (int) RoguelikeKey::LBackward:
					player.MoveLeft();
					player.MoveBackward();
					break;
			}
		} 

		// Keypad 
		else
		{
			switch ( key ) 
			{
				case (int) KeypadKey::Left:
					player.MoveLeft();
					break;

				case (int) KeypadKey::Right:
					player.MoveRight();
					break;

				case (int) KeypadKey::Forward:
					player.MoveForward();
					break;

				case (int) KeypadKey::Backward:
					player.MoveBackward();
					break;

				case (int) KeypadKey::RForward:
					player.MoveRight();
					player.MoveForward();
					break;

				case (int) KeypadKey::LForward:
					player.MoveLeft();
					player.MoveForward();
					break;

				case (int) KeypadKey::RBackward:
					player.MoveRight();
					player.MoveBackward();
					break;

				case (int) KeypadKey::LBackward:
					player.MoveLeft();
					player.MoveBackward();
					break;
			}
		} 

		// Public
		switch ( key ) 
		{
			case (int) PublicKey::SetInput:
				if ( Config::roguelike_command )
					Config::roguelike_command = false;
				else
					Config::roguelike_command = true;
				break;

			case (int) PublicKey::Back:
				engine.Close();
				break;

			case (int) PublicKey::SetSpeed:
				if ( player.speed < 10 ) 
					player.speed++;
				else 
					player.speed = 1;
				break;
		}



		// END INPUT
	}
}

int main() {	
	engine.FunctionGame( GameLoop );             
	return 0;
}
