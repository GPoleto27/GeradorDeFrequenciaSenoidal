#include "sl.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define PI 3.141592
int main ()
{
    slWindow(800, 600, "Gerador de Frequência Senoidal", 0);
    slSetFont(slLoadFont("arial_narrow_7.ttf"), 24);
    slSetTextAlign(SL_ALIGN_CENTER);
    int f = 0, t = 0, xG = 0, yG = 0;
    double x = 50.0, y = 300.0, d = 1000;
    char *freq = malloc(4*sizeof(char)), *dur = malloc(4*sizeof(char));
    while(!slShouldClose()&&!slGetKey(SL_KEY_ESCAPE))
    {
        slSetFontSize(24);
        sprintf(dur, "%.1lf", (d/1000));
        sprintf(freq, "%d", f);
        slSetForeColor(1,1,1,1);
        slText(125, 510, "Escala x = 1:69");
        slSetFontSize(40);
        slText (400, 550, "Gerador de Frequencia Senoidal");
        slRectangleOutline (399, 300, 697, 400);
        slText(625, 50, freq);
        slText(725, 50, "Hz");
        slText(125, 50, dur);
        slText(225, 50, "s");

        slSetForeColor(0,1,0,1); ///Verde
        slText(400, 15, "EXECUTAR");
        slText(175, 50, "+");
        slText(675, 50, "+");
        slLine(50,300,747,300);

        slSetForeColor(1,0,0,1);
        slText(75, 50, "-");
        slText(575, 50, "-");

        while (x <= 747)
        {
            y = 300+(190*sin(-(f*2*PI)*t));
            xG = (int)x;
            yG = (int)y;
            slPoint(xG,yG);
            x +=0.01;
            t+=1;
        }
        x = 50.0;
        t = 0;

        if (slGetMouseX()> 60 && slGetMouseX()< 85 && slGetMouseY() > 25 &&  slGetMouseY() < 75 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) /// - ms
        {
            if (d > 100)
                d -=100;
        }

        if (slGetMouseX()> 560 && slGetMouseX()< 585 && slGetMouseY() > 25 &&  slGetMouseY() < 75 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) /// - f
        {
            if (f > 0)
            {
                if ((f-1)%69 == 0)
                    f-=1;
                else
                    f -=2;
            }
        }

        if (slGetMouseX()> 160 && slGetMouseX()< 185 && slGetMouseY() > 25 &&  slGetMouseY() < 75 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) /// + ms
        {
            if (d < 30000)
                d +=100;
        }

        if (slGetMouseX()> 660 && slGetMouseX()< 685 && slGetMouseY() > 25 &&  slGetMouseY() < 75 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) /// + f
        {
            if (f < 9999)
            {
                if ((f+1)%69 == 0)
                    f+=1;
                else
                    f +=2;
            }
        }

        if (slGetMouseX()> 315 && slGetMouseX()< 475 && slGetMouseY() > 10 &&  slGetMouseY() < 50) /// PLAY
        {
            if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
                Beep(f, d);
        }
        slRender();
    }
    return 0;
}
