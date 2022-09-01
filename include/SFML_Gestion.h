#ifndef SFML_GESTION_H
#define SFML_GESTION_H

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class SFML_Gestion
{
public:
    SFML_Gestion();
    ~SFML_Gestion();

    void close();
    void printText(string str, Vector2f vec, int charSize, Color color);

    RenderWindow window;
    Event event;
private:
    Text text;
    Font font;
};

#endif // SFML_GESTION_H
