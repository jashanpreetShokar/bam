#include "map_selection.h"



map_selection::map_selection(RenderWindow& window) {


	this->font.loadFromFile("Assets\\Font\\Poppins-Bold.ttf");
	/*
	Map reader should go here.
	
	*/
	_image.setSize(Vector2f(200, 200));
	tutorialMap.loadFromFile("Assets\\imageIcon\\tutorial-Image-Icon.png");
	_image.setPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	_image.setTexture(&tutorialMap);
	image.push_back(_image);
	
 

	txt.setPosition(Vector2f(1000 / 2, 1000 / 2 + 50));
	txt.setString("?? - ra'am\nCreated by:Rulvent"); // title
	txt.setCharacterSize(19);
	txt.setFont(font);
	text.push_back(txt);


  
}

 
void map_selection::draw(RenderWindow& window) {
	window.setView(window.getDefaultView());
	
	for (int i = 0; i < image.size(); i++) {
		
		if (image[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {

			image[i].setFillColor(Color(255, 255, 255, 255 / 2));
			if (Mouse::isButtonPressed(Mouse::Left)) {
				 


 
			 
					ms_song_selected = true;
			 





				
			}

 
			for (int i = 0; i < text.size(); i++) {
				window.draw(text[i]);
			}
			 
		}
		else {
			image[i].setFillColor(Color(255, 255, 255 , 255 ));
		}

		window.draw(image[i]);
	}




}