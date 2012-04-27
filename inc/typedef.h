/**
 * @file typedef.h
 *
 * @defgroup commonGroup Common
 * 
 */

#ifndef TYPEDEF_H
#define TYPEDEF_H

#define UINT_8  unsigned char
#define UINT_16 unsigned int
#define UINT_32 unsigned long

#define INT_8 signed char
#define INT_16 signed int
#define INT_32 signed long

#define FLOAT float
#define DOUBLE double

#define BOOL unsigned char
#define FALSE 0
#define TRUE 1

typedef enum {
    DATA_TYPE_UINT8,
    DATA_TYPE_UINT16,
    DATA_TYPE_UINT32,
    DATA_TYPE_INT8,
    DATA_TYPE_INT16,
    DATA_TYPE_INT32,
    DATA_TYPE_FLOAT,
    DATA_TYPE_DOUBLE
}DATA_TYPE;

#endif