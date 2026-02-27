
#ifndef __MAP_H__
#define __MAP_H__

#include <cstddef>


template<typename Key, typename Value, std::size_t N>
class Map
{
public:
    struct Entry
    {
        Key key;
        Value value;
    };

    constexpr Map(const Entry (&entries)[N])
        : _entries(entries)
    {
    }

    constexpr Value const& at(const Key& key, const Value& defaultValue) const
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            if (_entries[i].key == key)
            {
                return _entries[i].value;
            }
        }
        return defaultValue;
    }

private:
    Entry const (&_entries)[N];
};


#endif
