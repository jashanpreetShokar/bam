#pragma once
#include "SFML/Graphics.hpp"
#include <cmath>

using namespace std; using namespace sf;
class Button
{
public:
	Button(Vector2f coords, string text, string font, Vector2f size);

	void draw(RenderWindow& window);
	Text text;
	Font font;
	bool isPressed = false;
private:
	RectangleShape button_hitbox;



};

