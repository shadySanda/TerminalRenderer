#include <iostream>
#include <math.h>

class Display
{

public:

    const static int xBufferSize = 20;
    const static int yBufferSize = 50;
    char buffer[xBufferSize][yBufferSize];

    void clearBuff()
    {
        for(int x=0; x<xBufferSize; x++)
        {
            for(int y=0; y<yBufferSize; y++)
            {
                buffer[x][y] = blank;
            }
        }
    }

    void fill()
    {
        for(int x=0; x<xBufferSize; x++)
        {
            for(int y=0; y<yBufferSize; y++)
            {
                buffer[x][y] = star;
            }
        }
    }

    void pixel(float x, float y, char val)
    {
        buffer[(int)x][(int)y] = val;
    }

    void print()
    {
        for(int x=0; x<xBufferSize; x++)
        {
            for(int y=0; y<yBufferSize; y++)
            {
                std::cout<<buffer[x][y];
            }
            std::cout<<'\n';
        }
    }

    void updateAndShow()
    {
        print();
        //sleep(50000);
        system(command);
    }

private:
    const char blank = ' ';
    const char star = '*';
    std::string str = "clear";
    const char *command = str.c_str();

};

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

Display display;
float x = 0.0f;
float y = 0.0f;
bool gotThereX = false;
bool gotThereY = false;

void moveAroundSIN()
{
    float xVal = map(sin(x), -1.0f, 1.0f, 0.0f, (float)display.xBufferSize);
    float yVal = map(sin(y), -1.0f, 1.0f, 10.0f, (float)display.yBufferSize);

    display.pixel(xVal, yVal, 'm');
    x += 0.1f;
    y += 0.09f;
}

void bounce()
{

    display.pixel(x, y, 'm');

    if(x < display.xBufferSize && gotThereX == false)
    {
        x = x +1;
    }
       
    if(x >= display.xBufferSize || gotThereX == true)
    {
        gotThereX = true;
        x = x -1;
    }

    if(x <= 0)
    {
        gotThereX = false;
    }

    if(y < display.yBufferSize && gotThereY == false)
    {
        y = y +1;
    }
        
    if(y >= display.yBufferSize || gotThereY == true)
    {
        gotThereY = true;
        y = y -1;
    }

    if(y <= 0)
    {
        gotThereY = false;
    }
}


int main()
{
    
    while(true)
    {
        display.clearBuff();

        bounce();

        display.updateAndShow();

    }

    return 0;
}