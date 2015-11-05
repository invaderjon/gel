cmake_minimum_required(VERSION 2.8)
project(gel)

# IGNORE NEW VERSION POLICY
if ( POLICY CMP0048 )
        cmake_policy( SET CMP0048 OLD )
endif()

# PRE-REQS
find_package( Threads REQUIRED )

find_library(
        LIB_GTEST
        NAMES gtest libgtest
        NO_DEFAULT_PATH
        PATHS ${CMAKE_SOURCE_DIR}/lib/googletest
)

if ( LIB_GTEST MATCHES NOTFOUND )
        message( FATAL_ERROR "The dependency gel must be located in ./lib/googletest. Run configure.py to remedy this." )
endif()

# ARGUMENTS
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# DIRECTORIES
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# CONFIGURATION
set(gelMajor 0)
set(gelMinor 0)
set(gelPatch 0)
set(gelDebugEnabled 1)
set(gelLogEnabled 1)
set(gelLoggingOverride 0)
set(gelLogger "")

# CONFIGURED FILES
set(gelConfigured config)
configure_file(config.cmake.in ${SOURCE_DIR}/gel/config.g.h)
configure_file(configured.cmake.in ${SOURCE_DIR}/gel/config.g.cpp)

# SOURCES
set(INCLUDE_FILES
        include/gel/gelfloat.h
        include/gel/gelint.h
        include/gel/gellib.h
        include/gel/containers/imap.h
        include/gel/containers/iset.h
        include/gel/core/itickable.h
        include/gel/debug/ilogger.h
        include/gel/io/istream.h
        include/gel/math/gelmath.h
        include/gel/math/mat.h
        include/gel/math/mat_math.h
        include/gel/math/mat2x2.h
        include/gel/math/mat3x3.h
        include/gel/math/mat4x4.h
        include/gel/math/precision.h
        include/gel/math/swizzle.h
        include/gel/math/vec.h
        include/gel/math/vec2.h
        include/gel/math/vec3.h
        include/gel/math/vec4.h
        include/gel/memory/iallocator.h
        include/gel/memory/imemory.h
        include/gel/memory/pool_allocator.h
        include/gel/time/clock.h
        include/gel/time/time.h
        include/gel/math/vec_math.h)

set(SOURCE_FILES
        src/gel/config.g.cpp
        src/gel/config.g.h
        src/gel/debug.cpp
        src/gel/debug.h
        src/gel/gelfloat.cpp
        src/gel/gelint.cpp
        src/gel/gellib.cpp
        src/gel/log.cpp
        src/gel/log.h
        src/gel/core/itickable.cpp
        src/gel/containers/imap.cpp
        src/gel/containers/iset.cpp
        src/gel/debug/ilogger.cpp
        src/gel/io/istream.cpp
        src/gel/math/gelmath.cpp
        src/gel/math/mat.cpp
        src/gel/math/mat_math.cpp
        src/gel/math/mat2x2.cpp
        src/gel/math/mat3x3.cpp
        src/gel/math/mat4x4.cpp
        src/gel/math/precision.cpp
        src/gel/math/swizzle.cpp
        src/gel/math/vec.cpp
        src/gel/math/vec2.cpp
        src/gel/math/vec3.cpp
        src/gel/math/vec4.cpp
        src/gel/memory/iallocator.cpp
        src/gel/memory/imemory.cpp
        src/gel/memory/pool_allocator.cpp
        src/gel/time/clock.cpp
        src/gel/time/time.cpp
        src/gel/util/logger.cpp
        src/gel/util/logger.h
        src/gel/math/vec_math.cpp)

# INCLUDES
include_directories(include src)

# GEL BUILD
add_library( gel ${INCLUDE_FILES} ${SOURCE_FILES} )

# TESTS
if ( BUILD_TESTS )
        set(MEMORY_TEST_FILES
        )

        set(CONTAINER_TEST_FILES
        )

        set(TIME_TEST_FILES
                test/gel/time/clock.t.cpp
        )

        set(MATH_TEST_FILES
                test/gel/math/mat2x2.t.cpp
                test/gel/math/mat3x3.t.cpp
                test/gel/math/mat4x4.t.cpp
                test/gel/math/vec2.t.cpp
                test/gel/math/vec3.t.cpp
                test/gel/math/vec4.t.cpp
        )

        set(ALL_TEST_FILES
                ${MEMORY_TEST_FILES}
                ${CONTAINER_TEST_FILES}
                ${TIME_TEST_FILES}
                ${MATH_TEST_FILES}
        )

        include_directories(
                include
                test
        )

        # BUILD
        add_executable( all_tests test.m.cpp ${ALL_TEST_FILES} )
        target_link_libraries( all_tests ${LIB_GTEST} ${CMAKE_THREAD_LIBS_INIT} )
endif()
