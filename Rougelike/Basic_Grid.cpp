//Grid basisc testing

#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std;

int CordX = 4;
int CordY = 4;
bool running = true;
int speed = 1;

void globalCooldown()
{
    this_thread::sleep_for(std::chrono::milliseconds(200));
}

void grid()
{
    char map[10][10];
    for (int i = 0; i < 10; i++)
    {
        cout << "     ";
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = '=';
            if (j == CordX && i == CordY)
            {
                map[i][j] = 'X';
            }
            cout << map[i][j];
        }
        cout << endl;
    }
}

void movementCheck(int movement, char direction)
{    
    switch (direction)
    {
        case 'A':
        if (CordX + movement > -1)
        {
            CordX += movement;
        }
        break;
        case 'W':
        if (CordY + movement > -1)
        {
            CordY += movement;
        }
        break;
        case 'S':
        if (CordY + movement < 10)
        {
            CordY += movement;
        }
        break;
        case 'D':
        if ((CordX + movement) < 10)
        {
            CordX += movement;
        }
        break;
        default:
        cout << "You've meet a terribly ill fate.";
    }
}


void routines(int movement, char direction)
{
    movementCheck(movement, direction);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "     Thanks for playing this demo!\n     To move around press the W, A, S, D keys.\n     Have fun!\n\n\n";
    grid();
    globalCooldown();
}

void routines()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "     Thanks for playing this demo!\n     To move around press the W, A, S, D keys.\n     Have fun!\n\n\n";
    grid();
    globalCooldown();
}

int main ()
{
    routines();
    while (running)
    {
        if(GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            routines(speed * -1, 'A');
        }
        if(GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            routines(speed, 'D');
        }
        if(GetKeyState('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            routines(speed * -1, 'W');
        }
        if(GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            routines(speed, 'S');
        }
        if(GetKeyState('O') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            running = false;
        }
    }

    return 0;
}