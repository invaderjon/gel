// log.h
#ifndef GEL_LOG_H
#define GEL_LOG_H
#include "config.g.h"

#ifndef GEL_LOG_OVERRIDE
#include "util/logger.h"
#endif

// CONFIGURATION DEPENDENT
#if GEL_LOG
#define flog(file, verbosity, tag, message) gel_log(file, verbosity, tag, message)
#else
#define flog(file, verbosity, tag, message)
#endif

// CONSTANTS
#define GEL_LOG_FILE "gel.log"
#define GEL_LOG_VERBOSE 0
#define GEL_LOG_DEBUG 1
#define GEL_LOG_WARNING 2
#define GEL_LOG_ERROR 3
#define GEL_LOG_FATAL 4

// LOG FUNCTIONS
#define log(verbosity, tag, message) \
    flog(GEL_LOG_FILE, verbosity, tag, message)

// GENERIC LOGGING
#define logv(tag, message) \
    log(GEL_LOG_VERBOSE, tag, message)

#define logd(tag, message) \
    log(GEL_LOG_DEBUG, tag, message)

#define logw(tag, message) \
    log(GEL_LOG_WARNING, tag, message)

#define loge(tag, message) \
    log(GEL_LOG_ERROR, tag, message)

#define logf(tag, message) \
    log(GEL_LOG_FATAL, tag, message)

// FILE SPECIFIC LOGGING
#define flogv(file, tag, message) \
    flog(file, GEL_LOG_VERBOSE, tag, message)

#define flogd(file, tag, message) \
    flog(file, GEL_LOG_DEBUG, tag, message)

#define flogw(file, tag, message) \
    flog(file, GEL_LOG_WARNING, tag, message)

#define floge(file, tag, message) \
    flog(file, GEL_LOG_ERROR, tag, message)

#define flogf(file, tag, message) \
    flog(file, GEL_LOG_FATAL, tag, message)

#endif //GEL_LOG_H
