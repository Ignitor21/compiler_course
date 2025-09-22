#include "sim.hxx"

void draw_circle(int x0, int y0, int radius, int argb)
{
    for (int w = 0; w < 2 * radius; w++)
    {
        for (int h = 0; h < 2 * radius; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx*dx + dy*dy) <= (radius * radius))
                sim_put_pixel(x0 + dx, y0 + dy, argb);
        }
    }
}

int get_sin_precise(int angle_quarter_degrees)
{
    while (angle_quarter_degrees < 0)
        angle_quarter_degrees += 1440;
    while (angle_quarter_degrees >= 1440)
        angle_quarter_degrees %= 1440;

    if (angle_quarter_degrees <= 360)
        return sin_table_precise[angle_quarter_degrees];
    else if (angle_quarter_degrees <= 720)
        return sin_table_precise[720 - angle_quarter_degrees];
    else if (angle_quarter_degrees <= 1080)
        return -sin_table_precise[angle_quarter_degrees - 720];
    else
        return -sin_table_precise[1440 - angle_quarter_degrees];
}

int get_cos_precise(int angle_quarter_degrees) {
    return get_sin_precise(angle_quarter_degrees + 360);
}

void draw_rays(int x0, int y0, int rays_number, int ray_length, int argb)
{
    int angle_step = (360 * 4) / rays_number;

    for (int i = 0; i < rays_number; ++i)
    {
        int angle = i * angle_step;

        int sin_val = get_sin_precise(angle);
        int cos_val = get_cos_precise(angle);

        int x1 = x0 + (cos_val * ray_length) / 65535;
        int y1 = y0 + (sin_val * ray_length) / 65535;

        sim_draw_line(x0, y0, x1, y1, argb);
    }
}

void app() 
{
    int radius = 30;
    int perimeter = 2 * (X_SIZE + Y_SIZE - 4 * radius);
    int pos = 0;
    int speed = 4;
    int rays_number = 720;
    int ray_length = sim_calculate_ray_length();

    while (1)
    {
        if (sim_should_quit())
            return;

        sim_flush();

        int x = 0, y = 0;
        if (pos < X_SIZE - 2 * radius)
        {
            x = radius + pos;
            y = radius;
        }
        else if (pos < X_SIZE - 2 * radius + Y_SIZE - 2 * radius)
        {
            x = X_SIZE - radius;
            y = radius + (pos - (X_SIZE - 2 * radius));
        }
        else if (pos < 2 * (X_SIZE - 2 * radius) + Y_SIZE - 2 * radius)
        {
            x = (X_SIZE - radius) - (pos - (X_SIZE - 2 * radius + Y_SIZE - 2 * radius));
            y = Y_SIZE - radius;
        }
        else
        {
            x = radius;
            y = (Y_SIZE - radius) - (pos - 2 * (X_SIZE - 2 * radius) - (Y_SIZE - 2 * radius));
        }
        
        draw_circle(X_SIZE / 2, Y_SIZE / 2, 2 * radius, 0xFF0000FF);
        draw_circle(x, y, radius, 0xFFFF0000);
        draw_rays(x, y, rays_number, ray_length, 0xFFFF0000);
        pos += speed;

        if (pos >= perimeter)
            pos = 0;

    }
}
