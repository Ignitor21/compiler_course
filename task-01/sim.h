#pragma once

static const int X_SIZE = 640;
static const int Y_SIZE = 480;

void sim_init(void);
void app(void);
void sim_exit(void);
void sim_flush(void);
int sim_should_quit(void);
void sim_put_pixel(int x, int y, int argb);
void sim_draw_line(int x0, int y0, int x1, int y1, int argb);
int sim_sqrt(int x);
int get_sin_precise(int angle_quarter_degrees);
int get_cos_precise(int angle_quarter_degrees);

