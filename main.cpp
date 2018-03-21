
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

using namespace sf;

RenderWindow window (VideoMode(500, 500), "Arkanoid");


bool intersect(HWND h)
{
    Event event;

    if (h != window.getSystemHandle())
    {
        if (Mouse::isButtonPressed(Mouse::Left))
        {

        }
        else
        {
            FloatRect rect;
            RECT rect1 = {0};
            GetWindowRect(h, &rect1);
            rect.left = rect1.left;
            rect.top = rect1.top;
            rect.width = rect1.right-rect1.left;
            rect.height = rect1.bottom-rect1.top;
            FloatRect Window_Rect;
            Window_Rect.left = window.getPosition().x;
            Window_Rect.top = window.getPosition().y;
            Window_Rect.height = window.getSize().y;
            Window_Rect.width = window.getSize().x;

            if (rect != Window_Rect && Window_Rect.intersects(rect))
            {
                MoveWindow(h, window.getPosition().x, window.getPosition().y, 150, 150, true);

            }
        }

    }


}

BOOL CALLBACK fnEnumWindowProc(HWND hwnd, LPARAM lParam){

  intersect(hwnd);

  return TRUE;
}


int main()
{
    window.alert("hello, world");
while (window.isOpen())
    {
        Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
    }

    EnumWindows(fnEnumWindowProc, 0);

    window.clear(Color::Magenta);
    window.display();
    }


    return 0;
}
