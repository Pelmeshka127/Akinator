#ifndef ARCHITECTURE_H_
#define ARCHITECTURE_H_

enum Errors_Code {
    No_Error        = 0,
    Bad_Alloc       = 1,
    File_Error      = 2,
    Undef_Capacity  = 3,
    Underflow       = 5,
    Overflow        = 6,
};

const int Max_Length = 40;

#endif