#include "Game.h"
#include "map_selection.h"
 
MainMenu::MainMenu(RenderWindow& window)
{
	

	this->font.loadFromFile("Assets\\Font\\Poppins-Bold.ttf");
	

	o_text1.setString("READY!");
	o_text1.setStyle(Text::Italic);
	o_text1.setPosition(window.getSize().x / 3, window.getSize().y / 3);
 
 
	o_text1.setFont(this->font);
 

	text.push_back(o_text1);
 
}
bool Y_working = false;
void MainMenu::draw(RenderWindow& window)
{
	
 
	 x = Mouse::getPosition(window).x , y = Mouse::getPosition(window).y;
 

	if (x <= 1000) {
		view.setCenter(x / 2 + 400, y / 2 + 400);

	}
 


  
	if (Y_working) {
		view.setCenter(0, y / 2 + 400);
	}
	window.setView(view);
 
	for (int i = 0; i < text.size(); i++) {
	// right col
		if (text[i].getPosition().x < 0) {
			text[i].setPosition(0.f, text[i].getPosition().y);

	}
	// top col
		if (text[i].getPosition().y < 0) {
			text[i].setPosition(text[i].getPosition().y, 0.f );

		}
	// right
		if (text[i].getPosition().x + text[i].getGlobalBounds().width > window.getSize().x) {
			text[i].setPosition(window.getSize().x - text[i].getGlobalBounds().width, 0.f);

		}
	//top 
		if (text[i].getPosition().y + text[i].getGlobalBounds().height > window.getSize().y) {
			text[i].setPosition( 0.f, window.getSize().y - text[i].getGlobalBounds().height);

		}

		if (text[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {

			text[i].setFillColor(Color::Red);
 			if (Mouse::isButtonPressed(Mouse::Left)) {
				text[i].setFillColor(Color::Magenta);
								
				should_running = false;
 
				}


		}
		else {
			text[i].setFillColor(Color::White);
 
		}
		if (Keyboard::isKeyPressed(Keyboard::Return)) {
			should_running = false;

		}
		window.draw(text[i]);
 
	
	}

}




