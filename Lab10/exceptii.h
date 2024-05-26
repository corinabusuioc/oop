#pragma once
#include <iostream>
#include <exception>

class exceptie1 : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Index out of bounds";
    }
};

class exceptie2 : public std::exception
{
    virtual const char* what() const throw()
    {
        return "Invalid capacity";
    }
};

int verify_index(int index, int size)
{
    exceptie1 index_out_of_bounds;
    try
    {
        if (index < 0 || index >= size)
            throw index_out_of_bounds;
    }
    catch (std::exception& e)
    {
        std::cout << "Exceptie: " << e.what() << std::endl;
        return 0;
    }
    return 1;
}

int verify_capacity(int capacity)
{
    exceptie2 invalid_capacity;
    try
    {
        if (capacity < 0)
            throw invalid_capacity;
    }
    catch (std::exception& e)
    {
        std::cout << "Exceptie: " << e.what() << std::endl;
        return 0;
    }
    return 1;
}
