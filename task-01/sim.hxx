#pragma once

static const int X_SIZE = 640;
static const int Y_SIZE = 480;

void simInit();
void app();
void simExit();
void simFlush();
void simPutPixel(int x, int y, int argb);
int simRand();
