
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace sf; using namespace std;
class map_selection
{
public:
	map_selection(RenderWindow& window);
	void draw(RenderWindow& window);
	bool ms_song_selected = false;
private:
	RectangleShape _image;
	Texture tutorialMap;
	
	Text txt;
	Text desc;
 
	Font font;
	View view;
	Clock clock;
	vector<Texture> texture;
	vector<Text> text;
 

	vector<RectangleShape> image;
};

