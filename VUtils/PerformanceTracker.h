#pragma once
#include <iostream>
#include <memory_resource>
#include <chrono>

inline static bool gMemtrack = 0;
inline static unsigned int gAllocated = 0;
inline static unsigned int gAllocatedCount = 0;
inline static unsigned int gDeleted = 0;
inline static unsigned int gDeletedCount = 0;

inline static std::chrono::steady_clock::time_point gStartTimeTracker = std::chrono::steady_clock::now();

inline void EnableMemoryTracking() { gMemtrack = 1; };

inline void DisableMemoryTracking() { gMemtrack = 0; };

inline void ResetMemoryTacking()
{
    gAllocated = 0;
    gAllocatedCount = 0;
    gDeleted = 0;
    gDeletedCount = 0;
}

inline void PrintMemory()
{
    std::cout << "Allocated : " << gAllocated << std::endl;
    std::cout << "Count     : " << gAllocatedCount << std::endl;
    std::cout << "Deleted   : " << gDeleted << std::endl;
    std::cout << "Count     : " << gDeletedCount << std::endl;
}

inline void ResetTimeTracking()
{
    gStartTimeTracker = std::chrono::steady_clock::now();
}

inline void PrintTimeTracking()
{
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::microseconds>(now - gStartTimeTracker).count();
    std::cout << "Time:" << duration << "ms" << std::endl;
}

void* operator new(size_t size)
{
    if (gMemtrack)
    {
        gAllocated += static_cast<unsigned int>(size);
        gAllocatedCount++;
    }

    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    if (gMemtrack)
    {
        gDeleted += static_cast<unsigned int>(size);
        gDeletedCount++;
    }

    free(memory);
}

class PMRTrackerResource : public std::pmr::memory_resource
{
public:
    PMRTrackerResource(std::pmr::memory_resource* upstream)
        : mUpstream(upstream)
    {
    }

    void* do_allocate(std::size_t size, std::size_t alignment) override
    {
        void* ptr = mUpstream->allocate(size, alignment);
        if (gMemtrack)
            std::cout << "Allocated " << size << " bytes at " << ptr << std::endl;
        return ptr;
    }

    void do_deallocate(void* ptr, std::size_t size, std::size_t alignment) override
    {
        mUpstream->deallocate(ptr, size, alignment);
        if (gMemtrack)
            std::cout << "Deallocated " << size << " bytes at " << ptr << std::endl;
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override
    {
        return (this == &other);
    }

private:
    std::pmr::memory_resource* mUpstream;
};