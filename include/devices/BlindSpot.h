#pragma once

#include <display/SegmentDisplay.h>
#include <hardware/GPIODevice.h>

#define SENSOR_1_PIN 2
#define SENSOR_2_PIN 3
#define SENSOR_3_PIN 4

extern SegmentDisplay segment_display;



namespace devices {
    extern GPIODeviceDebounce blindspot_sensor_1;
    extern GPIODeviceDebounce blindspot_sensor_2;
    extern GPIODeviceDebounce blindspot_sensor_3;
    void blindspot_init();
    void blindspot_update();
    void blindspot_begin();
}