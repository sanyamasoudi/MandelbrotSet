#include"image_utils.h"
#include<math.h>
#include <complex.h>
#include <stdlib.h>

const long long int MAX_ITER = 80;

float complex powo (float complex cnum1)
{
    float x = crealf(cnum1) * crealf(cnum1) - cimagf(cnum1) * cimagf(cnum1);
    float y=  crealf(cnum1)  * cimagf(cnum1) +  crealf(cnum1)  * cimagf(cnum1);
    float complex ans=x+y*I;
    return ans;
}

float mandelbrot(float complex c)
{
    float complex z = 0;
    float complex z1 = 0;
    float n = 0;
    while (abs(z) <= 2 && n < MAX_ITER)
    {
        z = powo (z) + c;
        n += 1;
    }

    if (n == MAX_ITER)
        return MAX_ITER;
    z1=abs(z);
    return n + 1 - log(log2(z1));
}

int main()
{
    float count=0;
    BitMapFile  myImage;
    InitImage(&myImage, 1300, 2000);
    // myImage.bmHeader.colorIdx[0].g = 255;
    myImage.bmHeader.colorIdx[0].r= 233;
    myImage.bmHeader.colorIdx[1].g = 125;
    myImage.bmHeader.colorIdx[2].b = 15;
    for(int i=0; i<2000; i++)
    {
        for(int j=0; j<1300; j++)
        {
            float x=-2.5+(float)i/2000*4;
            float y=-1.5+(float)j/1300*3;
            float complex mandel=x+y*I;
            count = mandelbrot(mandel);
            if (count<8)
            {
                myImage.bmData[j*2000 + i] = 1;
            }
            else if (count >8&&count <12)
            {
                myImage.bmData[j*2000 + i] = 2;
            }
            else if (count >15&&count <30)
            {
                myImage.bmData[j*2000 + i] = 2;
            }
            else
            {
                myImage.bmData[j*2000+ i] = 0;
            }
        }
    }
    
    WriteBitmapFile("simple_test1.bmp", &myImage);
}