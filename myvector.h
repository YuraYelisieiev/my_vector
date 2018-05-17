//
// Created by YuraYeliseev on 5/4/18.
//

#ifndef VECTOR_MYVECTOR_H
#define VECTOR_MYVECTOR_H

#include <initializer_list>
#include <algorithm>
#include <utility>

template<class T>
class myvector {
    void alloc_new(size_t);

private:
    bool in_memory(T* element){ return element>= begin() && element<= end(); }

    class memory_manager {
        template<class T2>

        void swap(memory_manager &other) {
            std::swap(data, other.data);
            std::swap(used, other.used);
            std::swap(capacity, other.capacity);
        }

    public:
        ~memory_manager()
        {
            destroy(data, data + used);
            operator delete(data);

        }
        explicit memory_manager(size_t cap = 0) : used(0) {
            data = static_cast<T *>(::operator new(sizeof(T) * cap == 0 ? 2 : cap));
            capacity = cap == 0 ? 2: cap;
        }

        size_t used;
        T *data;
        size_t capacity;

        void copy_unin(memory_manager &other) {
            for (size_t i = 0; i < other.used; i++) {
                construct(other.data + i, data[i]);
            }
            other.used = used;
        }
    } memory;


public:
    T* begin(){return memory.data;};

    T* end(){return memory.data + memory.used;};

    explicit myvector(size_t);

    template<class T2>
    static void construct(T *p, T2 &init) {
        new(p) T(init);
    }

    static void destroy(T *p) {
        p->~T();
    }

    template<class Iterto>
    static void destroy(Iterto beginit, Iterto endit){
        while (beginit != endit){
            destroy(&*beginit);
            ++beginit;
        }
    }

    myvector(const myvector &);

    myvector(std::initializer_list<T> lst);

    myvector(size_t, T element);

    void pushback(const T &);

    void delete_last(){
        destroy(memory.data + memory.used);
        --memory.used;
    }

    size_t size();

    T operator[](size_t);

    myvector &operator=(const myvector &);

    void resize(size_t new_size);

    myvector operator+=(const T &);

};

#include "myvector_impl.h"

#endif //VECTOR_MYVECTOR_H
