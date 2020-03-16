#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace sf; using namespace std;
class MainMenu
{

public:
	MainMenu(RenderWindow& window);
	void draw(RenderWindow& window);
	bool should_running = true;
private:
	float x;
	float y;
	Text o_text1; 	 
	Text o_text2; 	 
	Text o_text3; 	
	Text txt;
	View view;
	vector<Text> text;
	Font font;
	
};

