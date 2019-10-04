
#include "splashkit.h"

using namespace std;

#define ZOMBIE 0
#define CANDY 1
#define POWER 2

void load_resources()
{
    load_bitmap("candy", "Candy.png");
    load_bitmap("zombie", "zombie.png");

}

bitmap power_type(int id)
{
    switch(id)
    {
        case CANDY:	    
        	return bitmap_named("candy");
		case ZOMBIE:
			return bitmap_named("zombie");
        default:
        	return bitmap_named("candy");
    }
}

int main()
{
    int counter = 0;
    bitmap power,powerzombie,powercandy;  
    double width, height; 
    open_window("halloween",800, 800);
	load_bitmap("background","bg.png");

    
    load_resources(); 
	
    power= power_type(rnd(POWER));
	powerzombie=power_type(ZOMBIE);
	powercandy=power_type(CANDY);
    width=rnd(screen_width() - bitmap_width(power)-20);
    height = rnd(screen_height() - bitmap_height(power)-400); 
    while (not quit_requested() )
    {
        process_events();
        clear_screen(COLOR_WHITE);
		draw_bitmap("background",0,0);
        draw_text("Score: " + to_string(counter),COLOR_BLACK, 600, 700); 
		draw_bitmap(power, width, height);
        refresh_screen(60);
        if ( mouse_clicked(LEFT_BUTTON) and bitmap_point_collision(powerzombie, width, height, mouse_x(), mouse_y() ) )
        {
			load_sound_effect("booingsound","boo.mp3");
			play_sound_effect("booingsound");
            counter = counter-5; 
            power = power_type(rnd(POWER));
            width = rnd(screen_width() - bitmap_width(power)-20);
            height = rnd(screen_height() - bitmap_height(power)-400);
        }
		if ( mouse_clicked(RIGHT_BUTTON) and bitmap_point_collision(powerzombie, width, height, mouse_x(), mouse_y() ) )
        {
			load_sound_effect("gun","gunshot.mp3");
			play_sound_effect("gun");
            counter = counter+5; 
            power = power_type(rnd(POWER));
            width = rnd(screen_width() - bitmap_width(power)-20);
            height = rnd(screen_height() - bitmap_height(power)-400);
        }
		if ( mouse_clicked(LEFT_BUTTON) and bitmap_point_collision(powercandy, width, height, mouse_x(), mouse_y() ) )
        {
			load_sound_effect("gun","gunshot.mp3");
			play_sound_effect("gun");
            counter = counter+5; 
            power = power_type(rnd(POWER));
            width = rnd(screen_width() - bitmap_width(power)-20);
            height = rnd(screen_height() - bitmap_height(power)-400);
        }
		if ( mouse_clicked(RIGHT_BUTTON) and bitmap_point_collision(powercandy, width, height, mouse_x(), mouse_y() ) )
        {
			load_sound_effect("booingsound","boo.mp3");
			play_sound_effect("booingsound");
            counter = counter-5; 
            power = power_type(rnd(POWER));
            width = rnd(screen_width() - bitmap_width(power)-20);
            height = rnd(screen_height() - bitmap_height(power)-400);
        }

    }
    return 0;
}