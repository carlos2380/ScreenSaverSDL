#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;

class Font;

class FontManager
{
public:
	FontManager();
	~FontManager();
	bool setFont(string font);
	vector<int> getRenders();

private:
	string textToPrint;
	map<string, string> fonts;


};

