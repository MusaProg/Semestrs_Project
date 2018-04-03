#include <SFML/Graphics.hpp>
#include "Moduls_For_Project/Graphic.hpp"
#include "Moduls_For_Project/Intersect.hpp"
#include "Moduls_For_Project/Consts.hpp"
#include "Moduls_For_Project/Include.hpp"

using namespace sf;


BOOL CALLBACK fnEnumWindowProc(HWND hwnd, LPARAM lParam){

   if (isIntersect(window, hwnd))
   {
       double a = Include_Window_In_Sector(hwnd);
       if (a != -1)
       {
           std::cout << hwnd << " : " << a << "\n";
            MoveWindow(hwnd, window.getPosition().x, window.getPosition().y, 150, 150, true);
       }
   }

  return TRUE;
}



int main()
{
Sleep(5000);
window.setPosition(Vector2i(100, 100));
Initialize_NotAcces_Array();

while (window.isOpen())
    {
        Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
    }



    window.clear(Color::White);

    Draw(window, Wall, line1, line2, line3, line4);

    EnumWindows(fnEnumWindowProc, 0);

    window.display();

    }

    return 0;
}
