#include <devices/BlindSpot.h>
#include <devices/animations/sensor_animations.h>
#include <display/animations/Animations.h>
#include <pico/stdlib.h>


SegmentDisplay::SegmentDisplaySettings display_settings[] = {
    SegmentDisplay::Create(pio0, 10, 11, 0, 7, false), //sensor 1
    SegmentDisplay::Create(pio0, 12, 13, 1, 7, true), //sensor 2
    SegmentDisplay::Create(pio0, 14, 15, 2, 7, false)  //sensor 3
};

SegmentDisplay segment_display = SegmentDisplay(display_settings, 3);

int main()
{

    stdio_init_all();
    
    devices::blindspot_init();
    devices::blindspot_begin();
    while (1)
    {
        Event::HandleEvents();
        devices::blindspot_update();
    }

}