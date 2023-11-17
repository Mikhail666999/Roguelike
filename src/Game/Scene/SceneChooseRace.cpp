
class SceneChooseRace : public Menu
{
public:
	SceneChooseRace( int nx, int ny ) 
	{
		position.x = nx;
		position.y = ny;
		Start();
	}

	void Human( Entity &Entity ) 
	{
		Entity.SetRaca( Raca::Human );
	}

	void Elf( Entity &Entity ) 
	{
		Entity.SetRaca( Raca::Elf );
	}
	
	void HalfElf( Entity &Entity ) 
	{
		Entity.SetRaca( Raca::HalfElf );
	}
	
	void Ork( Entity &Entity ) 
	{
		Entity.SetRaca( Raca::Ork );
	}
	
	void HalfOrk( Entity &Entity ) 
	{
		Entity.SetRaca( Raca::HalfOrk );
	}
	
	void HalfElfOrk( Entity &Entity ) 
	{
		Entity.SetRaca( Raca::HalfElfOrk );
	}
	

	void Start() override
	{
		AddElement( Raca::Human		 );
		AddElement( Raca::Elf 		 );
		AddElement( Raca::HalfElf 	 );
		AddElement( Raca::Ork 		 );
		AddElement( Raca::HalfOrk 	 );
		AddElement( Raca::HalfElfOrk );
	}

	void Run( Engine &Engine, Entity &Entity ) 
	{
		int Key;
		while ( MenuWork )
		{
			Engine.ScreenClear();
			
			Entity.DrawDebugInfo( Engine, 50, 10, "Player" );
			Engine.MvPrint( Engine.width * 0.48, 1, "Choose your race" );
			
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

					case 2:
						Engine.MvPrint( position.x,	position.y + i, "c) " + Element[i].Text );
						break;

					case 3:
						Engine.MvPrint( position.x,	position.y + i, "d) " + Element[i].Text );
						break;

					case 4:
						Engine.MvPrint( position.x,	position.y + i, "e) " + Element[i].Text );
						break;

					case 5:
						Engine.MvPrint( position.x,	position.y + i, "f) " + Element[i].Text );
						break;
				}
			}

			Key = Engine.InputChar();
			switch ( Key )
			{
				case 'a':
					Human( Entity );
					Close();
					break;

				case 'b':
					Elf( Entity );
					Close();
					break;

				case 'c':
					HalfElf( Entity );
					Close();
					break;

				case 'd':
					Ork( Entity );
					Close();
					break;

				case 'e':
					HalfOrk( Entity );
					Close();
					break;

				case 'f':
					HalfElfOrk( Entity );
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