// iclock.h
#ifndef GEL_CLOCK_H
#define GEL_CLOCK_H

#include "gel/time/time.h"

namespace gel
{

namespace time
{

class Clock
{
  private:
    /**
     * The current time in cycles.
     */
    TimePoint _time;

    /**
     * The delta time since the last update update cycle and the current in
     * seconds.
     */
    Duration _deltaTime;

    /**
     * The time scale.
     */
    float _timeScale;

    /**
     * If the clock is paused.
     */
    bool _isPaused;

    // HELPER FUNCTIONS
    /**
     * Applies the time scale to the given delta time.
     *
     * @param dt The delta time.
     * @return The scaled delta time.
     */
    Duration scale(Duration dt);

  public:
    // CONSTRUCTORS
    /**
     * Constructs a new clock.
     */
    Clock();

    /**
     * Constructs a new clock with the given time scale.
     *
     * @param timeScale The time scale.
     */
    Clock(float timeScale);

    /**
     * Constructs a new clock with the given initial starting time in cycles..
     *
     * @param initial The starting time in cycles.
     */
    Clock(TimePoint initial);

    /**
     * Constructs a new clock with the given time scale and initial starting
     * time.
     *
     * @param initial The starting time in cycles
     * @param timeScale The time scale.
     */
    Clock(TimePoint initial, float timeScale);

    /**
     * Constructs a copy of another clock.
     *
     * @param clock The clock to copy.
     */
    Clock(const Clock& clock);

    // OPERATORS
    /**
     * Sets the clock to be a copy of another clock.
     *
     * @param clock The clock to copy.
     */
    Clock& operator=(const Clock& clock);

    // MEMBER FUNCTIONS
    /**
     * Updates the clock time.
     *
     * @param elapsed The real-world elapsed time in seconds
     */
    void update(Duration elapsedSec);

    // ACCESSOR FUNCTIONS
    /**
     * Gets the amount of time that elapsed in between the last and current
     * update in seconds.
     *
     * @return The elapsed time.
     */
    Duration elapsed();

    /**
     * Gets the current time in milliseconds.
     * Warning: This value may be imprecise.
     *
     * @return The number of milliseconds since the clock started.
     */
    TimePoint time();

    /**
     * Gets the current time in cycles.
     *
     * @return The number of cycles since the clock started.
     */
    TimePoint timeCycles();

    /**
     * Gets the time scale.
     *
     * @return The scale that is applied to updates.
     */
    float timeScale();

    /**
     * Checks if the clock is currently paused.
     * @return If the clock is paused.
     */
    bool isPaused();

    /**
     * Sets the time scale of the clock.
     *
     * This scale value is applied whenever the clock is updated to scale
     * the received duration to one that is applied.
     */
    void setTimeScale(float scale);

    /**
     * Sets whether or not the clock is paused.
     *
     * @param paused If it should be paused.
     */
    void setPaused(bool paused);
};

// CONSTRUCTORS
inline
Clock::Clock() : _time(0L),_deltaTime(0.0f), _timeScale(1.0f), _isPaused(false)
{
}

inline
Clock::Clock(float timeScale) : _time(0L), _deltaTime(0.0f),
                                _timeScale(timeScale), _isPaused(false)
{
}

inline
Clock::Clock(TimePoint initial) : _time(initial), _deltaTime(0.0f),
                                  _timeScale(1.0f), _isPaused(false)
{
}

inline
Clock::Clock(TimePoint initial, float timeScale)
    : _time(initial), _deltaTime(0.0f), _timeScale(timeScale), _isPaused(false)
{
}

inline
Clock::Clock(const Clock &clock)
    : _time(clock._time), _deltaTime(clock._deltaTime),
      _timeScale(clock._timeScale), _isPaused(clock._isPaused)
{
}

// OPERATORS
inline
Clock& Clock::operator=(const Clock &clock)
{
    _time = clock._time;
    _deltaTime = clock._deltaTime;
    _timeScale = clock._timeScale;
    _isPaused = clock._isPaused;
    return *this;
}

// MEMBER FUNCTIONS
void Clock::update(Duration elapsed)
{
    _deltaTime = scale(elapsed);
    _time += (TimePoint)TimeUnits::convert(_deltaTime,
                                           TimeUnits::SECONDS,
                                           TimeUnits::CYCLES);
}

// ACCESSOR FUNCTIONS
inline
Duration Clock::elapsed()
{
    return _deltaTime;
}

inline
TimePoint Clock::time()
{
    return TimeUnits::convert(_time, TimeUnits::CYCLES,
                              TimeUnits::MILLISECONDS);
}

inline
TimePoint Clock::timeCycles()
{
    return _time;
}

inline
float Clock::timeScale()
{
    return _timeScale;
}

inline
bool Clock::isPaused()
{
    return _isPaused;
}

inline
void Clock::setTimeScale(float scale)
{
    _timeScale = scale;
}

inline
void Clock::setPaused(bool paused)
{
    _isPaused = paused;
}

// HELPER FUNCTIONS
inline
Duration Clock::scale(float dt)
{
    return (_isPaused) ? 0.0f : dt * _timeScale;
}

} // End nspc time

} // End nspc gel

#endif //GEL_CLOCK_H
