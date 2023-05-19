
/*preprocessor header file guard*/
#ifndef STD_TYPES_H
#define STD_TYPES_H

#define NULL_PTR	(void *)0

typedef char * pstring;
typedef char   string;

//1Byte data types
typedef unsigned char u8 ;
typedef signed char s8    ;

//2Bytes date types
typedef short unsigned int  u16 ;
typedef short signed int  s16 ;

//4Bytes data types
typedef  unsigned int  u32 ;
typedef  signed int  s32 ;

//floating data types
typedef float f32 ;
typedef double f64 ;
typedef long double f128 ;

typedef unsigned long long int		u64;

#endif
