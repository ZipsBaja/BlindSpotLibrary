#include <devices/BlindSpot.h>
#include <devices/animations/sensor_animations.h>
#include <pico/stdlib.h>
#include <display/animations/Animations.h>
#include <hardware/Button.h>
#include <util/TimeHandler.h>
#include <hardware/Timer.h>





namespace devices
{
    GPIODeviceDebounce blindspot_sensor_1 = GPIODeviceDebounce(SENSOR_1_PIN, Pull::UP, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, 1);
    GPIODeviceDebounce blindspot_sensor_2 = GPIODeviceDebounce(SENSOR_2_PIN, Pull::UP, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, 1);
    GPIODeviceDebounce blindspot_sensor_3 = GPIODeviceDebounce(SENSOR_3_PIN, Pull::UP, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, 1);
    Button reset_button = Button(5, true, 200);
    constexpr uint64_t TWO_HOURS_US = 2ULL * 60ULL * 60ULL * 1000000ULL;
    TimeHandler th;
    //int sensor_activate_ref_count;
    bool sensor_activate = false;
    RepeatingTimer Minute_Counter;
    uint32_t Total_Minutes = 120;
    uint32_t Minutes_Left = Total_Minutes; 


    static void init_sensor(EventSource* source, const ArrayView<uint32_t>& animation);


    void blindspot_init()
    {

        blindspot_sensor_1 .AddAction([](const Event* ev, void* ptr){
            GPIOEvent* gpio_ev = ev->GetEventAsType<GPIOEvent>();
            printf("Sensor 1 event triggered mask: %u\n", gpio_ev->GetEventsTriggeredMask());
            if(gpio_ev->GetEventsTriggeredMask() & GPIO_IRQ_EDGE_FALL)
            {
                //sensor activates
                segment_display.DisplayAnimationOnce(0, animations::animations_left_sensor, 33.33f, true);
                //sensor_activate_ref_count++;
                //puts("Sensor 1 activated\n");
            }
            else 
            {
                segment_display.DisplayClear(0);
                //sensor deactivates
                //segment_display.DisplayAnimationOnce(0, animations::animations_left_sensor, 33.33f, true, true);
                //sensor_activate_ref_count--;
                puts("Sensor 1 deactivated\n");
            }
            
        });

        blindspot_sensor_2 .AddAction([](const Event* ev, void* ptr){
            GPIOEvent* gpio_ev = ev->GetEventAsType<GPIOEvent>();
            if(gpio_ev->GetEventsTriggeredMask() & GPIO_IRQ_EDGE_FALL)
            {
                //sensor activates
                segment_display.DisplayAnimationOnce(1, animations::animations_middle_sensor, 33.33f, true);
                sensor_activate = true;
                //puts("Sensor 2 activated\n");
            }
            else
            {
                if (Minutes_Left > 0){
                

                segment_display.DisplayBoth(1, Minutes_Left / 60, Minutes_Left % 60, true);
                }
                
                //sensor deactivates
                //segment_display.DisplayAnimationOnce(1, animations::animations_middle_sensor, 33.33f, true, true);
                sensor_activate = false;
            }
            
        });

        blindspot_sensor_3 .AddAction([](const Event* ev, void* ptr){
            GPIOEvent* gpio_ev = ev->GetEventAsType<GPIOEvent>();
            if(gpio_ev->GetEventsTriggeredMask() & GPIO_IRQ_EDGE_FALL)
            {
                //sensor activates
                segment_display.DisplayAnimationOnce(2, animations::animations_right_sensor, 33.33f, true);
                puts("Sensor 3 activated\n");
                //sensor_activate_ref_count++;
            }
            else
            {
                segment_display.DisplayClear(2);
                //sensor deactivates
                //segment_display.DisplayAnimationOnce(2, animations::animations_right_sensor, 33.33f, true, true);
                //sensor_activate_ref_count--;
            }

        });
        reset_button.AddAction([](const Event* ev, void* ptr){
            puts("Reset button pressed, starting timer\n");
            segment_display.DisplayClearAll();
        });
        Minute_Counter.AddAction([](const Event* ev, void*){
            if (Minutes_Left > 0){
                Minutes_Left--;

                segment_display.DisplayBoth(1, Minutes_Left / 60, Minutes_Left % 60, true);
            }
    
        });
        
        segment_display.DisplayBoth(1, 1, 59, true);
        Minutes_Left--;
    }
        
        
   
    void blindspot_begin(){
        Minute_Counter.Start(60000); 
    }
   
    void blindspot_update()
    {
        /*th.Update();
        uint64_t CurrentTime = th.now_us - th.GetGlobalTimeWhenCreated();
        uint64_t TimeLeft = TWO_HOURS_US - CurrentTime;
        uint32_t left,right;
        left = TimeLeft / 1000000 / 60 / 60;
        right = (TimeLeft / 1000000 / 60) % 60;
        if (sensor_activate_ref_count <= 0){
            segment_display.DisplayBoth(1, left, right, true); 
        }*/
        

    }  

}