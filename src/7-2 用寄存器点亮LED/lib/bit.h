#ifndef __LIB_BIT_H
#define __LIB_BIT_H
// 定义位操作
#define SET_DIGIT_1(data, digit) ((data) |= (1 << (digit)))
#define SET_DIGIT_0(data, digit) ((data) &= ~(1 << (digit)))
#define SET_DIGIT(data, digit, value) \
    if ((value) == 1)                 \
        SET_DIGIT_1((data), (digit)); \
    else                              \
        SET_DIGIT_0((data), (digit));

#endif /* __LIB_BIT_H */
