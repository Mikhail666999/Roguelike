class Engine {
public:
	int width;
	int height;

	Engine();
	Engine( int w, int h );
	~Engine();

	void 	Init();
	void 	MvPrint( int x, int y, string text );
	void 	ScreenFill( string s );
	void 	ScreenFillSquare( int nx, int ny, int nw, int nh, string s );
	void 	ScreenClear();
	void 	ReSize( int w, int h );
	void 	Refresh();
	void 	CursorHide();
	void 	Close();

	int 	InputChar();
};

Engine::Engine()
{
	Init();
	ReSize( 100, 32 );
}

Engine::Engine( int w, int h )
{
	Init();
	ReSize( w, h );
}

Engine::~Engine()
{
	Close();
}

void Engine::Init() 
{
	initscr();
	noecho();
	CursorHide();
}

void Engine::MvPrint( int x, int y, string text )
{
	mvprintw( y, x, text.c_str() );
	Refresh();
}

void Engine::ScreenFill( string s )
{
	for ( int y = 0; y < height; ++y )
	{
		for ( int x = 0; x < width; ++x )
		{
			MvPrint( x, y, s );
		}
	}
}

void Engine::ScreenFillSquare( int nx, int ny, int nw, int nh, string s )
{
	for ( int y = ny; y < ny + nh; ++y )
	{
		for ( int x = nx; x < nx + nw; ++x )
		{
			MvPrint( x, y, s );
		}
	}
}

void Engine::ScreenClear()
{
	clear();
	Refresh();
}

void Engine::ReSize( int w, int h )
{
	resizeterm( h, w );
	width 	= w;
	height 	= h;
}

void Engine::Refresh()
{
	refresh();
}

void Engine::CursorHide()
{
	curs_set( 0 );
}

void Engine::Close() 
{
	endwin();
}

int Engine::InputChar()
{
	return getch();
}