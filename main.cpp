#include "src/header.h"

using namespace Config;

Engine engine;

void GameLoop() {
	Config::roguelike_command = true;
	engine.CursorInVisible();
	engine.ReadAllPressed();

	Entity player;
	player.Fill( 10, 10, '@', 20 );

	int key;
	while ( engine.IsOpen() ) {
		engine.UpdateConfig();
		engine.ScreenClear();
		engine.ScreenDraw();

		engine.MvPrint( 0, 0, ( "code: " + to_string( key ) + ",\t key: " + (char)key ).c_str() );
		engine.MvPrint( player.position.x, player.position.y, string(&player.icon, 1) );

		if ( Config::roguelike_command )
			engine.MvPrint( 0, 1, "roguelike_command = true" );
		else
			engine.MvPrint( 0, 1, "roguelike_command = false" );

		key = engine.inp();
		switch ( key ) {
			case (const int)key_left:
				player.MoveLeft();
				break;

			case key_right:
				player.MoveRight();
				break;

			case key_forward:
				player.MoveForward();
				break;

			case key_backward:
				player.MoveBackward();
				break;

			case key_rforward:
				player.MoveRight();
				player.MoveForward();
				break;

			case key_lforward:
				player.MoveLeft();
				player.MoveForward();
				break;

			case key_rbackward:
				player.MoveRight();
				player.MoveBackward();
				break;

			case key_lbackward:
				player.MoveLeft();
				player.MoveBackward();
				break;

			case '0':
				if ( Config::roguelike_command )
					Config::roguelike_command = false;
				else
					Config::roguelike_command = true;
				break;

			case 'q':
			case key_back:
				engine.Close();
				break;
		}
	}
}

int main() {	
	engine.FunctionGame( GameLoop );             
	return 0;
}

