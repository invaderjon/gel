// time.h
#ifndef GEL_TIME_H
#define GEL_TIME_H
#include "gel/gelint.h"

namespace gel
{

namespace time
{

/**
 * Defines an duration of time since a previous arbitrary point.
 *
 * This should be used for durations that are defined relative to an arbitrary
 * scale.
 */
typedef float Duration;

/**
 * Defines an absolute point in time in reference to an arbitrary starting
 * point.
 */
typedef uint64 TimePoint;

/**
 * Defines helper methods to convert time in between various units.
 */
struct TimeUnits
{
    /**
     * Defines a unit of time.
     */
    enum Unit
    {
        HOURS,
        MINUTES,
        SECONDS,
        MILLISECONDS,
        MICROSECONDS,
        NANOSECONDS,
        CYCLES
    };

    /**
     * Gets the that converts a unit from seconds.
     * @param unit The unit.
     * @return The multiplier.
     */
    static float getUnitMultiplier(Unit unit);

    /**
     * Converts the duration from one unit to another.
     *
     * @param duration The unconverted duration.
     * @param in The input units.
     * @param out The output units.
     * @return The converted duration.
     */
    static Duration convert(Duration duration, Unit in, Unit out);

    /**
     * Converts the time from one unit to another.
     *
     * @param time The unconverted time.
     * @param in The input units.
     * @param out The output units.
     * @return The converted time.
     */
    static TimePoint convert(TimePoint time, Unit in, Unit out);
};

float TimeUnits::getUnitMultiplier(Unit unit)
{
    float mult;
    switch (unit)
    {
        case HOURS:
            mult = 1 / 3600.0f;
            break;

        case MINUTES:
            mult = 1 / 60.0f;
            break;

        case SECONDS:
            mult = 1.0f;
            break;

        case MILLISECONDS:
            mult = 1000.0f;
            break;

        case MICROSECONDS:
            mult = 1000000.0f;
            break;

        case NANOSECONDS:
            mult = 1000000000.0f;
            break;

        case CYCLES:
            // TODO: determine cycles/second
            mult = 1000000000.0f;
            break;

        default:
            mult = 1.0f;
            break;
    }

    return mult;
}

inline
Duration TimeUnits::convert(Duration duration, Unit in, Unit out)
{
    return (duration * getUnitMultiplier(out)) / getUnitMultiplier(in);
}

inline
TimePoint TimeUnits::convert(TimePoint time, Unit in, Unit out)
{
    float inMult = getUnitMultiplier(in);
    float outMult = getUnitMultiplier(out);

    return TimePoint(time * (outMult / inMult));
}

} // End nspc time

} // End nspc gel

#endif //GEL_TIME_H
