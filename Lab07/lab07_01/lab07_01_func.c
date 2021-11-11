#include "lab07_01_func.h"

void swap(int array[], long pos1, long pos2)
{
    long tmp;
    tmp=array[pos1];
    array[pos1]=array[pos2];
    array[pos2]=tmp;
}
void qs_sort(int array[], long start, long end)
{
    long head=start, tail=end-1, tmp;
    long diff=end-start;
    long pe_index;
    // якщо залишилося менше двох елементів – кінець рекурсії
    if (diff<1) return;
    if (diff==1)
        if (array[start]>array[end]) {
            swap(array, start, end);
            return;
        }
    // пошук індексу розділяючого елементу pe_index
    long m=(start+end)/2;
    if (array[start]<=array[m]) {
        if (array[m]<=array[end]) pe_index=m;
        else if (array[end]<=array[start]) pe_index=start;
        else pe_index=end;
    }
    else {
        if (array[start]<=array[end]) pe_index=start;
        else if(array[end]<=array[m]) pe_index=m;
        else pe_index=end;
    }
    long pe=array[pe_index]; // сам розділяючий елемент
    swap(array,pe_index,end);
    while (1) {
        while(array[head]<pe)
            ++head;
        while(array[tail]>pe && tail>start)
            --tail;
        if (head>=tail) break;
        swap(array,head++, tail--);
    }
    swap(array,head,end);
    long mid=head;
    qs_sort(array, start, mid-1); // рекурсивний виклик для 1-ої підмножини
    qs_sort(array, mid+1, end); // рекурсивний виклик для 2-ої підмножини
}

void bubble_sort(int array[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 1; j < size - i; j++){
            if(array[j] < array[j-1]) swap(array, j, j-1);
        }
    }
}

int is_sorted(int array[], int size){
    for(int i = 1; i < size; i++){
        if(array[i] < array[i-1]) return 0;
    }
    return 1;
}

int is_equal_arrays(int array1[], int array2[], int size){
    for(int i = 0; i < size; i++){
        if(array1[i] != array2[i]) return 0;
    }
    return 1;
}