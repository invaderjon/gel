#ifndef GEL_IMEMORY_H
#define GEL_IMEMORY_H

#include <gel/gellib.h>

namespace gel
{

namespace mem
{

/**
 * @brief Defines a pool of memory.
 *
 * This can optionally be passed to a gel::mem::IAllocator implementation
 * which will be initialized using the provided memory pool. This should only
 * be constructed once and shared among all allocator instances for the best
 * performance.
 */
class IMemory
{
  public:
    /**
     * Destructor.
     */
    virtual ~IMemory() = 0;

    /**
     * Allocates a block of memory.
     *
     * @param size      The size of the memory block, in bytes.
     */
    virtual void* allocate(Size size) = 0;

    /**
     * Reallocates a block of memory.
     *
     * @param pointer   The pointer to the previously allocated block.
     * @param size      The new size for the memory block, in bytes.
     */
    virtual void* reallocate(void* pointer, Size size) = 0;

    /**
     * Releases a block of memory.
     *
     * @param pointer The pointer to the allocated block.
     */
    virtual void release(void* pointer) = 0;
};

inline
IMemory::~IMemory()
{ }

} // End nspc mem

} // End nspc gel

#endif //GEL_IMEMORY_H
