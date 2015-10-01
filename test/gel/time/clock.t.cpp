// clock.t.cpp
#include <gtest/gtest.h>

#include "gel/time/time.h"
#include "gel/time/clock.h"

TEST( Clock, Construction )
{
    using namespace gel::time;

    Clock clock;

    EXPECT_EQ( 0, clock.elapsed() );
    EXPECT_EQ( 0, clock.time() );
    EXPECT_EQ( 0, clock.timeCycles() );
    EXPECT_EQ( 1.0f, clock.timeScale() );
    EXPECT_FALSE( clock.isPaused() );

    TimePoint timeInMs = TimePoint(1000);
    TimePoint timeInCycles = TimeUnits::convert(TimePoint(timeInMs),
                                        TimeUnits::MILLISECONDS,
                                        TimeUnits::CYCLES);
    Clock offset(timeInCycles);

    EXPECT_EQ( 0, offset.elapsed() );
    EXPECT_EQ( timeInMs, offset.time() );
    EXPECT_EQ( timeInCycles, offset.timeCycles() );
    EXPECT_EQ( 1.0f, offset.timeScale() );
    EXPECT_FALSE( offset.isPaused() );

    Clock scaled(25.0f);

    EXPECT_EQ( 0, scaled.elapsed() );
    EXPECT_EQ( 0, scaled.time() );
    EXPECT_EQ( 0, scaled.timeCycles() );
    EXPECT_EQ( 25.0f, scaled.timeScale() );
    EXPECT_FALSE( scaled.isPaused() );

    Clock scaledAndOffset(timeInCycles, 25.0f);

    EXPECT_EQ( 0, scaledAndOffset.elapsed() );
    EXPECT_EQ( timeInMs, scaledAndOffset.time() );
    EXPECT_EQ( timeInCycles, scaledAndOffset.timeCycles() );
    EXPECT_EQ( 25.0f, scaledAndOffset.timeScale() );
    EXPECT_FALSE( scaledAndOffset.isPaused() );

    Clock copy(scaledAndOffset);

    EXPECT_EQ( scaledAndOffset.elapsed(), copy.elapsed() );
    EXPECT_EQ( scaledAndOffset.time(), copy.time() );
    EXPECT_EQ( scaledAndOffset.timeCycles(), copy.timeCycles() );
    EXPECT_EQ( scaledAndOffset.timeScale(), copy.timeScale() );
    EXPECT_FALSE( copy.isPaused() );
}

TEST( Clock, Update )
{
    using namespace gel::time;

    TimePoint timeInMs = TimePoint(2000);
    TimePoint timeInCycles = TimeUnits::convert(TimePoint(timeInMs),
                                                TimeUnits::MILLISECONDS,
                                                TimeUnits::CYCLES);
    Clock clock(timeInCycles, 2.0f);

    EXPECT_EQ( 0, clock.elapsed() );
    EXPECT_EQ( timeInMs, clock.time() );
    EXPECT_EQ( timeInCycles, clock.timeCycles() );

    EXPECT_EQ( 2.0f, clock.timeScale() );
    EXPECT_FALSE( clock.isPaused() );

    clock.update( 25.0f );

    const TimePoint expectedTime = timeInCycles +
        TimePoint(TimeUnits::convert(Duration(2.0f*25.0f),
                                     TimeUnits::SECONDS,
                                     TimeUnits::CYCLES));

    const TimePoint expectedTimeMs = timeInMs +
        TimePoint(TimeUnits::convert(Duration(2.0f*25.0f),
                           TimeUnits::SECONDS,
                           TimeUnits::MILLISECONDS));

    EXPECT_EQ( 25.0f * 2, clock.elapsed() );
    EXPECT_EQ( expectedTime, clock.timeCycles() );
    EXPECT_EQ( 2.0f, clock.timeScale() );
    EXPECT_FALSE( clock.isPaused() );
}