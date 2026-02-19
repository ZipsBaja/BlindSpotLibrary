#pragma once

#include <util/ArrayView.h>
#include <cstdint>

namespace animations
{

    constexpr uint32_t frames_left_sensor[] = {
        0UL,
        0b00000110UL << 0,
        0b01000111UL << 0,
        0b01111111UL << 0,

        (0b00000110UL << 8) + (0b01111111UL << 0),
        (0b01000111UL << 8) + (0b01111111UL << 0),
        (0b01111111UL << 8) + (0b01111111UL << 0),

        (0b01111111UL << 8) + (0b01111111UL << 0),

        (0b00000110UL << 16) + (0b01111111UL << 8) + (0b01111111UL << 0),
        (0b01000111UL << 16) + (0b01111111UL << 8) + (0b01111111UL << 0),
        (0b01111111UL << 16) + (0b01111111UL << 8) + (0b01111111UL << 0),

        (0b00000110UL << 24) + (0b01111111UL << 16) + (0b01111111UL << 8) + (0b01111111UL << 0),
        (0b01000111UL << 24) + (0b01111111UL << 16) + (0b01111111UL << 8) + (0b01111111UL << 0),
        (0b01111111UL << 24) + (0b01111111UL << 16) + (0b01111111UL << 8) + (0b01111111UL << 0),

        (0b01111111UL << 24) + (0b01111111UL << 16) + (0b01111111UL << 8) + (0b01111111UL << 0),

    };

    constexpr ArrayView<uint32_t> animations_left_sensor = make_array_view(frames_left_sensor);

    constexpr uint32_t frames_right_sensor[] = {
        0UL,
        0b00110000UL << 24,
        0b01111001UL << 24,
        0b01111111UL << 24,

        (0b01111111UL << 24) + (0b00110000UL << 16),
        (0b01111111UL << 24) + (0b01111001UL << 16),
        (0b01111111UL << 24) + (0b01111111UL << 16),

        (0b11111111UL << 24) + (0b11111111UL << 24),

        (0b11111111UL << 24) + (0b11111111UL << 16) + (0b10110000UL << 8),
        (0b11111111UL << 24) + (0b11111111UL << 16) + (0b11111001UL << 8),
        (0b11111111UL << 24) + (0b11111111UL << 16) + (0b11111111UL << 8),

        (0b11111111UL << 24) + (0b11111111UL << 16) + (0b11111111UL << 8) + (0b10110000UL << 0),
        (0b11111111UL << 24) + (0b11111111UL << 16) + (0b11111111UL << 8) + (0b11111001UL << 0),
        (0b11111111UL << 24) + (0b11111111UL << 16) + (0b11111111UL << 8) + (0b11111111UL << 0),

        (0b11111111UL << 24) + (0b11111111UL << 16) + (0b11111111UL << 8) + (0b11111111UL << 0),

    };

    constexpr ArrayView<uint32_t> animations_right_sensor = make_array_view(frames_right_sensor);

    constexpr uint32_t frames_middle_sensor[] = {
        0UL,
        0b10000000UL << 8,
        
        (0b10000110UL << 16) + (0b10110000UL << 8),
        (0b11001111UL << 16) + (0b11111001UL << 8),
        (0b11111111UL << 16) + (0b11111111UL << 8),

        (0b10000110UL << 24) +(0b11111111UL << 16) + (0b11111111UL << 8) + (0b10110000UL << 0),
        (0b11001111UL << 24) +(0b11111111UL << 16) + (0b11111111UL << 8) + (0b11111001UL << 0),
        (0b11111111UL << 24) +(0b11111111UL << 16) + (0b11111111UL << 8) + (0b11111111UL << 0),

        (0b11111111UL << 24) +(0b11111111UL << 16) + (0b11111111UL << 8) + (0b11111111UL << 0),


    };

    constexpr ArrayView<uint32_t> animations_middle_sensor = make_array_view(frames_middle_sensor);
}