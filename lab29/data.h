#pragma once
#include <cstdio>
#include <ctime>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <iomanip>
using std::string;
using std::cout;
using std::cin;
using std::endl;

template<typename T>
bool less(T &aValue1, T &aValue2)
{
    return aValue1 < aValue2;
}


template< class T >
class List {
public:
    T **data;
    int count;


    List(){

    }
    List(const List &copy) : count(copy.count) {
        data = new T *[count];
        for (int i = 0; i < count; ++i) {
            data[i] = new T(*copy.data[i]);
        }
    }
    int getCount() {
        return count;
    }
    void  add(T* arr){

        //data[pos] = element;
        T** new_array = new T*[this->count + 1];
        for (int i = 0; i < this->count; ++i) {
            new_array[i + 1] = this->data[i];
        }
        new_array[0] = new T(*arr);
        for (int i = 0; i < 3; ++i) {
            cout << arr[i] << endl;
        }

        delete this->data;
        this->data = new_array;
        this->count++;

    }

    T index(size_t pos){
        return *data[pos];
    }
    void print(){
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << data[i][j] << endl;
            }


        }

    }


    //template < typename T >
    void my_swap ( T & first , T & second ) //T - тип, указанный в параметре шаблона
    {
        T temp(first) ; //временная переменная должна быть того же типа, что и параметры
        first = second ;
        second = temp ;
    }

    template < class ElementType >
    void bubbleSort(ElementType * arr, size_t arrSize)
    {
        for(size_t i = 0; i < arrSize - 1; ++i)
            for(size_t j = 0; j < arrSize - 1; ++j)
                if (arr[j + 1] < arr[j])
                    my_swap ( arr[j] , arr[j+1] ) ;
    }

    template < typename ElementType >
    void out_array ( const ElementType * arr , size_t arrSize )
    {
        for ( size_t i = 0 ; i < arrSize ; ++i )
            std::cout << arr[i] << ' ' ;
        std::cout << std::endl ;
    }
    void printMin() {
        for (int i = 0; i < count; ++i) {
            cout << "Print minimal: " << *data[i] << endl;
        }


    }


};
template <typename T2>
bool sortAsc(T2 a, T2 b) {
    return a < b;
}
