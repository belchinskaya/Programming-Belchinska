
#include "data.h"


int main() {
    List<int> * list = new List<int>();
    int pos = 0;

    int arr1[3] = {3, 21, 0};
    int arr2[3] = {43, 51, 6};
    int arr3[3] = {9, 8, 7};
    const size_t n = 3 ;
    //for (int i = 0; i < 3; ++i) {
    list->add(arr1);
    list->add(arr2);
    list->add(arr3);
    //}
    for (int i = 0; i < list->getCount(); ++i) {
        list->index(i);

    }



    std::cout << "Source arrays: " << endl;
    list->out_array (arr1, n ) ;
    list->out_array ( arr2 , n ) ;
    list->out_array ( arr3 , n ) ;
    for (int i = 0; i < list->getCount(); ++i) {
        list->index(i);
        list->bubbleSort ( list->data[i] , n ) ;
    }

    list->bubbleSort ( arr2 , n ) ;
    list->bubbleSort ( arr3 , n );
    cout << "Sorted arrays:" << endl;
    list->out_array ( arr1 , n ) ;
    list->out_array ( arr2 , n ) ;
    list->out_array ( arr3 , n ) ;
    list->printMin();


    //list->print();
    //data.doSort<bool (*)(int, int), int>(5, arr, sortAsc(data.index(arr), data.index(arr)));
    return 0;
}