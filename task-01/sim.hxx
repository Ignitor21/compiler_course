#pragma once

static const int X_SIZE = 640;
static const int Y_SIZE = 480;

void sim_init();
void app();
void sim_exit();
void sim_flush();
int sim_should_quit();
void sim_draw_circle(int x0, int y0, int radius);
