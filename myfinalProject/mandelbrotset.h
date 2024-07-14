#ifndef __MANDELBROTSET_H__
#define __MANDELBROTSET_H__

#include"defs.h"
#include<math.h>
#include<complex.h>

int MAX_ITER =8000;
float complex func(float complex cnum1)
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
        z = func(z) + c;
        n += 1;
    }
    
    if (n == MAX_ITER)
        return MAX_ITER;
    z1=abs(z);
    return n + 1 - log(log2(z1));
}
void UpdateImageData(ImageState* state)
{
    state->bmFileData.bmHeader.colorIdx[0].r= 0;state->bmFileData.bmHeader.colorIdx[0].g= 0;state->bmFileData.bmHeader.colorIdx[0].b= 0;
    state->bmFileData.bmHeader.colorIdx[1].r = 153;state->bmFileData.bmHeader.colorIdx[1].g= 150;state->bmFileData.bmHeader.colorIdx[1].b= 204;
    
    state->bmFileData.bmHeader.colorIdx[2].r = 191;
    state->bmFileData.bmHeader.colorIdx[2].g= 62;state->bmFileData.bmHeader.colorIdx[2].b= 255;
    state->bmFileData.bmHeader.colorIdx[3].r= 178;state->bmFileData.bmHeader.colorIdx[3].g= 58;state->bmFileData.bmHeader.colorIdx[3].b= 238;
    state->bmFileData.bmHeader.colorIdx[4].r = 154;state->bmFileData.bmHeader.colorIdx[4].g = 50;state->bmFileData.bmHeader.colorIdx[4].b= 205;
    state->bmFileData.bmHeader.colorIdx[5].r = 104;state->bmFileData.bmHeader.colorIdx[5].g = 34;state->bmFileData.bmHeader.colorIdx[5].b= 139;
    state->bmFileData.bmHeader.colorIdx[6].r= 148;state->bmFileData.bmHeader.colorIdx[6].g= 0;state->bmFileData.bmHeader.colorIdx[6].b= 211;
    state->bmFileData.bmHeader.colorIdx[7].r= 255;state->bmFileData.bmHeader.colorIdx[7].g= 240;state->bmFileData.bmHeader.colorIdx[7].b= 245;
    state->bmFileData.bmHeader.colorIdx[8].r= 30;state->bmFileData.bmHeader.colorIdx[8].g= 144;state->bmFileData.bmHeader.colorIdx[8].b= 255;
    state->bmFileData.bmHeader.colorIdx[9].r = 28;state->bmFileData.bmHeader.colorIdx[9].g= 134;state->bmFileData.bmHeader.colorIdx[9].b= 238;
    state->bmFileData.bmHeader.colorIdx[10].r = 24;state->bmFileData.bmHeader.colorIdx[10].g= 116;state->bmFileData.bmHeader.colorIdx[10].b= 205;
    state->bmFileData.bmHeader.colorIdx[11].r= 16;state->bmFileData.bmHeader.colorIdx[11].g= 78;state->bmFileData.bmHeader.colorIdx[11].b=139;
    state->bmFileData.bmHeader.colorIdx[12].r = 224;state->bmFileData.bmHeader.colorIdx[12].g = 102;state->bmFileData.bmHeader.colorIdx[12].b= 255;
    state->bmFileData.bmHeader.colorIdx[13].r = 209;state->bmFileData.bmHeader.colorIdx[13].g = 95;state->bmFileData.bmHeader.colorIdx[13].b= 238;
    state->bmFileData.bmHeader.colorIdx[14].r= 255;state->bmFileData.bmHeader.colorIdx[14].g= 62;state->bmFileData.bmHeader.colorIdx[14].b= 150;
    for(int x=0; x<state->width; x++)
    {
        for(int y=0; y<state->height; y++)
        {
            float re=state->minx+(float)x/(state->width)*(state->maxx-state->minx);
            float im=state->miny+(float)y/(state->height)*(state->maxy-state->miny);
            float rx = re * cos(state->angle) + im * sin(state->angle);
            float ry = -1*re * sin(state->angle) + im * cos(state->angle);
            float complex C=rx+ry*I;
            float m=mandelbrot(C);
            if(4.8<m && m<5)
            {
               state->bmFileData.bmData[y*state->width+x] =8;
            }
            else if(5<m && m<5.3)
            {
               state->bmFileData.bmData[y*state->width+x] =9; 
            }
            else if(5.3<m && m<6)
            {
               state->bmFileData.bmData[y*state->width+x] =10; 
            }
            else if(6<m && m<6.4)
            {
               state->bmFileData.bmData[y*state->width+x] =11; 
            }
            else if(7.5<m && m<8)
            {
               state->bmFileData.bmData[y*state->width+x] =7; 
            }
            else if(8<m && m<9.5)
            {
               state->bmFileData.bmData[y*state->width+x] =6; 
            }
            else if(9.5<m && m<12)
            {
               state->bmFileData.bmData[y*state->width+x] =5; 
            }
            else if(12<m && m<16.5)
            {
               state->bmFileData.bmData[y*state->width+x] =4; 
            }
            else if(16.5<m && m<17)
            {
               state->bmFileData.bmData[y*state->width+x] =3; 
            }
            else if(17<m && m<23)
            {
               state->bmFileData.bmData[y*state->width+x] =7; 
            }
            else if(23<m && m<30)
            {
               state->bmFileData.bmData[y*state->width+x] =1; 
            }
            else if(30<m && m<70)
            {
               state->bmFileData.bmData[y*state->width+x] =2; 
            }
            else if(70<m && m<MAX_ITER)
            {
               state->bmFileData.bmData[y*state->width+x] =7; 
            }
            else
            {
               state->bmFileData.bmData[y*state->width+x] =0;
            }
        }
    }
        
}

