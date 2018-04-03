#ifndef CONSTS_H
#define CONSTS_H

#include <SFML\Graphics.hpp>
#include <windows.h>

using namespace sf;

const double k = 2; /// показывает, во сколько раз размеры стены(дальней)
/// меньше размера главного окна
RenderWindow window (VideoMode(500, 500), "Arkanoid");
RectangleShape Wall (Vector2f(window.getSize().x/k, window.getSize().y/k));

VertexArray line1 (sf::Lines, 2);
VertexArray line2 (sf::Lines, 2);
VertexArray line3 (sf::Lines, 2);
VertexArray line4 (sf::Lines, 2);

HWND NotAcces[274];
int NotAcces_Size = 0;
bool Acces_Current_Window;

#endif // CONSTS_H
