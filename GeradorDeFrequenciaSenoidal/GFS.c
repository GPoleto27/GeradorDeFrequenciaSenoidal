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
    int f = 0, t=1, xG = 0, yG = 0;
    double x = 50.0, y = 300.0, d = 1000;
    char *freq = malloc(4*sizeof(char)), *dur = malloc(4*sizeof(char));
    while(!slShouldClose()&&!slGetKey(SL_KEY_ESCAPE))
    {
        sprintf(dur, "%.1lf", (d/1000));
        sprintf(freq, "%d", f);
        slSetForeColor(1,1,1,1);
        slSetFontSize(40);
        slText (400, 550, "Gerador de Frequencia Senoidal");
        slRectangleOutline (400, 300, 700, 400);
        slText(625, 50, freq);
        slText(725, 50, "Hz");
        slText(125, 50, dur);
        slText(225, 50, "s");

        slSetForeColor(0,1,0,1); ///Verde
        slText(400, 15, "EXECUTAR");
        slText(175, 50, "+");
        slText(675, 50, "+");

        slSetForeColor(1,0,0,1);
        slText(75, 50, "-");
        slText(575, 50, "-");

        while (x <= 750)
        {
            y = 300+(175*sin(-(f*2*PI)*t));
            xG = (int)x;
            yG = (int)y;
            slPoint(xG,yG);
            x +=0.01;
            t++;
        }
        x = 50.0;
        t = 0;

        if (slGetMouseX()> 60 && slGetMouseX()< 85 && slGetMouseY() > 25 &&  slGetMouseY() < 75 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) /// - ms
        {
            if (d > 100)
                d -=100;
        }

        if (slGetMouseX()> 560 && slGetMouseX()< 585 && slGetMouseY() > 25 &&  slGetMouseY() < 75 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) /// - ms
        {
            if (f >= 0)
                f -=1;
        }

        if (slGetMouseX()> 160 && slGetMouseX()< 185 && slGetMouseY() > 25 &&  slGetMouseY() < 75 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) /// - ms
        {
            if (d < 30000)
                d +=100;
        }

        if (slGetMouseX()> 660 && slGetMouseX()< 685 && slGetMouseY() > 25 &&  slGetMouseY() < 75 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) /// - ms
        {
            if (f < 9999)
                f +=1;
        }

        if (slGetMouseX()> 315 && slGetMouseX()< 475 && slGetMouseY() > 10 &&  slGetMouseY() < 50 && slGetMouseButton(SL_MOUSE_BUTTON_LEFT)) /// - ms
            Beep(f, d);

        slRender();
    }
    return 0;
}
