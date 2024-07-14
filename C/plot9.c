#include"image_utils.h"
#include<math.h>
#include <complex.h>
#include <stdlib.h>
float complex powo (float complex cnum1)
{
    float R = crealf(cnum1) * crealf(cnum1) - cimagf(cnum1) * cimagf(cnum1);
    float i=  crealf(cnum1)  * cimagf(cnum1) +  crealf(cnum1)  * cimagf(cnum1);
    float complex com=R+i*I;
    return com;
}

float mandelbrot(float complex c)
{
    int MAX_ITER = 30;
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
    float m=0;int MAX_ITER = 30;int i=0;
    BitMapFile  myImage;
    InitImage(&myImage, 1300, 2000);
    myImage.bmHeader.colorIdx[0].r= 255;
    myImage.bmHeader.colorIdx[1].g = 255;
    myImage.bmHeader.colorIdx[2].b = 255;
    myImage.bmHeader.colorIdx[3].r= 255;myImage.bmHeader.colorIdx[3].g= 255;
    myImage.bmHeader.colorIdx[4].g = 255;myImage.bmHeader.colorIdx[4].b = 255;
    myImage.bmHeader.colorIdx[5].r = 225;myImage.bmHeader.colorIdx[4].b = 255;
    myImage.bmHeader.colorIdx[6].r= 191;myImage.bmHeader.colorIdx[6].g= 191;myImage.bmHeader.colorIdx[6].b= 191;
    myImage.bmHeader.colorIdx[7].r=0;myImage.bmHeader.colorIdx[6].g=0;myImage.bmHeader.colorIdx[6].b=0;
    for(int x=0; x<2000; x++)
    {
        for(int y=0; y<1300; y++)
        {
            float real=-2.5+(float)x/2000*4;
            float image=-1.5+(float)y/1300*3;
            float complex C=real+image*I;
            m = mandelbrot(C);
            if (m<MAX_ITER)
            {
                if(i<=6)
                    myImage.bmData[2000*y +x*2000] =i;
                else
                    i=0;
                    myImage.bmData[2000*y +x] =i;
                
            }
            else
            {
                myImage.bmData[y*2000+ x] = 7;
            }
            i++;
        }
    }
    
    WriteBitmapFile("simple_test9.bmp", &myImage);
}