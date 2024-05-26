#pragma once
#include "exceptii.h"
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template <typename T>
class GenericCompare : public Compare
{
public:
    int CompareElements(void* e1, void* e2) override
    {
        T* elem1 = static_cast<T*>(e1);
        T* elem2 = static_cast<T*>(e2);
        if (*elem1 < *elem2) 
            return -1;
        if (*elem1 > *elem2) 
            return 1;
        return 0;
    }
};

template <typename T>
int compareDesc(T& a, T& b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}

template <typename T>
int compareCresc(T& a, T& b)
{
    if (a < b)
        return 1;
    if (a > b)
        return -1;
    return 0;
}

template<class T>
class ArrayIterator
{
private:
    T** List;
    int Current; 
public:
    ArrayIterator(T** list, int curent) : List(list), Current(curent) {}
    ArrayIterator& operator ++ ()
    {
        Current++;
        return (*this);
    }
    ArrayIterator& operator -- ()
    {
        Current--;
        return (*this);
    }
    bool operator= (ArrayIterator<T>& other)
    {
        return Current == other.Current;
    }
    bool operator!=(ArrayIterator<T>& other) 
    {
        return Current != other.Current;
    }
    T* GetElement()
    {
        return List[Current];
    }
};
template<class T>
class Array
{
private:
    T** List; 
    int Capacity;
    int Size; 
public:
    Array() : Capacity(0), Size(0) {}
    ~Array() 
    {
        for (int i = 0;i < Size;i++)
            delete List[i];
        delete[] List;
    }
    Array(int capacity) 
    {
        if (verify_capacity(capacity) == 1)
        {
            Capacity = capacity;
            Size = 0;
            List = new T * [Capacity];
            for (int i = 0;i < Capacity;i++)
                List[i] = new T;
        }
    }
    Array(const Array<T>& otherArray) 
    {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0;i < Capacity;i++) {
            List[i] = new T;
            List[i] = otherArray.List[i];
        }
    }

    T& operator[] (int index) 
    {
        if (verify_index(index, Size) == 1)
            return (*List[index]);
    }

    const Array<T>& operator+=(const T& newElem)
    {
        List[Size++] = new T(newElem);
        return (*this);
    }
    const Array<T>& Insert(int index, const T& newElem)
    {
        if (verify_index(index, Size) == 1)
        {
            for (int i = Size;i >= index + 1;i--)
                List[i] = List[i - 1];
                List[index] = new T(newElem);
            Size++;
        }
        return (*this);
    }
    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (verify_index(index, Size) == 1)
        {
            int s = otherArray.Size;
            if (s != 0)
            {
                for (int i = Size - 1 + s;i >= index + s;i--)
                    List[i] = List[i - s];
                for (int i = index;i < index + s;i++)
                    List[i] = otherArray.List[i - index];
                Size += s;
            }
        }
        return (*this);
    }
    const Array<T>& Delete(int index)
    {
        if (verify_index(index, Size) == 1)
        {
            Size--;
            for (int i = index;i < Size;i++)
                List[i] = List[i + 1];
        }
        return (*this);
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (Size != otherArray.Size)
            return 0;
        for (int i = 0;i < Size;i++)
            if (List[i] != otherArray.List[i])
                return 0;
        return 1;
    }

    void Sort()
    {
        for (int i = 0;i < Size;i++)
            for (int j = i + 1;j < Size;j++)
                if (*List[i] > *List[j])
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }
    void Sort(int(*compare)(const T&, const T&)) 
    {
        for (int i = 0;i < Size;i++)
            for (int j = i + 1;j < Size;j++)
                if (compare(*List[i], *List[j]) > 0)
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }
    void Sort(Compare* comparator) 
    {
        for (int i = 0;i < Size;i++)
            for (int j = i + 1;j < Size;j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }

    // BinarySearch - daca array-ul este sortat
    int BinarySearch(const T& elem) 
    {
        int mid, start = 0, end = Size - 1;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (elem < *List[mid])
                end = mid - 1;
            if (elem > *List[mid])
                start = mid + 1;
            if (elem == *List[mid])
                return mid;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int mid, start = 0, end = Size - 1;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (compare(elem, *List[mid]) < 0)
                end = mid - 1;
            if (compare(elem, *List[mid]) > 0)
                start = mid + 1;
            if (compare(elem, *List[mid]) == 0)
                return mid;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator)
    {
        int mid, start = 0, end = Size - 1;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (comparator->CompareElements((void*)&elem, List[mid]) > 0)
                end = mid - 1;
            if (comparator->CompareElements((void*)&elem, List[mid]) < 0)
                start = mid + 1;
            if (comparator->CompareElements((void*)&elem, List[mid]) == 0)
                return mid;
        }
        return -1;
    }

    // Find - daca array-ul nu este sortat
    int Find(const T& elem) 
    {
        for (int i = 0;i < Size;i++)
            if (elem == *List[i])
                return i;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0;i < Size;i++)
            if (compare(elem, *List[i]) == 0)
                return i;
        return -1;
    }
    int Find(const T& elem, Compare* comparator)
    {
        for (int i = 0;i < Size;i++)
            if (comparator->CompareElements((void*)&elem, List[i]) == 0)
                return i;
        return -1;
    }

    int GetSize() 
    {
        return Size;
    }
    int GetCapacity() 
    {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(List, 0);
    }
    ArrayIterator<T> GetEndIterator() 
    {
        return ArrayIterator<T>(List, Size);
    }
};


