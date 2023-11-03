#pragma once 

class Position {
public:
	int x, y;

	Position()									{ x = 0; y = 0;   }
	Position( int xx, int yy ) : x(xx), y(yy)	{				  }
	
	void 		Fill( int xx, int yy ) 			{ x = xx; y = yy; }
};