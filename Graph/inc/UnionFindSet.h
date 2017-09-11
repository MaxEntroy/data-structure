 #ifndef UnionFindSet_H
#define UnionFindSet_H
#include "common.h"

Status make_set( int* tree, int n );
Status find_set( int* tree, int i );
bool union_set( int* tree, int i, int j ); // true for union, false for not union

#endif