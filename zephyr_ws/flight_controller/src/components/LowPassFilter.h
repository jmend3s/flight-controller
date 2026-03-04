
#ifndef __LOW_PASS_FILTER_H__
#define __LOW_PASS_FILTER_H__

#include <cstdint>


class LowPassFilter
{
public:
    uint32_t filter(uint32_t rawMillivolts);

private:
    float _filteredMillivolts = 0.0f;
    bool _filterInitialized = false;
    static constexpr float _alpha = 0.25f;
};


#endif
