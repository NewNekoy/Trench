#include "SFML_Gestion.h"

SFML_Gestion::SFML_Gestion()
{
    window.create(VideoMode(800, 600), "Trench");
    window.setFramerateLimit(60);
    font.loadFromFile("asset/font/arial.ttf");
    text.setFont(font);
}

void SFML_Gestion::printText(string str, Vector2f vec, int charSize, Color color)
{
	text.setFillColor(color);
	text.setString(str);
	text.setCharacterSize(charSize);
	text.setPosition(vec);
	window.draw(text);
}

void SFML_Gestion::close()
{
    window.close();
}

SFML_Gestion::~SFML_Gestion()
{

}
