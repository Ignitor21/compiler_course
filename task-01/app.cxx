#include "sim.hxx"

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
        
        sim_flush();
        sim_draw_circle(x, y, radius, 0xFFFF0000);
        sim_draw_rays(x, y, rays_number, ray_length, 0xFFFF0000);
        pos += speed;

        if (pos >= perimeter)
            pos = 0;

    }
}
