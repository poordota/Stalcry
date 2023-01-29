#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
using namespace sf;

SoundBuffer destroyBuffer;
Sound destroySound;

SoundBuffer winBuffer;
Sound winSound;

SoundBuffer pressBuffer;
Sound pressSound;

Music music;
int destroyAudio(float volum) {
	if (!destroyBuffer.loadFromFile("audio/Destroy.ogg"))
		return -1;
	destroySound.setBuffer(destroyBuffer);
	destroySound.setVolume(volum);
	destroySound.play();
}

int winAudio() {
	
	if (!winBuffer.loadFromFile("audio/Win.ogg"))
		return -1;
	winSound.setBuffer(winBuffer);
	winSound.play();
}

int pressAudio() {

	if (!pressBuffer.loadFromFile("audio/Press.ogg"))
		return -1;
	pressSound.setBuffer(pressBuffer);
	pressSound.setVolume(50.f);
	pressSound.play();
}

