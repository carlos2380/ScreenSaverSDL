#include <SDL.h>

class Canvas
{
public:

	//The window we'll be rendering to
	SDL_Window* gWindow = nullptr;
	//The window renderer
	SDL_Renderer* gRenderer = nullptr;

	Canvas();
	~Canvas();
	bool init();
	
};

