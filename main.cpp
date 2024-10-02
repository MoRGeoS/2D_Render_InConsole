#include <iostream>
#include <thread>
#include <chrono>

#include "Draw.h"

void setConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD dwMode = 0;
    GetConsoleMode(hConsole, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hConsole, dwMode);
}

int main()
{
    setConsole();
    std::thread render(Render);
    std::thread draw(Draw);
    std::thread fps(Fps);
    while (isRunning)
    {
        //Your code if you need one
    }
    fps.detach();
    render.detach();
    draw.detach();
}
