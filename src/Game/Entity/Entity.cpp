class Entity {	
public:
	int x = 0, y = 0, health = 5;
	string gender; 
	
	//	CONFIG.CPP > Raca
	string raca;

	Entity();
	Entity( int xx, int yy, int h );
	Entity( int xx, int yy, int h, string g, string r );

	void Fill( int xx, int yy, int h, string g, string r );
	void SetGender( string g );
	void SetRaca( string r );

	void DrawDebugInfo( Engine &Engine, int nx, int ny, string title );
};

Entity::Entity()
{
	Fill( 0, 0, 10, "none", "none" );
}

Entity::Entity( int xx, int yy, int h )
{
	Fill( xx, yy, h, "none", "none" );
}

Entity::Entity( int xx, int yy, int h, string g, string r )
{
	Fill( xx, yy, h, g, r );
}

void Entity::Fill( int xx, int yy, int h, string g, string r )
{
	x 		= xx;
	y 		= yy;
	health	= h;
	gender 	= g;
	raca 	= r;
}

void Entity::SetGender( string g )
{
	gender = g;
}

void Entity::SetRaca( string r )
{
	raca = r;
}

void Entity::DrawDebugInfo( Engine &Engine, int nx, int ny, string title )
{
	Engine.MvPrint( nx, ny, title );
	Engine.MvPrint( nx, ny + 1, "X = " 		+ to_string( x ) );
	Engine.MvPrint( nx, ny + 2, "Y = " 		+ to_string( y ) );
	Engine.MvPrint( nx, ny + 3, "Gender = " + gender );
	Engine.MvPrint( nx, ny + 4, "Race = "	+ raca );
}