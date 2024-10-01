//Not Started Yet
#include <iostream>
#include <thread>
#include <chrono>

#include "Draw.h"

int main()
{
  std::thread render(Render);
  std::thread draw(Draw);
  while (isRunning)
    {
      //Your code if you need
    }
  render.detach();
  draw.detach();
}
