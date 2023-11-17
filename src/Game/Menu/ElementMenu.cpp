
class ElementMenu 
{
public:
	string 	Text = "none";

	ElementMenu() = default;
	void SetText( string t );
	string GetText();
};

void ElementMenu::SetText( string t )
{
	Text = t;
}

string ElementMenu::GetText()
{
	return Text;
}