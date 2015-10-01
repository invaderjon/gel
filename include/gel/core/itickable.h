// ITickable.h
#ifndef GEL_ITICKABLE_H
#define GEL_ITICKABLE_H

#include "gel/time/time.h"

namespace gel
{

namespace core
{

class ITickable
{
  public:
    /**
     * Prepares for the next tick cycle.
     *
     * @param dt The time in milliseconds since the last tick cycle.
     */
    virtual void pretick(time::Duration dt) = 0;

    /**
     * Performs the update for the current tick cycle.
     *
     * @param dt The time in milliseconds since the last tick cycle.
     */
    virtual void tick(time::Duration dt) = 0;

    /**
     * Cleans up after a tick cycle is completed.
     *
     * @param dt The time in milliseconds since the last tick cycle.
     */
    virtual void postick(time::Duration dt) = 0;
};

} // End nspc core

} // End nspc gel

#endif // GEL_ITICKABLE_H
