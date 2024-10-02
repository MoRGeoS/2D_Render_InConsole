#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>

bool isRunning = true;
bool isFirst = true;
bool isFrame = false;
int FPS = 0;
std::string msg;

std::vector<std::vector<bool>> map =
{
{0, 1, 0},
{1, 0, 1},
{1, 1, 1,}
};

std::string FirstBuffer;
std::string SecondBuffer;

std::string* pFirstBuffer = &FirstBuffer;
std::string* pSecondBuffer = &SecondBuffer;

void Render()
{
    while (isRunning)
    {
        *pSecondBuffer = "\x1B[2J\x1B[H";
        for (int y = 0; y < map.size(); y++)
        {
            for (int x = 0; x < map[y].size(); x++)
            {
                if (map[y][x])
                {
                    *pSecondBuffer += "#";
                }
                else
                {
                    *pSecondBuffer += " ";
                }

            }
            *pSecondBuffer += "\n";
        }
        while (isFrame && !isFirst)
        {
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
        isFrame = true;
        isFirst = false;
    }
}

void Draw()
{
    while (isRunning)
    {
        if (isFrame)
        {
            *pFirstBuffer += msg;
            std::cout << *pFirstBuffer;
            std::swap(pFirstBuffer, pSecondBuffer);
            isFrame = false;
            FPS++;
        }
    }
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        isRunning = false;
    }
}

void Fps()
{
    while (isRunning)
    {
        Sleep(1000);
        msg = "FPS: " + std::to_string(FPS);
        FPS = 0;
    }
}
