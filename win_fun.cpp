#include <iostream>
#include <windows.h>
//#include<winuser.h>
#include <math.h>
using namespace std;

void setposition_cmd(int x, int y)
{
    HANDLE hout;
    COORD coord;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hout, coord);
}

int cmd_mouse()
{
    POINT P;
    POINT positions[20];

    int position[100][2];
    int j = 0;

    setposition_cmd(0, 1);
    cout << "click position:" << endl;

    while (1)
    {
        GetCursorPos(&P);
        int x1 = P.x;
        int y1 = P.y;

        setposition_cmd(0, 0);
        cout << "     "
             << " "
             << "     " << endl;
        setposition_cmd(0, 0);
        cout << P.x << " " << P.y << endl;

        if (GetAsyncKeyState(VK_LBUTTON))
        {
            setposition_cmd(0, j + 2);
            cout << j << ":" << P.x << " " << P.y << endl;
            j++;
        }

        Sleep(30);
    }
    //system("pause");
    return 0;
    //CreateProcess()
}

void useless()
{
    //SetCursorPos(0, 0);鼠标移位
    //mouse_event(0, 0, 0, 0, 0);按键模拟
}

int fun_round(int x1, int y1, int R)
{
    int x = x1 - R;
    int y;
    bool flag = true;
    while (1)
    {
        if (x == x1 - R)
        {
            flag = true;
        }
        if (x == x1 + R)
        {
            flag = false;
        }
        if (flag == true)
        {
            x++;
            y = sqrt(pow(R, 2) - pow((x - x1), 2)) + y1;
        }
        else
        {
            x--;
            y = -sqrt(pow(R, 2) - pow((x - x1), 2)) + y1;
        }
        SetCursorPos(x, y);
        Sleep(5);
    }
}
int main()
{
    //fun_round(942,588,30);
    cmd_mouse();
}