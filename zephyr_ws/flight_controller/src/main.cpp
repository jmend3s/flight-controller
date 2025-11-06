
#include "Application.h"
#include "Gpio.h"

class LedBlinkService : public Component
{
public:
    LedBlinkService(Gpio& led, uint32_t interval)
        : led_(led), interval_(interval), counter_(0) {}

    void initialize() override
    {
        led_.set(Gpio::State::Low);  // start off
    }

    void update() override
    {
        if (++counter_ >= interval_)
        {
            led_.toggle();
            counter_ = 0;
        }
    }

private:
    Gpio& led_;
    uint32_t interval_;
    uint32_t counter_;
};

static Gpio led("GPIO_1", 13, Gpio::Direction::Output);
extern "C" int main(void)
{
    static LedBlinkService blinker(led, 10);

    static Application app;
    app.add(led);
    app.add(blinker);

    app.initialize();
    app.run();
}