#include "src/header.h"

Engine Engine( 100, 30 );
Entity Player( 10, 10, 10, "none", "none" );

SceneChooseGender 	SceneChGender( 10, 10 );
SceneChooseRace		SceneChRace( 10, 10 );

int main() 
{
	Engine.Init();

	SceneChGender.Run( Engine, Player );
	SceneChRace.Run( Engine, Player );

	Engine.ScreenClear();
	
	Engine.MvPrint( 10, 2, "Hi game!!!" );
	Player.DrawDebugInfo( Engine, 50, 10, "Player" );

	Engine.InputChar();
	
	return 0;
}