void ChangeCenter(ImageState* state, double newcx, double newcy, int steps)
{
    long double rx=(state->cx-newcx)/steps;
    long double ry=(state->cy-newcy)/steps;
    for(int i=0;i<steps; i++)
    {
        state->minx+=rx;state->maxx+=rx;
        state->miny+=ry;state->maxy+=ry;
        UpdateImageData(state);
        WriteBitmapFile(state->image_count++, & state->bmFileData);
    }
}

void ChangeZoom(ImageState* state,double zoom,double xpos,double ypos, int steps)
{
    long double Lxp=(long double)(state->maxx-xpos)/steps;
    long double Lxn=(long double)(xpos-state->minx)/steps;
    long double Lyp=(long double)(state->maxy-ypos)/steps;
    long double Lyn=(long double)(ypos-state->miny)/steps;
    if(zoom>1)
    {
        for(int i=0; i<zoom; i++)
        {
            state->maxx-=Lxp;
            state->minx+=Lxn;
            state->maxy-=Lyp;
            state->miny+=Lyn;
            UpdateImageData(state);
            WriteBitmapFile(state->image_count++, & state->bmFileData);
        }
    }
    else
    {
        for(int i=0; i<(int)(1/zoom); i++)
        {
            state->maxx+=Lxp;
            state->minx-=Lxn;
            state->maxy+=Lyp;
            state->miny-=Lyn;
            UpdateImageData(state);
            WriteBitmapFile(state->image_count++, & state->bmFileData);
        }
    }
}

void ChangeRotation(ImageState* state, double angle, int steps)
{
    angle=to_radian(angle);
    double angle_step = angle / steps;
    for(int i=0; i<steps; i++)
    {
        state->angle += angle_step;
        UpdateImageData(state);
        WriteBitmapFile(state->image_count++, & state->bmFileData);
    }
}

void Hold(ImageState* state, int steps)
{
    for(int i=0; i<steps; i++)
    {
        UpdateImageData(state);
        WriteBitmapFile(state->image_count++, & state->bmFileData);
    }
}

#endif