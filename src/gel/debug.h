// debug.h
#ifndef GEL_DEBUG_H
#define GEL_DEBUG_H
#include "config.g.h"

/**
 * Defines a section of code that should only be included in debug builds.
 */
#define debug_only if(GEL_DEBUG)

#endif //GEL_DEBUG_H
