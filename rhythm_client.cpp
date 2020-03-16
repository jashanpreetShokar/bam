#include "rhythm_client.h"
#include "Collision.h" // for handling collision within the game
#include "newAudio.h"
 
rhythm_client::rhythm_client(RenderWindow& window) {

	background.loadFromFile("Assets\\Sprites\\game_back\\game_back.png");
	r_background.setTexture(&background);
	r_background.setSize(Vector2f(window.getSize().x, window.getSize().y));
 
	this->font.loadFromFile("Assets\\Font\\Poppins-Bold.ttf");
	text.setFont(font);
	error.loadFromFile("Assets\\Sprites\\Misses & Correction\\misses.png");
	Correct.loadFromFile("Assets\\Sprites\\Misses & Correction\\correct.png");
 
}

void rhythm_client::draw(RenderWindow& window , string source ) {
	

	window.draw(r_background);
	arrow.draw(window);
	window.draw(text);
	dTime = dClock.restart();
	// Optimization [back end] 
	// if any of the arrows are out of the screen they will be deleted to save framerate

	// right arrow
	for (int i = 0; i < ra.size(); i++) {
		if (ra[i].getRight().getPosition().x < 0 || ra[i].getRight().getPosition().x > window.getSize().x || // x axis if the arrow is out. don't even know why i would need this but ok 
			ra[i].getRight().getPosition().y < 0 || ra[i].getRight().getPosition().y > window.getSize().y    // y axis if the arrow is out. need this
			) {
			ra.erase(ra.begin() + i);

		}
	}
	// left arrow
	for (int i = 0; i < la.size(); i++) {
		if (la[i].getLeft().getPosition().x < 0 || la[i].getLeft().getPosition().x > window.getSize().x || // x axis if the arrow is out. don't even know why i would need this but ok 
			la[i].getLeft().getPosition().y < 0 || la[i].getLeft().getPosition().y > window.getSize().y    // y axis if the arrow is out. need this
			) {
			la.erase(la.begin() + i);

		}
	}
	// up arrow
	for (int i = 0; i < ua.size(); i++) {
		if (ua[i].getUp().getPosition().x < 0 || ua[i].getUp().getPosition().x > window.getSize().x || // x axis if the arrow is out. don't even know why i would need this but ok 
			ua[i].getUp().getPosition().y < 0 || ua[i].getUp().getPosition().y > window.getSize().y    // y axis if the arrow is out. need this
			) {
			ua.erase(ua.begin() + i);

		}
	}
	// down arrow

	for (int i = 0; i < da.size(); i++) {
		if (da[i].getDown().getPosition().x < 0 || da[i].getDown().getPosition().x > window.getSize().x || // x axis if the arrow is out. don't even know why i would need this but ok 
			da[i].getDown().getPosition().y < 0 || da[i].getDown().getPosition().y > window.getSize().y    // y axis if the arrow is out. need this
			) {
			da.erase(da.begin() + i);

		}
	}

	// left arrow
	if (leftarrow_generate == true) {
 		leftArrow lr;
		la.push_back(lr);
		leftarrow_generate = false;
	}
	for (int i = 0; i < la.size(); i++) {
		la[i].draw(window);
		la[i].move(speed * dTime.asSeconds() );
	}
	// up arrow
	if (uparrow_generate == true) {
 		upArrow uparrow;
		ua.push_back(uparrow);
		uparrow_generate = false;
	}
	for (int i = 0; i < ua.size(); i++) {
		ua[i].draw(window);
		ua[i].move(speed * dTime.asSeconds());
	}

	// down arrow
	if (downarrow_generate == true) {
 		downArrow downarrow;
		da.push_back(downarrow);
		downarrow_generate = false;
	}
	for (int i = 0; i < da.size(); i++) {
		da[i].draw(window);
		da[i].move(speed * dTime.asSeconds());
	}

	// right arrow


	if (rightarrow_generate == true) {
 		rightArrow downarrow;
		ra.push_back(downarrow);
		rightarrow_generate = false;
	}
	for (int i = 0; i < ra.size(); i++) {
		ra[i].draw(window);
		ra[i].move(speed * dTime.asSeconds());
	}


	// arrow left
	if (Keyboard::isKeyPressed(Keyboard::ARROW_LEFT)) {

		arrow.vec_arrow[0].setTexture(&arrow.hit_arrow);
		for (int i = 0; i < la.size(); i++) {
			if (Collision::PixelPerfectTest(arrow.vec_arrow[0], la[i].getLeft())) {
 				score++;

			}
			 
		}


	}
	else {

		arrow.vec_arrow[0].setTexture(&arrow.nothit_arrow);

	}
	// arrow up
	if (Keyboard::isKeyPressed(Keyboard::ARROW_UP)) {

		arrow.vec_arrow[1].setTexture(&arrow.hit_arrow);
		for (int i = 0; i < ua.size(); i++) {
			if (arrow.vec_arrow[1].getGlobalBounds().intersects(ua[i].getUp().getGlobalBounds())) {

				if (Collision::PixelPerfectTest(arrow.vec_arrow[1], ua[i].getUp())) {
 					score++;

				}

			}
			 
		}
	}
	else {

		arrow.vec_arrow[1].setTexture(&arrow.nothit_arrow);

	}
	// arrow down
	if (Keyboard::isKeyPressed(Keyboard::ARROW_DOWN)) {

		arrow.vec_arrow[2].setTexture(&arrow.hit_arrow);
		for (int i = 0; i < da.size(); i++) {
			if (Collision::PixelPerfectTest(arrow.vec_arrow[2] , da[i].getDown())) {
 				score++;

			}
		
		}
	}
	else {

		arrow.vec_arrow[2].setTexture(&arrow.nothit_arrow);

	}
	if (Keyboard::isKeyPressed(Keyboard::ARROW_RIGHT)) {
		arrow.vec_arrow[3].setTexture(&arrow.hit_arrow);

		for (int i = 0; i < ra.size(); i++) {
			if (Collision::PixelPerfectTest(arrow.vec_arrow[3], ra[i].getRight())) {
 				score++;
			}
			 
		}
	}
	else {

		arrow.vec_arrow[3].setTexture(&arrow.nothit_arrow);

	}

	if (music.getStatus() != music.Playing) {
		if (!isPlayed) {
			music.openFromFile(source);
			music.play();
			isPlayed = true;
		}

	}
	
	length = to_string(static_cast<int>(music.getPlayingOffset().asSeconds()) );
	musicLength = to_string(static_cast<int>(music.getDuration().asSeconds()));
	text.setString("Time Achived:" + length + "\nDesired Time:" + musicLength + "\nscore:" + to_string(score));
	if (static_cast<int>(music.getPlayingOffset().asSeconds()) == static_cast<int>(music.getDuration().asSeconds())) {
	cout << " game finished [should take back to main menu]" << endl;

 	}
 
	if (EnableDebug) {

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			leftarrow_generate = true;

		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {

			uparrow_generate = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			downarrow_generate = true;

		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			rightarrow_generate = true;

		}

	}

	

}



 