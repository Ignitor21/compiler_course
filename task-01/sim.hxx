#pragma once

static const int X_SIZE = 640;
static const int Y_SIZE = 480;

void sim_init();
void app();
void sim_exit();
void sim_flush();
int sim_should_quit();
void sim_draw_circle(int x0, int y0, int radius);
int sim_calculate_ray_length();
void sim_draw_rays(int x0, int y0, int rays_number, int ray_length);
int get_cos_precise(int angle_quarter_degrees);
int get_sin_precise(int angle_quarter_degrees);
