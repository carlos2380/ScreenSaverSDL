#include <SDL.h>
#include <string>
#include <vector>
using namespace std;
class Font
{
public:
	Font();
	~Font();

	//Loads image at specified path
	bool loadFromFile(string path, SDL_Renderer* gRenderer);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL, SDL_Renderer* gRenderer);

	//Gets image dimensions
	int getWidth();
	int getHeight();

	vector<SDL_Rect> getSpriteVect(string text);

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;

	//Number of letters;
	int numLetters;
};

