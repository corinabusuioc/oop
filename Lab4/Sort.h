#pragma once
class Sort
{
    int* v;
    int count;
public:
    Sort(int count, int mini, int maxi); 
    Sort() : v(new int[8] {9, 6, 31, 12, 54, 11, 3, 10}), count(8) {}; 
    Sort(int *v, int count); 
    Sort(int count, ...); 
    Sort(char *string); 
    void InsertSort(bool ascendent = false); 
    void QuickSort(bool ascendent, int st, int dr); 
    void BubbleSort(bool ascendent = false); 
    void Print(); 
    int  GetElementsCount(); 
    int  GetElementFromIndex(int index); 
};

