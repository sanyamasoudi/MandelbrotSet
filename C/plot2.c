#include"image_utils.h"
#include<math.h>
#include <complex.h>
#include <stdlib.h>

const long long int MAX_ITER = 80;

float complex powo (float complex cnum1)
{
    float R = crealf(cnum1) * crealf(cnum1) - cimagf(cnum1) * cimagf(cnum1);
    float i=  crealf(cnum1)  * cimagf(cnum1) +  crealf(cnum1)  * cimagf(cnum1);
    float complex com=R+i*I;
    return com;
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
    float m=0;
    BitMapFile  myImage;
    InitImage(&myImage, 1300, 2000);
    // myImage.bmHeader.colorIdx[0].g = 255;
    myImage.bmHeader.colorIdx[0].r= 233;
    myImage.bmHeader.colorIdx[1].g = 125;
    myImage.bmHeader.colorIdx[2].b = 15;
    for(int x=0; x<2000; x++)
    {
        for(int y=0; y<1300; y++)
        {
            float real=-2.5+(float)x/2000*4;
            float image=-1.5+(float)y/1300*3;
            float complex C=real+image*I;
            m = mandelbrot(C);
            if (m<=30)
            {
                myImage.bmData[y*2000 + x] = 1;
            }
            else
            {
                myImage.bmData[y*2000+ x] = 0;
            }
        }
    }
    
    WriteBitmapFile("simple_test2.bmp", &myImage);
}