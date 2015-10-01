// allocator.h
#ifndef GEL_ALLOCATOR_H
#define GEL_ALLOCATOR_H

#include "gel/gellib.h"
#include "gel/memory/imemory.h"

namespace gel
{

namespace mem
{

/**
 * @brief Defines a memory allocator for wrapping dynamic allocation.
 *
 * This interface provides a wrapper for dynamic memory allocation.
 * Implementations of this interface may be passed to classes such as
 * containers which will use it when it needs to allocate memory.
 *
 * @tparam T The type that is allocated.
 */
template<typename T>
class IAllocator
{
  public:
    /**
     * Destructor.
     */
    virtual ~IAllocator() = 0;

    /**
     * Allocates a block of memory.
     *
     * @param count The size of the memory block, in instances of T.
     * @return      A pointer to the allocated block.
     */
    virtual T* allocate(Size count) = 0;

    /**
     * Reallocates a pre-existing block of memory.
     *
     * @param ptr   A pointer to the existing memory block.
     * @param count The new size of the memory block, in instances of T.
     * @return      A pointer to the reallocated block.
     */
    virtual T* reallocate(T* ptr, Size count) = 0;

    /**
     * Releases a block of memory.
     *
     * @param ptr A pointer to the allocated memory block.
     */
    virtual void free(T* ptr) = 0;
};

template<typename T>
inline
IAllocator<T>::~IAllocator()
{
}

} // End nspc mem

} // End nspc gel

#endif //GEL_ALLOCATOR_H
