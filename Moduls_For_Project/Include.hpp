#ifndef INCLUDE_H
#define INCLUDE_H

#include "Consts.hpp"

/*
    ���� ���� �������� �������, ������� ���������, ���������� �� ���� ���� � �����
    ���� �� ��������, � ���� ��, �� ������������ ����� ����� �������. �����, -1.
     _______
    |\  2  /|
    |1 |0| 3|
    |/  4  \|

      - ����� ��������
*/

/*
    �������, ������� ���������, ���������� �� ����� � 0 �������. ���� ��, �� ����������-
    �� true, ����� false
*/
bool Include_Point_In_0(double x_point, double y_point)
{
    double Left = window. Wall.getPosition().x;
    double Right = Right + Wall.getSize().x;
    double Top = Wall.getPosition().y;
    double Bottom = Top + Wall.getSize().y;

    if (x_point >= Left && x_point <= Right && y_point >= Top && y_point <= Bottom)
        return true;
    return false;
}

bool Include_Point_In_1(double x_point, double y_point)
{
    return false;
}

bool Include_Point_In_2(double x_point, double y_point)
{
    return false;
}

bool Include_Point_In_3(double x_point, double y_point)
{
    return false;
}

/*
    ���������� true, ���� ������������� r ���������� � 0 �������
*/
bool Include_Window_In_0(RECT r)
{
    if (Include_Point_In_0(r.left, r.top))
      if (Include_Point_In_0(r.right, r.top))
        if (Include_Point_In_0(r.left, r.bottom))
            if (Include_Point_In_0(r.right, r.bottom))
                 return true;
    return false;
}

bool Include_Window_In_1(RECT r)
{
    if (Include_Point_In_1(r.left, r.top))
      if (Include_Point_In_1(r.right, r.top))
        if (Include_Point_In_1(r.left, r.bottom))
            if (Include_Point_In_1(r.right, r.bottom))
                 return true;
    return false;
}

bool Include_Window_In_2(RECT r)
{
    if (Include_Point_In_2(r.left, r.top))
      if (Include_Point_In_2(r.right, r.top))
        if (Include_Point_In_2(r.left, r.bottom))
            if (Include_Point_In_2(r.right, r.bottom))
                 return true;
    return false;
}

bool Include_Window_In_3(RECT r)
{
    if (Include_Point_In_3(r.left, r.top))
      if (Include_Point_In_3(r.right, r.top))
        if (Include_Point_In_3(r.left, r.bottom))
            if (Include_Point_In_3(r.right, r.bottom))
                 return true;
    return false;
}

/*
    ������� ���������� ����� �������, � ������� ��������� ������� ����. ���� ��
    ������ ������� ���(�.�. ���� �� ��������� ������� � ����� ���� �� ��������), ��
    ������������ -1
*/
int Include_Window_In_Sector(HWND h)
{
    RECT rect1 = {0};
    GetWindowRect(h, &rect1);

    if (Include_Window_In_0(rect1)) return 0;
    if (Include_Window_In_1(rect1)) return 1;
    if (Include_Window_In_2(rect1)) return 2;
    if (Include_Window_In_3(rect1)) return 3;
    return -1;
}

#endif // INCLUDE_H
