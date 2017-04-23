#include "wire.hpp"
#include <algorithm>

namespace kpvs
{
    Wire::Wire():
        state(VSTATE_LOW)
    {
    }

    int Wire::connectPin(Pin& pin)
    {
        pins.push_back(&pin);
        return ERR_OK;
    }

    int Wire::disconnectPin(Pin& pin)
    {
        auto it = std::find(pins.begin(), pins.end() + pins.capacity(), &pin);
        pins.erase(it);
        return ERR_OK;
    }

    int Wire::update()
    {
        bool metLow = false;
        bool metHigh = false;

        // TODO: needs rethinking
        for (auto pin : pins)
        {
            if (pin->mode == Pin::PINMODE_OUT)
            {
                if (pin->state == VSTATE_LOW)
                {
                    metLow = true;
                    state  = VSTATE_LOW;
                }
                else if (pin->state == VSTATE_HIGH)
                {
                    metHigh = true;
                    state   = VSTATE_HIGH;
                }
                else if (pin->state == VSTATE_X)
                {
                    state = VSTATE_X; //TODO: WTF?
                }
            }
        }
        if (metHigh && metLow)
            return ERR_SHORT_CIRCUIT;

        for (auto pin : pins)
        {
            if (pin->mode == Pin::PINMODE_IN)
                pin->state = state;
        }

        return ERR_OK;
    }

    VoltageState Wire::getState() const
    {
        return state;
    }
}
