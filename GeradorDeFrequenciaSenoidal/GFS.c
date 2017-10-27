#include "sl.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define PI 3.141592
int main ()
{
    slWindow(1200, 600, "Gerador de Frequência Senoidal", 0);
    slSetFont(slLoadFont("arial_narrow_7.ttf"), 24);
    slSetTextAlign(SL_ALIGN_CENTER);
    int f1 = 552, f2 = 277, Ym1 = 125, Ym2 = 125, t1 = 1, t2 = 2, t = 0, tt = 0,
        xG = 0, yG = 0, mode = 0;
    double x = 50.0, y1 = 300.0, y2 = 300.0, yr = 0;
    short form1 = 0, form2 = 1, din1 = 0, din2 = 0, sinal1 = 0, sinal2 = 0;
    char    *Ym1c   = malloc(sizeof(char)),     *Ym2c   = malloc(sizeof(char)),
            *f1c    = malloc(sizeof(char)),     *f2c    = malloc(sizeof(char)),
            *t1c    = malloc(sizeof(char)),     *t2c    = malloc(sizeof(char)),
            *freq1  = malloc(5*sizeof(char)),   *freq2  = malloc(5*sizeof(char)),
            *modo   = malloc(sizeof(char)),     //*pos    = malloc(8*sizeof(char)),
            *posX   = malloc(3*sizeof(char)),   *posY   = malloc(3*sizeof(char));
    while(!slShouldClose()&&!slGetKey(SL_KEY_ESCAPE))
    {
        slSetForeColor(1,1,1,1);
        slSetFontSize(24);
        slText(25, 270, "0");
        slText(25,5,"-250");
        slText(25,525,"250");
        slText(710,5,"x = 697");
        sprintf(freq1, "%d", f1);
        sprintf(freq2, "%d", f2);
        sprintf(modo, "%d", mode+1);
        sprintf(Ym1c, "%d", Ym1);
        sprintf(Ym2c, "%d", Ym2);
        sprintf(t1c, "%d", t1);
        sprintf(t2c, "%d", t2);
        sprintf(f1c, "%d", f1);
        sprintf(f2c, "%d", f2);
        sprintf(posX, "%d", slGetMouseX()-50);
        sprintf(posY, "%d", slGetMouseY()-275);
        if (slGetMouseX()>= 50 && slGetMouseX()<= 747 && slGetMouseY() >= 25 &&  slGetMouseY() <= 525)
        {
            slLine(slGetMouseX(),25,slGetMouseX(),525);
            slSetFontSize(24);
            slText(slGetMouseX()-25,slGetMouseY(),posX);
            slText(slGetMouseX()+25,slGetMouseY(),posY);
            if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            {
                if (!mode)
                    Beep(f1, 1000);
                else if (mode == 1)
                    Beep(f2, 1000);
                else
                {
                    Sleep(100);
                    if(!din1)
                        din1 = 1;
                    if (!din2)
                        din2 = 1;
                    else if (din1 && din2)
                        din1 = din2 = 0;
                }
            }
        }
        slSetFontSize(40);
        slText (400, 550, "Gerador de Frequencia Senoidal");
        slRectangleOutline (399, 275, 697, 500);
        slLine(50,275,747,275);
        slText(985, 550,"Modo:");
        slText(1050, 550, modo);
        slSetForeColor(1,0,0,1);
        slText(1000, 475, "Onda 1:");
        if (!sinal1)
            slText(800, 425, "-");
        else
            slText(800, 425, "+");
        if (slGetMouseX()> 775 && slGetMouseX()< 825 && slGetMouseY() > 400 &&  slGetMouseY() < 450 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
        {
            Sleep(100);
            if (!sinal1)
                sinal1++;
            else
                sinal1 = 0;
        }
        if (slGetMouseX()> 900 && slGetMouseX()< 1100 && slGetMouseY() > 450 &&  slGetMouseY() < 500 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
        {
            Sleep(100);
            if (din1)
                din1 = 0;
            else
                din1 = 1;
        }
        slSetForeColor(1,1,1,1);
        if (!form1)
            slText(1000, 425, "seno");
        else
            slText(1000, 425, "cosseno");
        if (slGetMouseX()> 900 && slGetMouseX()< 1100 && slGetMouseY() > 400 &&  slGetMouseY() < 450 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
        {
            Sleep(100);
            if (form1)
                form1 = 0;
            else
                form1 = 1;
        }
        slText(800, 375, "Ym:");
        slText(1000, 375, Ym1c);
        slText(800, 325, "Hz:");
        slText(1000, 325, f1c);
        slText(800, 275, "T:");
        slText(1000, 275, t1c);
        if (mode)
        {
            slSetForeColor(0,0,1,1);
            slText(1000, 225, "Onda 2:");
            if (!sinal2)
                slText(800, 175, "-");
            else
                slText(800, 175, "+");
            if (slGetMouseX()> 775 && slGetMouseX()< 825 && slGetMouseY() > 150 &&  slGetMouseY() < 200 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            {
                Sleep(100);
                if (!sinal2)
                    sinal2++;
                else
                    sinal2 = 0;
            }
            if (slGetMouseX()> 900 && slGetMouseX()< 1100 && slGetMouseY() > 200 &&  slGetMouseY() < 250 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            {
                Sleep(100);
                if (din2)
                    din2 = 0;
                else
                    din2 = 1;
            }
            slSetForeColor(1,1,1,1);
            if (!form2)
                slText(1000, 175, "seno");
            else
                slText(1000, 175, "cosseno");
            if (slGetMouseX()> 900 && slGetMouseX()< 1100 && slGetMouseY() > 150 &&  slGetMouseY() < 200 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            {
                Sleep(100);
                if (form2)
                    form2 = 0;
                else
                    form2 = 1;
            }
            slText(800, 125, "Ym:");
            slText(1000, 125, Ym2c);
            slText(800, 75, "Hz:");
            slText(1000, 75, f2c);
            slText(800, 25, "T:");
            slText(1000, 25, t2c);
        }
        slSetForeColor(0,1,0,1); ///Verde
        slText(1100, 375, "+");
        if (slGetMouseX()> 1075 && slGetMouseX()< 1125 && slGetMouseY() > 350 &&  slGetMouseY() < 400 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            Ym1 += 1;
        slText(1100, 325, "+");
        if (slGetMouseX()> 1075 && slGetMouseX()< 1125 && slGetMouseY() > 300 &&  slGetMouseY() < 375 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            f1 += 1;
        slText(1100, 275, "+");
        if (slGetMouseX()> 1075 && slGetMouseX()< 1125 && slGetMouseY() > 250 &&  slGetMouseY() < 325 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
        {
            Sleep(100);
            t1 += 1;
        }
        if (mode)
        {
            slText(1100, 125, "+");
            if (slGetMouseX()> 1075 && slGetMouseX()< 1125 && slGetMouseY() > 100 &&  slGetMouseY() < 150 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
                Ym2 += 1;
            slText(1100, 75, "+");
            if (slGetMouseX()> 1075 && slGetMouseX()< 1125 && slGetMouseY() > 50 &&  slGetMouseY() < 100 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
                f2 += 1;
            slText(1100, 25, "+");
            if (slGetMouseX()> 1075 && slGetMouseX()< 1125 && slGetMouseY() > 0 &&  slGetMouseY() < 50 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            {
                Sleep(100);
                t2 += 1;
            }
        }
        slSetForeColor(1,0,0,1);
        slText(900, 375, "-");
        if (slGetMouseX()> 875 && slGetMouseX()< 925 && slGetMouseY() > 350 &&  slGetMouseY() < 400 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
        {
            if (Ym1 > 0)
                Ym1 -=1;
        }
        slText(900, 325, "-");
        if (slGetMouseX()> 875 && slGetMouseX()< 925 && slGetMouseY() > 300 &&  slGetMouseY() < 375 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
        {
            if (f1 > 0)
                f1 -= 1;
        }
        slText(900, 275, "-");
        if (slGetMouseX()> 875 && slGetMouseX()< 925 && slGetMouseY() > 250 &&  slGetMouseY() < 325 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
        {
            Sleep(100);
            if (t1 > 0)
                t1 -= 1;
        }
        if (mode)
        {
            slText(900, 125, "-");
            if (slGetMouseX()> 875 && slGetMouseX()< 925 && slGetMouseY() > 100 &&  slGetMouseY() < 150 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            {
                if (Ym2 > 0)
                    Ym2 -= 1;
            }
            slText(900, 75, "-");
            if (slGetMouseX()> 875 && slGetMouseX()< 925 && slGetMouseY() > 50 &&  slGetMouseY() < 100 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            {
                if (f2 > 0)
                    f2 -= 1;
            }
            slText(900, 25, "-");
            if (slGetMouseX()> 875 && slGetMouseX()< 925 && slGetMouseY() > 0 &&  slGetMouseY() < 50 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
            {
                Sleep(100);
                if (t2 > 0)
                    t2 -= 1;
            }
        }
        if (!mode)
        {
            while (x <= 747)
            {
                slSetForeColor(1,0,0,1); ///ONDA 1
                if (!form1) //0
                {
                    if (!sinal1)
                        y1 = 275+(Ym1*sin(-(f1*2*PI)*t));
                    else
                        y1 = 275+(Ym1*sin((f1*2*PI)*t));
                }
                else //1
                {
                    if (!sinal1)
                        y1 = 275+(Ym1*cos(-(f1*2*PI)*t));
                    else
                    y1 = 275+(Ym1*cos((f1*2*PI)*t));
                }
                if (y1 < 525 && y1 > 25)
                {
                    xG = round(x);
                    yG = round(y1);
                    slPoint(xG,yG);
                }
                x +=0.08;
                t+=t1;
            }
        }
        else if (mode == 1)
        {
            while (x <= 747)
            {
                slSetForeColor(1,0,0,1); ///ONDA 1
                if (!form1) //0
                {
                    if (!sinal1)
                        y1 = 275+(Ym1*sin(-(f1*2*PI)*t));
                    else
                        y1 = 275+(Ym1*sin((f1*2*PI)*t));
                }
                else //1
                        y1 = 275+(Ym1*cos((f1*2*PI)*t));
                if (y1 < 525 && y1 > 25)
                {
                    xG = round(x);
                    yG = round(y1);
                    slPoint(xG,yG);
                }
                slSetForeColor(0,0,1,1); ///ONDA 2
                if (!form2) //0
                {
                    if (!sinal2)
                        y1 = 275+(Ym2*sin(-(f2*2*PI)*tt));
                    else
                        y1 = 275+(Ym2*sin((f2*2*PI)*tt));
                }
                else //1
                        y1 = 275+(Ym2*cos((f2*2*PI)*tt));
                if (y1 < 525 && y1 > 25)
                {
                    yG = round(y1);
                    slPoint(xG,yG);
                }
                x += 0.08;
                t += t1;
                tt += t2;
            }
        }
        else if (mode == 2)
        {
            while (x <= 747)
            {
                slSetForeColor(1,0,0,1); ///ONDA 1
                if (!form1) //0
                {
                    if (!sinal1)
                        y1 = 275+(Ym1*sin(-(f1*2*PI)*t));
                    else
                        y1 = 275+(Ym1*sin((f1*2*PI)*t));
                }
                else //1
                        y1 = 275+(Ym1*cos((f1*2*PI)*t));
                if (y1 < 525 && y1 > 25)
                {
                    xG = round(x);
                    yG = round(y1);
                    slPoint(xG,yG);
                }
                slSetForeColor(0,0,1,1); ///ONDA 2
                if (!form2) //0
                {
                    if (!sinal2)
                        y2 = 275+(Ym2*sin(-(f2*2*PI)*tt));
                    else
                        y2 = 275+(Ym2*sin((f2*2*PI)*tt));
                }
                else //1
                        y2 = 275+(Ym2*cos(-(f2*2*PI)*tt));
                if (y2 < 525 && y2 > 25)
                {
                    yG = round(y2);
                    slPoint(xG,yG);
                }
                slSetForeColor(0,1,0,1); ///RESULTANTE
                yr = (y2 + y1)-275;
                if (yr < 525 && yr > 25)
                {
                    yG = round(yr);
                    slPoint(xG,yG);
                }
                x +=0.08;
                t += t1;
                tt += t2;
            }
        }
        else
        {
            while (x <= 747)
            {
                slSetForeColor(0,1,0,1); ///RESULTANTE
                if (!form1) //0
                {
                    if (!sinal1)
                        y1 = 275+(Ym1*sin(-(f1*2*PI)*t));
                    else
                        y1 = 275+(Ym1*sin((f1*2*PI)*t));
                }
                else //1
                        y1 = 275+(Ym1*cos((f1*2*PI)*t));
                if (!form2) //0
                {
                    if (!sinal2)
                        y2 = 275+(Ym2*sin(-(f2*2*PI)*tt));
                    else
                        y2 = 275+(Ym2*sin((f2*2*PI)*tt));
                }
                else //1
                        y2 = 275+(Ym2*cos((f2*2*PI)*tt));
                yr = (y2 + y1)-275;
                if (yr < 525 && yr > 25)
                {
                    xG = round(x);
                    yG = round(yr);
                    slPoint(xG,yG);
                }
                x +=0.08;
                t += t1;
                tt += t2;
            }
        }
        x = 50.0;
        if (!din1)
            t = 0;
        if (!din2)
            tt = 0;
        if (slGetMouseX()> 950 && slGetMouseX()< 1750 && slGetMouseY() > 500 &&  slGetMouseY() < 600 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
        {
            Sleep(100);
            if (mode == 3)
                mode = 0;
            else
                mode += 1;
        }
        slRender();
    }
    return 0;
}
