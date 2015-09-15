cmake_minimum_required(VERSION 3.3)
project(gel)

# ARGUMENTS
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

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
        include/gel/gellib.h
        include/gel/gelint.h
        include/gel/memory/imemory.h
        include/gel/memory/iallocator.h include/gel/memory/pool_allocator.h)

set(SOURCE_FILES
        src/gel/config.g.cpp
        src/gel/config.g.h
        src/gel/debug.cpp
        src/gel/debug.h
        src/gel/log.cpp
        src/gel/log.h
        src/gel/util/logger.cpp
        src/gel/util/logger.h
        src/gel/memory/imemory.cpp src/gel/memory/iallocator.cpp src/gel/memory/pool_allocator.cpp)

# INCLUDES
include_directories(src)
include_directories(include)

# GEL BUILD
add_library( gel ${INCLUDE_FILES} ${SOURCE_FILES} )

# TESTS
if ( BUILD_TESTS )
        set(MEMORY_TEST_FILES )
        set(CONTAINER_TEST_FILES )
        set(ALL_TEST_FILES ${MEMORY_TEST_FILES} ${CONTAINER_TEST_FILES})

        include_directories(test)

        add_executable( all_tests test.m.cpp ${ALL_TEST_FILES} )
        target_link_libraries(gel)
endif()
