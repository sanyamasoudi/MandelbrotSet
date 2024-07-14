#include"image_utils.h"
#include<math.h>
#include <complex.h>
#include <stdlib.h>
#include <complex.h>
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
    float n = 0;
    while (abs(z) <= 2 && n < MAX_ITER)
    {
        z = powo (z) + c;
        n += 1;
    }
    return n;
}
int main()
{
    float m=0;int MAX_ITER = 30;
    BitMapFile  myImage;
    InitImage(&myImage, 1300, 2000);
    myImage.bmHeader.colorIdx[0].r= 125;
    myImage.bmHeader.colorIdx[1].g = 25;
    myImage.bmHeader.colorIdx[2].b = 231;
    myImage.bmHeader.colorIdx[3].r= 63;myImage.bmHeader.colorIdx[3].g= 72;
    myImage.bmHeader.colorIdx[4].g = 97;myImage.bmHeader.colorIdx[4].b = 100;
    myImage.bmHeader.colorIdx[5].r = 197;myImage.bmHeader.colorIdx[4].b = 219;
    myImage.bmHeader.colorIdx[6].r= 12;myImage.bmHeader.colorIdx[6].g= 191;myImage.bmHeader.colorIdx[6].b= 191;
    myImage.bmHeader.colorIdx[7].r= 0;myImage.bmHeader.colorIdx[7].g= 0;myImage.bmHeader.colorIdx[7].b= 0;
    for(int x=0; x<2000; x++)
    {
        for(int y=0; y<1300; y++)
        {
            float real=-2.5+(float)x/2000*4;
            float image=-1.5+(float)y/1300*3;
            float complex C=real+image*I;
            m = mandelbrot(C);
            if (2<m && m<4)
            {
                myImage.bmData[y*2000 + x] =2;
                
            }
            else if (4<=m && m<7)
            {
                myImage.bmData[y*2000 + x] =3;
                
            }
            else if(7<m && m<12)
            {
               myImage.bmData[y*2000 + x] =1; 
            }
            else if(12<m && m<17)
            {
               myImage.bmData[y*2000 + x] =2; 
            }
            else if(12<m && m<17)
            {
               myImage.bmData[y*2000 + x] =3; 
            }
            else if(17<m && m<22)
            {
               myImage.bmData[y*2000 + x] =4; 
            }
            else if(22<m && m<30)
            {
               myImage.bmData[y*2000 + x] =6; 
            }
            else if(m>30)
            {
                myImage.bmData[y*2000+ x] = 7;
            }
            
        }
    }
    
    WriteBitmapFile("simple_test8.bmp", &myImage);
}