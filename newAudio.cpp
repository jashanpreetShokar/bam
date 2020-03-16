#include "newAudio.h"
newAudio::newAudio(string src) {




	if (!music.openFromFile(src)) {
		cout << "[error]: " << "Failed to launch " << src << endl;
		exit(-1);

	}


	music.play();

}