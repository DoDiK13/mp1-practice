#include <iostream>
#include <exception>
#include <string>


template <class T>
class Container {
private:
    T* elems;
    int size;
    int count = 0;
    unsigned int step;
public:
    Container(int, int);
    Container(const Container<T>&);
    ~Container();
    void InsertElement(const T&);
    int SearchElement(const T&) const;
    void DeleteElement(const T&);
    T operator [] (int) const;
    const Container<T>& operator = (const Container<T>&);

    friend std::ostream& operator << (std::ostream& os, const Container<T>& c) {
        os << "[";
        for (int i = 0; i < c.count; i++) {
            os << c[i];
            if (i < c.count - 1) os << ", ";
        }
        os << "]";
        return os;
    }

    int get_size() const {
        return this->size;
    }

    int get_count() const {
        return this->count;
    }
};

template <class T>
Container<T>::Container(int size, int step) {
    if (step <= 0) {
        throw std::exception("no valid step");
    }
    elems = new T[size];
    this->size = size;
    this->step = step;
}

template <class T>
Container<T>::Container(const Container<T>& temp) {
    this->size = temp.size;
    this->step = temp.step;
    this->elems = new T[this->size];
    this->count = temp.count;
    for (int i = 0; i < this->count; i++) {
        this->elems[i] = temp.elems[i];
    }
}

template <class T>
Container<T>::~Container() {
    delete[] elems;
}

template <class T>
void Container<T>::InsertElement(const T& elem) {
    if (count == size) {
        T* tmp_elems = new T[size + step];
        for (int i = 0; i < count; i++) {
            tmp_elems[i] = this->elems[i];
        }
        delete[] this->elems;
        this->elems = tmp_elems;
        this->size += step;
    }
    this->elems[count++] = elem;
}

template <class T>
int Container<T>::SearchElement(const T& elem) const {
    for (int i = 0; i < count; i++) {
        if (elems[i] == elem) {
            return i;
        }
    }
    return -1;
}

template <class T>
void Container<T>::DeleteElement(const T& elem) {
    int index = SearchElement(elem);
    if (index == -1) {
        throw std::exception("element not found");
    }
    elems[index] = elems[--count];
}

template <class T>
T Container<T>::operator [] (int index) const {
    if (index < 0 || index > count - 1) {
        throw std::exception("invalid index");
    }
    return elems[index];
}

template <class T>
const Container<T>& Container<T>::operator = (const Container<T>& temp) {
    if (this == &temp) {
        return *this;
    }

    if (this->size != temp.size) {
        this->size = temp.size;
        this->step = temp.step;
        delete[] this->elems;
        this->elems = new T[size];
    }

    this->count = temp.count;
    for (int i = 0; i < count; i++) {
        this->elems[i] = temp.elems[i];
    }
    return *this;
}


template <class T>
class Container<T*> {
private:
    T** elems;
    int size;
    int count = 0;
    int step;
public:
    Container(int, int);
    Container(const Container<T*>&);
    ~Container();
    void InsertElement(T* const&);
    int SearchElement(T* const&) const;
    void DeleteElement(T* const&);
    T* operator [] (int) const;
    const Container<T*>& operator = (const Container<T*>&);

    int get_size() const {
        return this->size;
    }

    int get_count() const {
        return this->count;
    }

    friend std::ostream& operator << (std::ostream& os, const Container<T*>& c) {
        os << "[";
        for (int i = 0; i < c.count; i++) {
            if (c.elems[i])
                os << *(c.elems[i]);
            else
                os << "null";
            if (i < c.count - 1) os << ", ";
        }
        os << "]";
        return os;
    }
};

template <class T>
Container<T*>::Container(int size, int step) {
    if (step <= 0) {
        throw std::exception("no valid step");
    }
    elems = new T * [size];
    this->size = size;
    this->step = step;
}

template <class T>
Container<T*>::Container(const Container<T*>& temp) {
    this->size = temp.size;
    this->step = temp.step;
    this->elems = new T * [this->size];
    this->count = temp.count;
    for (int i = 0; i < this->count; i++) {
        this->elems[i] = new T(*temp.elems[i]);
    }
}

template <class T>
Container<T*>::~Container() {
    for (int i = 0; i < count; i++) {
        delete elems[i];
    }
    delete[] elems;
}

template <class T>
void Container<T*>::InsertElement(T* const& elem) {
    if (count == size) {
        T** tmp_elems = new T * [size + step];
        for (int i = 0; i < count; i++) {
            tmp_elems[i] = new T(*this->elems[i]);
        }
        for (int i = 0; i < count; i++) {
            delete elems[i];
        }
        delete[] this->elems;
        this->elems = tmp_elems;
        this->size += step;
    }
    this->elems[count++] = elem;
}

template <class T>
int Container<T*>::SearchElement(T* const& elem) const {
    for (int i = 0; i < count; i++) {
        if (elems[i] == elem) {
            return i;
        }
    }
    return -1;
}

template <class T>
void Container<T*>::DeleteElement(T* const& elem) {
    int index = SearchElement(elem);
    if (index == -1) {
        throw std::exception("element not found");
    }
    delete elems[index];
    elems[index] = elems[--count];
}

template <class T>
T* Container<T*>::operator [] (int index) const {
    if (index < 0 || index > count - 1) {
        throw std::exception("invalid index");
    }
    return elems[index];
}

template <class T>
const Container<T*>& Container<T*>::operator = (const Container<T*>& temp) {
    if (this == &temp) {
        return *this;
    }

    for (int i = 0; i < count; i++) {
        delete elems[i];
    }

    if (this->size != temp.size) {
        this->size = temp.size;
        this->step = temp.step;
        delete[] this->elems;
        this->elems = new T * [size];
    }

    this->count = temp.count;
    for (int i = 0; i < count; i++) {
        this->elems[i] = new T(*temp.elems[i]);
    }
    return *this;
}