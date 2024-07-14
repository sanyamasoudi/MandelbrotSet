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
    int MAX_ITER = 37;
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
    float m=0;int MAX_ITER = 37;
    BitMapFile  myImage;
    InitImage(&myImage, 1300, 2000);
    myImage.bmHeader.colorIdx[0].r= 0;myImage.bmHeader.colorIdx[0].g= 0;myImage.bmHeader.colorIdx[0].b= 0;
    myImage.bmHeader.colorIdx[1].r = 153;myImage.bmHeader.colorIdx[1].g= 150;myImage.bmHeader.colorIdx[1].b= 204;
    myImage.bmHeader.colorIdx[2].r = 191;myImage.bmHeader.colorIdx[2].g= 62;myImage.bmHeader.colorIdx[2].b= 255;
    myImage.bmHeader.colorIdx[3].r= 178;myImage.bmHeader.colorIdx[3].g= 58;myImage.bmHeader.colorIdx[3].b= 238;
    myImage.bmHeader.colorIdx[4].r = 154;myImage.bmHeader.colorIdx[4].g = 50;myImage.bmHeader.colorIdx[4].b= 205;
    myImage.bmHeader.colorIdx[5].r = 104;myImage.bmHeader.colorIdx[5].g = 34;myImage.bmHeader.colorIdx[5].b= 139;
    myImage.bmHeader.colorIdx[6].r= 148;myImage.bmHeader.colorIdx[6].g= 0;myImage.bmHeader.colorIdx[6].b= 211;
    myImage.bmHeader.colorIdx[7].r= 255;myImage.bmHeader.colorIdx[7].g= 240;myImage.bmHeader.colorIdx[7].b= 245;
    myImage.bmHeader.colorIdx[8].r= 30;myImage.bmHeader.colorIdx[8].g= 144;myImage.bmHeader.colorIdx[8].b= 255;
    myImage.bmHeader.colorIdx[9].r = 28;myImage.bmHeader.colorIdx[9].g= 134;myImage.bmHeader.colorIdx[9].b= 238;
    myImage.bmHeader.colorIdx[10].r = 24;myImage.bmHeader.colorIdx[10].g= 116;myImage.bmHeader.colorIdx[10].b= 205;
    myImage.bmHeader.colorIdx[11].r= 16;myImage.bmHeader.colorIdx[11].g= 78;myImage.bmHeader.colorIdx[11].b=139;
    myImage.bmHeader.colorIdx[12].r = 224;myImage.bmHeader.colorIdx[12].g = 102;myImage.bmHeader.colorIdx[12].b= 255;
    myImage.bmHeader.colorIdx[13].r = 209;myImage.bmHeader.colorIdx[13].g = 95;myImage.bmHeader.colorIdx[13].b= 238;
    myImage.bmHeader.colorIdx[14].r= 255;myImage.bmHeader.colorIdx[14].g= 62;myImage.bmHeader.colorIdx[14].b= 150;
    for(int x=0; x<2000; x++)
    {
        for(int y=0; y<1300; y++)
        {
            float real=-2.5+(float)x/2000*4;
            float image=-1.5+(float)y/1300*3;
            float complex C=real+image*I;
            m = mandelbrot(C);
            if(4.8<m && m<5)
            {
                myImage.bmData[y*2000 + x] =8;
            }
            else if(5<m && m<5.3)
            {
               myImage.bmData[y*2000 + x] =9; 
            }
            else if(5.3<m && m<6)
            {
               myImage.bmData[y*2000 + x] =10; 
            }
            else if(6<m && m<6.4)
            {
               myImage.bmData[y*2000 + x] =11; 
            }
            else if(7.5<m && m<8)
            {
               myImage.bmData[y*2000 + x] =7; 
            }
            else if(8<m && m<9.5)
            {
               myImage.bmData[y*2000 + x] =6; 
            }
            else if(9.5<m && m<12)
            {
               myImage.bmData[y*2000 + x] =5; 
            }
            else if(12<m && m<16.5)
            {
               myImage.bmData[y*2000 + x] =4; 
            }
            else if(16.5<m && m<17)
            {
               myImage.bmData[y*2000 + x] =3; 
            }
            else if(17<m && m<23)
            {
               myImage.bmData[y*2000 + x] =7; 
            }
            else if(23<m && m<30)
            {
               myImage.bmData[y*2000 + x] =1; 
            }
            else if(30<m && m<37)
            {
               myImage.bmData[y*2000 + x] =2; 
            }
            else if(m>37)
            {
                myImage.bmData[y*2000+ x] = 0;
            }
            
        }
    }
    
    WriteBitmapFile("simple_test13.bmp", &myImage);
}
    