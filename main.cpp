#include "src/header.h"

using namespace Config;

Engine engine;
Entity player;

void GameLoop() 
{
	Config::roguelike_command = true;
	engine.CursorInVisible();
	// engine.ReadAllPressed();

	player.Fill( 10, 10, '@', 20 );

	int key;
	while ( engine.IsOpen() ) 
	{
		// 	START DRAW
		engine.ScreenClear();

		engine.MvPrint( 0, 0, ( "code: " + to_string( key ) + ",\t key: " + (char) key ).c_str() );
		engine.MvPrint( player.position.x, player.position.y, string(&player.icon, 1) );

		if ( Config::roguelike_command )
			engine.MvPrint( 0, 1, "roguelike_command = true" );
		else
			engine.MvPrint( 0, 1, "roguelike_command = false" );

		engine.ScreenDraw();
		// 	END DRAW



		// START INPUT
		key = engine.inp();

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

		switch ( key ) 
		{
			case (int) PublicKey::Set:
				if ( Config::roguelike_command )
					Config::roguelike_command = false;
				else
					Config::roguelike_command = true;
				break;

			case (int) PublicKey::Back:
				engine.Close();
				break;
		}
		// END INPUT
	}
}

int main() {	
	engine.FunctionGame( GameLoop );             
	return 0;
}

