
class SceneChooseGender : public Menu
{
public:
	SceneChooseGender( int x, int y )
	{
		position.x = x;
		position.y = y;
		Start();
	}

	void Male( Entity &Entity )
	{
		Entity.SetGender( "male" );
	}

	void Female( Entity &Entity )
	{
		Entity.SetGender( "female" );
	}

	void Start() override 
	{
		AddElement( "Male" );
		AddElement( "Female" );
	}

	void Run( Engine &Engine, Entity &Entity ) 
	{
		int Key;
		while ( MenuWork )
		{
			Engine.ScreenClear();

			Entity.DrawDebugInfo( Engine, 50, 10, "Player" );
			Engine.MvPrint( Engine.width * 0.48, 1, "Choose your gender" );
			
			for ( int i = 0; i < Element.size(); ++i )
			{
				switch ( i )
				{
					case 0:
						Engine.MvPrint( position.x,	position.y + i, "a) " + Element[i].Text );
						break;

					case 1:
						Engine.MvPrint( position.x,	position.y + i, "b) " + Element[i].Text );
						break;
				}
			}

			Key = Engine.InputChar();
			switch ( Key )
			{
				case 'a':
					Male( Entity );
					Close();
					break;

				case 'b':
					Female( Entity );
					Close();
					break;
			}


		}
	}

	void Close() override
	{
		MenuWork = false;
	}
};