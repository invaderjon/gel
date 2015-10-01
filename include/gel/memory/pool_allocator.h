// pool_allocator.h
#ifndef GEL_POOL_ALLOCATOR_H
#define GEL_POOL_ALLOCATOR_H

#include "iallocator.h"

namespace gel
{

namespace mem
{

template<typename T>
class PoolAllocator: IAllocator<T>
{

};

} // End nspc mem

} // End nspc gel

#endif //GEL_POOL_ALLOCATOR_H
