#include "Button.h"
Button::Button(Vector2f coords, string text, string font, Vector2f size )
{

	this->font.loadFromFile(font);
	this->text.setFont(this->font);
	button_hitbox.setSize(Vector2f(size.x  , size.y ));
	button_hitbox.setPosition(coords);
	this->text.setPosition(round(coords.x /2 ), round(button_hitbox.getLocalBounds().height / 3 + coords.y) );
	this->text.setCharacterSize(12);
	this->text.setString(text);
}

void Button::draw(RenderWindow& window)
{
	if (button_hitbox.getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {
		button_hitbox.setFillColor(Color(44, 44, 99));
		if (Mouse::isButtonPressed(Mouse::Left)) {
			isPressed = true;

		}
		this->text.setCharacterSize(13);

	}  
	else {
		button_hitbox.setFillColor(Color(44, 44, 77));
		this->text.setCharacterSize(12);

	}
	window.draw(button_hitbox);
	window.draw(text);


}
// button class used for creating buttons