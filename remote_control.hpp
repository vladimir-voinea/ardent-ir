#pragma once

#ifndef PICO

#include <Arduino.h>
#include <detail/IRremote/IRremote.h>

#include <functional>
#include <i_loop_observer.hpp>
#include <pin.hpp>

namespace ardent
{
enum class remote_control_buttons : unsigned long
{
    CH_minus = 0xFFA25D,
    CH_plus = 0xFFE21D,
    CH = 0xFF629D,
    FAST_BACK = 0xFF22DD,
    FAST_FORWARD = 0xFF02FD,
    PAUSE = 0xFFC23D,
    VOL_minus = 0xFFE01F,
    VOL_plus = 0xFFA857,
    EQ = 0xFF906F,
    Plus100 = 0xFF9867,
    Plus200 = 0xFFB04F,
    Num0 = 0xFF6897,
    Num1 = 0xFF30CF,
    Num2 = 0xFF18E7,
    Num3 = 0xFF7A85,
    Num4 = 0xFF10EF,
    Num5 = 0xFF38C7,
    Num6 = 0xFF5AA5,
    Num7 = 0xFF42BD,
    Num8 = 0xFF4AB5,
    Num9 = 0xFF52AD,
    Repeat = 0xFFFFFFFF
};

String to_string(remote_control_buttons button);

class remote_control final : public i_loop_observer
{
  public:
    using callback_type = std::function<void(remote_control_buttons)>;

    remote_control(pin p, callback_type on_button_pressed);

    void update() override;

  private:
    IRrecv irrecv;
    callback_type m_on_button_pressed;
};
} // namespace ardent

#endif // ARDUINO