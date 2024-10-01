#include <string>
#include <iostream>
#include <vector>

bool isRunning = true;
bool isFirst = true;

std::vector<std::vector<bool>> map = 
{
{0, 1, 0},
{1, 0, 1},
{1, 1, 1,}
};

std::string FirstBuffer;
std::string SecondBuffer;

std::string* pFirstBuffer = &FurstBuffer;
std::string* pSecondBuffer = &SecondBuffer;

void Render()
{
  while(isRunning)
    {
      *pSecondBuffer = "\x1B[2J\x1B[H";
      for (int y = 0; y < map.size(); y++)
        {
          for (int x = 0; x < map[y].size(); x++)
            {
              if(map[y][x])
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
      while(isFrame && !isFirst)
        {
          std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
      isFrame = true;
      isFirst = false;
    }
}

void Draw()
{
  while(isRunning)
    {
      if(isFrame)
      {
        std::cout << *pFirstBuffer;
        std::swap(pFirstBuffer, pSecondBuffer);
        isFrame = false;
      }
    }
  if(GetAsyncKeyState(VK_ESCAPE))
  {
    isRunning = false;
  }
}
