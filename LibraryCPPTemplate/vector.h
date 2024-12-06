#ifndef VECTOR_TEMPLATE_H
#define VECTOR_TEMPLATE_H

#include <cstddef>

template <typename Data> class Vector
{
public:
    // Creates vector
    Vector()
    {
        sizev = 0;
        rash = 1;
        data = new Data[rash];
    }

    Vector(const Vector& other)
        : data(new Data[other.rash]), sizev(other.sizev), rash(other.rash)
    {
        for (size_t i = 0; i < sizev; ++i) {
            data[i] = other.data[i];
        }
    }

    Vector& operator=(const Vector& other)
    {
        if (this != &other) {
            delete[] data; // Освобождение старой памяти
            data = new Data[other.rash];
            sizev = other.sizev;
            rash = other.rash;
            for (size_t i = 0; i < sizev; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    // Deletes vector structure and internal data
    ~Vector()
    {
        delete[] data;
    }

    // Retrieves vector element with the specified index
    Data get(size_t index) const
    {
        return data[index];
    }

    // Sets vector element with the specified index
    void set(size_t index, Data value)
    {
        data[index] = value;
    }

    // Retrieves current vector size
    size_t size() const
    {
        return sizev;
    }

    // Changes the vector size (may increase or decrease)
    // Should be O(1) on average
    void resize(size_t size)
    {
        if (rash < size) {
            size_t newrassh = (rash == 0) ? 1 : rash;
            while (newrassh < size)
            {
                newrassh *= 2;
            }

            Data* new_data = new Data[newrassh];


            for (size_t i = 0; i < sizev; ++i)
            {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            rash = newrassh;
        }

        sizev = size;
    }

private:
    Data* data;
    size_t sizev;
    size_t rash;
};

#endif
