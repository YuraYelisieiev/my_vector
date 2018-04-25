#include <iostream>

using namespace std;

template<class T>
class myvector {
    int vsize, maxsize;
    T *array;

    void alloc_new();

public:
    myvector();

    myvector(int);

    myvector(const myvector &);

    ~myvector();

    void pushback(const T &);

    int size();

    T operator[](int);

    myvector &operator=(const myvector &);

    void resize(int size);

    myvector &operator+=(const T &);

    int at(T &i);
};

template<class T>
myvector<T>::myvector() {
    maxsize = 20;
    array = new T[maxsize];
    vsize = 0;
}

template<class T>
myvector<T>::myvector(int i) {
    maxsize = i;
    array = new T[maxsize];
    vsize = 0;
}

template<class T>
myvector<T>::myvector(const myvector &arr) {
    if (this != &arr) {
        maxsize = arr.maxsize;
        vsize = arr.vsize;
        array = new T[maxsize];
        for (int i = 0; i < arr.vsize; i++) {
            array[i] = arr.array[i];
        }
    }
}

template<class T>
myvector<T>::~myvector() {
    delete[] array;
}

template<class T>
void myvector<T>::pushback(const T &i) {
    if (vsize + 1 > maxsize) {
        alloc_new();
    }
    array[vsize] = i;
    vsize++;
}

template<class T>
T myvector<T>::operator[](int i) {
    return array[i];
}

template<class T>
int myvector<T>::at(T &i) {
    if (i < vsize) return array[i];
    throw 10;
}

template<class T>
void myvector<T>::alloc_new() {
    maxsize = vsize * 2;
    T *tmp = new T[maxsize];
    for (int i = 0; i < vsize; i++)
        tmp[i] = array[i];
    delete[] array;
    array = tmp;
}

template<class T>
int myvector<T>::size() {
    return vsize;
}

template<class T>
myvector<T> &myvector<T>::operator=(const myvector &arr) {
    if (this != &arr) {
        maxsize = arr.maxsize;
        vsize = arr.vsize;
        delete[] array;
        array = new T[maxsize];
        for (int i = 0; i < arr.vsize; i++) {
            array[i] = arr.array[i];
        }
    }
    return *this;
}

template<class T>
myvector<T> &myvector<T>::operator+=(const T &i) {
    this->pushback(i);
    return *this;
}

template<class T>
void myvector<T>::resize(int new_size){
    T* temp = new T[new_size];
    for (int i = 0; i < vsize; i++){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
    temp = NULL;
}


int main() {
    int *i;
    i = new int;
    cout << *i;
    delete i;
    return 0;
}
