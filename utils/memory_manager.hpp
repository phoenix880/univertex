#ifndef MEMORY_MANAGER_HPP
#define MEMORY_MANAGER_HPP

#include <cstdlib>
#include <cstdint>
#include <new>
#include <stdexcept>

class MemoryManager {
private:
    static const size_t POOL_SIZE = 1024 * 1024; // 1 MB
    uint8_t* pool;
    size_t used;

public:
    MemoryManager() : pool(new uint8_t[POOL_SIZE]), used(0) {}
    ~MemoryManager() {delete[] pool;}

    template <typename T, typename... Args>
    T* allocate(Args&&... args) {
        if (used + sizeof(T) > POOL_SIZE) throw std::bad_alloc();
        T* ptr = reinterpret_cast<T*>(pool + used);
        used += sizeof(T);
        return new (ptr) T(std::forward<Args>(args)...);
    }

    template <typename T>
    void deallocate(T* ptr) {
        if (ptr >= reinterpret_cast<T*>(pool) &&
            ptr < reinterpret_cast<T*>(pool + POOL_SIZE)) ptr->~T();
        else delete ptr;
    }
};

#endif // MEMORY_MANAGER_HPP
