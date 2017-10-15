#include "Font.h"
#include <SDL_image.h>


Font::Font()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;

	//Basic init
	numLetters = 96;
}


Font::~Font()
{
	//Deallocate
	free();
}

bool Font::loadFromFile(std::string path, SDL_Renderer* gRenderer)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void Font::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Font::render(int x, int y, SDL_Rect* clip, SDL_Renderer* gRenderer)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

vector<SDL_Rect> Font::getSpriteVect(string text)
{
	vector<SDL_Rect> gSpriteClips (text.length());
	for(int i = 0; i < text.length(); ++i)
	{
		int intChar = text[i];
		SDL_Rect sdlRect;
		sdlRect.x = (mWidth / numLetters)*(intChar-33);
		sdlRect.y = 0;
		sdlRect.w = mWidth/numLetters;
		sdlRect.h = mHeight;
		gSpriteClips[i] = sdlRect;
	}
	return gSpriteClips;
}

int Font::getWidth()
{
	return mWidth;
}

int Font::getHeight()
{
	return mHeight;
}