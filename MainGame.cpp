#include "MainGame.h"

MainGame::MainGame()
	: mpWindow(nullptr)
	, mpScreenSurface(nullptr)
	, mSuccessInit(true)
	, mScreenHeight(600)
	, mScreenWidth(800)
	, mGameState(GameState::PLAY)
{

}

void MainGame::run()
{
	initSystems();
	gameLoop();
}

void MainGame::initSystems()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		mSuccessInit = false;
	}
	else
	{
		//Create window
		mpWindow = SDL_CreateWindow("Reanimated", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
		if (mpWindow == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			mSuccessInit = false;
		}
		//else
		{
			//Get window surface
			mpScreenSurface = SDL_GetWindowSurface(mpWindow);
		}
	}
}

void MainGame::gameLoop()
{
	while (mGameState != GameState::EXIT)
	{
		processInput();
	}
}

void MainGame::processInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			mGameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << e.motion.x << " " << e.motion.y << std::endl;
			break;
		}
	}
}
