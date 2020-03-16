#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "map_selection.h"
#include "rhythm_client.h"
#include "Map.h"
#include "Button.h"
using namespace std; using namespace sf;
 

/*


Current node grid:

[startup]->[gameselection]->[game]
 Infomation:
 re-include sfml [fixed]
 entry point issue is something wrong with the dlls or the program itself
 diagonse the issue [fixed]

 
*/
// welcome back to installing sfml 2.5.1

#include <string>
#define FCAP 15
int main() {

	RenderWindow window(VideoMode(1000,1000), "BAM! v.0.5 [inbuilding]", Style::Close  );
	MainMenu mu(window);
	Button button(Vector2f(window.getSize().x / 2, window.getSize().y / 2), "Bugs are commonly visible here.\n [Press the button if you agree]", "Poppins-Bold.ttf", Vector2f(200, 50));
	map_selection ms(window);
	rhythm_client rc(window  );
	rc.speed = -160;
	rc.EnableDebug = false; 
	Text text;
	Font font;
	font.loadFromFile("Assets\\Font\\Poppins-Bold.ttf");
	text.setFont(font);
 	text.setCharacterSize(15);
	rc.EnableDebug = true;
	window.setFramerateLimit(FCAP);
	bool focused = true;
	text.setPosition(Vector2f(window.getPosition().x  , 900));
	if (rc.EnableDebug) {
		text.setString("Orbital.tech\nDebugging Mode");
	}
	else {
		text.setString("Orbital.tech\n          2020");

	}
	while (window.isOpen()) {



		Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed) {

				window.close();

			}
			if (evnt.type == evnt.GainedFocus) {
				focused = true;
			}
			if (evnt.type == evnt.LostFocus) {
				focused = false;
			}
		}
		window.clear();
 
		if (button.isPressed) {
			if (mu.should_running) {
				 mu.draw(window);
			}

			if (!mu.should_running && !ms.ms_song_selected ) {
				ms.draw(window);
			}
			if (ms.ms_song_selected  ) {
				StartMap(rc);
				rc.draw(window , "ra'am.wav");

			}
		}
		else {
			button.draw(window);

		}
		

	 
		window.setView(window.getDefaultView());
		window.draw(text);

		window.display();

	}
	return 0;

}
 