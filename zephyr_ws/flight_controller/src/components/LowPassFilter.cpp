
#include "LowPassFilter.h"


uint32_t LowPassFilter::filter(uint32_t const rawMillivolts)
{
    if (!_filterInitialized)
    {
        _filteredMillivolts = static_cast<float>(rawMillivolts);
        _filterInitialized = true;
    }
    else
    {
        _filteredMillivolts += _alpha * (static_cast<float>(rawMillivolts) - _filteredMillivolts);
    }
    return static_cast<uint32_t>(_filteredMillivolts);
}
