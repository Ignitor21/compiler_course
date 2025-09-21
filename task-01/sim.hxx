#pragma once

static const int X_SIZE = 512;
static const int Y_SIZE = 512;

void simInit();
void app();
void simExit();
void simFlush();
void simPutPixel(int x, int y, int argb);
int simRand();
