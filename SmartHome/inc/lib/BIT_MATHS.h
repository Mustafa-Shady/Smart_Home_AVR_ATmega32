
/*preprocessor header file guard*/
#ifndef BIT_MATHS_H
#define BIT_MATHS_H

//this function is to set a specific bit in a variable
#define SET_BIT(VAR,BIT)    (VAR |= (1<<BIT))

//this function is to clear a specific bit in a variable
#define CLR_BIT(VAR,BIT)    (VAR &= (~(1<<BIT)))

//this function is to toggle a specific bit in a variable
#define TGL_BIT(VAR,BIT)    (VAR ^= (1<<BIT))

//this function is to get the value of a specific bit in a variable
#define GET_BIT(VAR,BIT)    ((VAR>>BIT)&1)

//this function is to set a value=0|1 to a specific bit in a variable
#define WRT_BIT(VAR,BIT,BIT_VALUE)  (VAR = (BIT_VALUE<<BIT) | (VAR &= (~(1<<BIT))))
 
 
 
 #endif
