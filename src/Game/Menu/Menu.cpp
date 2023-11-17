class Menu : public Position
{
public:
	vector<ElementMenu> Element;
	Position position;
	bool MenuWork = true;

	Menu() = default;
	void 				AddElement( string text );
	virtual		void 	Start() = 0;
	virtual 	void 	Close() = 0;
};

void Menu::AddElement( string text )
{
	ElementMenu em;
	em.SetText( text );

	Element.push_back( em );
}

