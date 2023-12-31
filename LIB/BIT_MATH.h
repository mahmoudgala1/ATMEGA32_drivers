/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    BIT_MATH.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : LIB
 *
 *
 */

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define CLEAR_BIT(REG,BIT)  (REG &= ~(1<<BIT))
#define SET_BIT(REG,BIT)    (REG |= (1<<BIT))
#define TOGGLE_BIT(REG,BIT) (REG ^= (1<<BIT))
#define GET_BIT(REG,BIT)    ((REG>>BIT)&1)

#endif /* _BIT_MATH_H_ */
