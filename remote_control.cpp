#include "remote_control.hpp"

#ifndef PICO

namespace ardent
{

remote_control::remote_control(pin p, callback_type on_button_pressed)
    : irrecv(p.get_pin_number()), m_on_button_pressed(std::move(on_button_pressed))
{
    irrecv.enableIRIn();
}

void remote_control::update()
{
    decode_results results;
    if (irrecv.decode(&results))
    {
        if (strcmp(to_string(static_cast<remote_control_buttons>(results.value)).c_str(), "unknown") != 0)
        {
            m_on_button_pressed(static_cast<remote_control_buttons>(results.value));
        }
        irrecv.resume();
    }
}

String to_string(remote_control_buttons button)
{
    switch (button)
    {
    case remote_control_buttons::CH_minus:
        return F("CH_minus");
    case remote_control_buttons::CH_plus:

        return F("CH_plus");
    case remote_control_buttons::CH:
        return F("CH");
    case remote_control_buttons::FAST_BACK:
        return F("FAST_BACK");
    case remote_control_buttons::FAST_FORWARD:
        return F("FAST_FORWARD");
    case remote_control_buttons::PAUSE:
        return F("PAUSE");
    case remote_control_buttons::VOL_minus:
        return F("VOL_minus");
    case remote_control_buttons::VOL_plus:
        return F("VOL_plus");
    case remote_control_buttons::EQ:
        return F("EQ");
    case remote_control_buttons::Plus100:
        return F("Plus100");
    case remote_control_buttons::Plus200:
        return F("Plus200");
    case remote_control_buttons::Num0:
        return F("Num0");
    case remote_control_buttons::Num1:
        return F("Num1");
    case remote_control_buttons::Num2:
        return F("Num2");
    case remote_control_buttons::Num3:
        return F("Num3");
    case remote_control_buttons::Num4:
        return F("Num4");
    case remote_control_buttons::Num5:
        return F("Num5");
    case remote_control_buttons::Num6:
        return F("Num6");
    case remote_control_buttons::Num7:
        return F("Num7");
    case remote_control_buttons::Num8:
        return F("Num8");
    case remote_control_buttons::Num9:
        return F("Num9");
    case remote_control_buttons::Repeat:
        return F("Repeat");
    default:
        return F("unknown");
    }
}

} // namespace ardent

#endif // ARDUINO