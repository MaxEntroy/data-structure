#ifndef SORT_H
#define SORT_H
#include "common.h"

// ÅÅĞò²Ù×÷ÉùÃ÷
Status insert_sort( ElemType* arr, int n ); // ²åÈëÅÅĞò
Status insert_sort1( ElemType* arr, int n); // ÕÛ°ë²éÕÒ²åÈëÅÅĞò
Status shell_sort( ElemType* arr, int n );  // Ï£¶ûÅÅĞò
Status bubble_sort( ElemType* arr, int n ); // Ã°ÅİÅÅĞò
Status bubble_sort1( ElemType* arr, int n );// Ã°ÅİÅÅĞò - ³Áµ×·¨
Status bubble_sort2( ElemType* arr, int n );// Ã°ÅİÅÅĞò - Ã°Åİ·¨
Status select_sort( ElemType* arr, int n ); // Ñ¡ÔñÅÅĞò
Status quick_sort( ElemType* arr, int n );  // ¿ìËÙÅÅĞò
Status maxheap_sort( ElemType* arr, int n );// ¶ÑÅÅĞò - ´ó¸ù¶Ñ - ÉıĞò
Status minheap_sort( ElemType* arr, int n );// ¶ÑÅÅĞò - Ğ¡¸ú¶Ñ - ½µĞò
Status merge_sort( ElemType* arr, int n );  // ¶şÂ·¹é²¢ÅÅĞò
Status count_sort( ElemType* arr, int n ); // ¼ÆÊıÅÅĞò

// ¸¨Öú²Ù×÷ÉùÃ÷
Status swap(ElemType& a, ElemType& b);
int partition(ElemType* arr, int low, int high);
Status quick_sort_helper( ElemType* arr, int low, int high );
Status maxsift( int* arr, int i, int m );
Status minsift( int* arr, int i, int m );
Status merge_sort_helper( ElemType* arr, int low, int high );
Status merge( ElemType* arr, int low, int mid, int high );


#endif