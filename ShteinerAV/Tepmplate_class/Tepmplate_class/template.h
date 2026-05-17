template <class T>
class Container {
private:
    T* elems;
    int size;
    int count = 0;
    int step = 1; 
public:
    Container(int, int);
    Container(const Container <T>&);
    ~Container();
    void InsertElement(const T&);
    int SearchElement(const T&) const;
    void DeleteElement(const T&);
    T operator [] (int) const;
    const Container<T>& operator = (const Container<T>&);
};

template <class T>
Container<T>::Container(int size, int step) {
    if (step <= 0) {
        throw std::exceprion("no valid step")
    }
    elems = new T[size];
    this->size = size;
    this->step = step;
}

template <class T>
Container<T>::Container(const Container<T>& temp) {
    this->size = temp.size;
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
        Container<T> temp(size + step, step);
        temp.count = this->count;

        for (int i = 0; i < temp.count; i++) {
            temp.elems[i] = this->elems[i];
        }

        (*this) = temp;
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
        throw std::exception("no find");
    }
    elems[index] = elems[--count];
}

template <class T>
T Container<T>::operator [] (int index) const {
    if (index < 0 || index > count - 1) {
        throw std::exception("no index");
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
        delete[] this->elems;
        this->elems = new T[size];
    }

    this->count = temp.count;
    for (int i = 0; i < count; i++) {
        this->elems[i] = temp.elems[i]; 
    }

    return *this;
}