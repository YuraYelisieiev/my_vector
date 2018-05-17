//
// Created by YuraYeliseev on 5/4/18.
//
#include "myvector.h"

template<class T>
myvector<T>::myvector(size_t i) : memory(i){ }

template<class T>
myvector<T>::myvector(const myvector &other): memory(other.memory.used) {
    while (memory.used < other.memory.used){
        construct(memory.data + memory.used, other.memory.data[memory.used]);
        ++memory.used;
    }
}

template<class T>
myvector<T>::myvector(size_t size1, T element) : memory(size1){
    while (memory.used < size1){
        construct(memory.data + memory.used, element);
        ++memory.used;
    }
}

template<class T>
myvector<T>::myvector(std::initializer_list<T> lst) : memory(lst.size()){
    for (auto i = lst.begin(); i != lst.end(); i++, memory.used++) {
        construct(memory.data + memory.used, *i);
    }
}


template<class T>
void myvector<T>::pushback(const T &i) {
    if (memory.used == memory.capacity){
        //if the element is in the same vector we make copy of it
        const T& elem = in_memory(&i)? T(i): i;
        alloc_new(memory.capacity * 2);
        construct(memory.data + memory.used, elem);
        ++memory.used;
    }else
    {
        construct(memory.data + memory.used, i);
        ++memory.used;
    }
}

template<class T>
T myvector<T>::operator[](size_t i) {
    return memory.data[i];
}


template<class T>
void myvector<T>::alloc_new(size_t new_cap) {
    if(new_cap > memory.capacity) {
        myvector temp(new_cap, T());
        memory.copy_unin(temp.memory);
        memory.swap(temp.memory);
    }
}

template<class T>
size_t myvector<T>::size() {
    return memory.used;
}

template<class T>
myvector<T>& myvector<T>::operator=(const myvector &arr) {
    memory.swap(arr.memory);
    return *this;
}

template<class T>
myvector<T> myvector<T>::operator+=(const T &i) {
    this->pushback(i);
    return *this;
}

template<class T>
void myvector<T>::resize(size_t new_size) {
    if ( new_size > memory.used ){
        alloc_new(new_size);
        for (size_t t = memory.used; t < new_size; t++){
            pushback(T());
        }
    }
    if(new_size < memory.used){
        while (new_size != memory.used){
            delete_last();
        }
    }
}