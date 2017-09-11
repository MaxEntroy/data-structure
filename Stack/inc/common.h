#ifndef common_H
#define common_H

/* 函数结果状态码 */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
//#define OVERFLOW -2
//#define UNDERFLOW -3

/* 类型定义 */
typedef int Status;		// Status是函数的类型，其值是函数结果状态码
typedef int ElemType;	// ElemType是数据类型

#endif