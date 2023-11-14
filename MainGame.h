#pragma once

#include <SDL.h>
#include <stdio.h>
#include <iostream>

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
	MainGame();

	void run();
	

private:
	void initSystems();
	void gameLoop();
	void processInput();

	SDL_Window* mpWindow;
	SDL_Surface* mpScreenSurface;
	bool mSuccessInit;
	const int mScreenHeight;
	const int mScreenWidth;
	GameState mGameState;
};

