#include "arrow.h"
#include "keybinds.h"
#define GENERATION_POINT 1000
 arrow::arrow() {


	nothit_arrow.loadFromFile("Assets\\Sprites\\Arrow\\arrow_nothit.png");
	hit_arrow.loadFromFile("Assets\\Sprites\\Arrow\\arrow_hit.png");
	rarrow.setPosition(Vector2f((1000 / 2) + 60, 0));
	uarrow.setPosition(Vector2f((1000 / 2)  , 50));
	darrow.setPosition(Vector2f((1000 / 2)  + 50, 50));
	larrow.setPosition(Vector2f((1000/2) - 50 , 50));
	// left arrow & rotation & position & size
	larrow.setSize(Vector2f(100, 100));
	larrow.setTexture(&nothit_arrow);
	left_arrow_size = larrow.getGlobalBounds();
	larrow.setOrigin(Vector2f(left_arrow_size.width / 2, left_arrow_size.height / 2));
	larrow.rotate(-180);

 	// up arrow & rotation & position & size
	uarrow.setSize(Vector2f(100, 100));
	uarrow.setTexture(&nothit_arrow);
	up_arrow_size = uarrow.getGlobalBounds();
	uarrow.setOrigin(Vector2f(up_arrow_size.width / 2, up_arrow_size.height / 2));
	uarrow.rotate(-90);
 
	// down arrow & rotation & position & size
	darrow.setSize(Vector2f(100, 100));
	darrow.setTexture(&nothit_arrow);
	down_arrow_size = darrow.getGlobalBounds();
	darrow.setOrigin(Vector2f(down_arrow_size.width / 2, down_arrow_size.height / 2));
	darrow.rotate(90);

	// right arrow & rotation & position & size
	rarrow.setSize(Vector2f(100, 100));
	rarrow.setTexture(&nothit_arrow);

	// all arrows are stored in a database that will contain the files data for usage
	vec_arrow.push_back(larrow);
	vec_arrow.push_back(uarrow);
	vec_arrow.push_back(darrow);
	vec_arrow.push_back(rarrow);
	// temp positions

}
void arrow::draw(RenderWindow& window) {

 

 
	for (int i = 0; i < vec_arrow.size(); i++) {
		
		
		window.draw(vec_arrow[i]);

	} 

 


}
// defining left arrow
leftArrow::leftArrow() {
	nothit_arrow.loadFromFile("Assets\\Sprites\\Arrow\\arrow_nothit.png");

	larrow.setSize(Vector2f(100, 100));
	left_arrow_size = larrow.getGlobalBounds();
	larrow.setOrigin(Vector2f(left_arrow_size.width / 2, left_arrow_size.height / 2));
	larrow.rotate(-180);
	larrow.setPosition(Vector2f((1000 / 2) - 50, GENERATION_POINT));
}


void leftArrow::draw(RenderWindow& window) {
	larrow.setTexture(&nothit_arrow);

	window.draw(larrow);


}
void leftArrow::move(float y) {

	larrow.move(0 , y);

}
// defining up arrow

upArrow::upArrow() {
	nothit_arrow.loadFromFile("Assets\\Sprites\\Arrow\\arrow_nothit.png");

	uarrow.setSize(Vector2f(100, 100));
	up_arrow_size = uarrow.getGlobalBounds();
	uarrow.setOrigin(Vector2f(up_arrow_size.width / 2, up_arrow_size.height / 2));
	uarrow.rotate(-90);
	uarrow.setPosition(Vector2f((1000 / 2), GENERATION_POINT));
}


void upArrow::draw(RenderWindow& window) {
	uarrow.setTexture(&nothit_arrow);

	window.draw(uarrow);


}
void upArrow::move(float y) {

	uarrow.move(0, y);

}
// defining down arrow

downArrow::downArrow() {
	nothit_arrow.loadFromFile("Assets\\Sprites\\Arrow\\arrow_nothit.png");

	darrow.setSize(Vector2f(100, 100));
	down_arrow_size = darrow.getGlobalBounds();
	darrow.setOrigin(Vector2f(down_arrow_size.width / 2, down_arrow_size.height / 2));
	darrow.rotate(90);
	darrow.setPosition(Vector2f((1000 / 2) + 50, GENERATION_POINT));
}


void downArrow::draw(RenderWindow& window) {
	darrow.setTexture(&nothit_arrow);

	window.draw(darrow);


}
void downArrow::move(float y) {

	darrow.move(0, y);

}


// right Arrow

rightArrow::rightArrow() {
	nothit_arrow.loadFromFile("Assets\\Sprites\\Arrow\\arrow_nothit.png");

	rarrow.setSize(Vector2f(100, 100));
 	rarrow.setPosition(Vector2f((1000 / 2) + 60, GENERATION_POINT));
}


void rightArrow::draw(RenderWindow& window) {
	rarrow.setTexture(&nothit_arrow);

	window.draw(rarrow);


}
void rightArrow::move(float y) {

	rarrow.move(0, y);

}
