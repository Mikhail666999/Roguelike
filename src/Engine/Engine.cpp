#pragma once

class Engine {
	bool        isWork   =   false;
	void 		Init()            			{    initscr(); noecho();              	}
public:
	Engine()                      			{    Init(); isWork = true;				}
	Engine( void func() )         			{    Init(); func(); isWork = true;		}

	void        FunctionGame( void func() )	{    func();							}
	bool 		IsOpen()					{    return isWork;						}

	void 		CursorInVisible() 			{    curs_set( 0 );						}
	void        CursorVisible()   			{    curs_set( 1 );						}
	void        ScreenClear()     			{    clear();							}
	void 		ScreenDraw()				{    refresh();							}
	void 		ReadAllPressed()			{    raw();                            	}
	void 		ReadPartPressed()			{    cbreak();                         	}

	int         inp()           			{    return getch();					}
	
	void 		Print( string text )		{    printw( text.c_str() );			}
	void        MvPrint( int x, int y, string text )
											{    mvprintw( y, x, text.c_str() );	}
	void 		MvAddChar( int x, int y, char s ) 
											{    mvaddch( y, x, s );				}
	void        Close()                     {    endwin(); isWork = false;			}

	~Engine() 								{    Close();							}

};