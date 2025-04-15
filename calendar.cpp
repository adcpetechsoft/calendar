#define STR_SIZE 50

#define P_OK 0
#define P_RES_NON_LEAP 20
#define P_ERR_NUM -10
#define P_ERR_VAL -20

#include <stdio.h>
#include <string.h>
#include <time.h>

int calendar_leap(int y)
{
    int res;

    if( (y%4==0) && (y%100 != 0) || (y%400 == 0) )
    {
        res=P_OK;
    }else
    {
        res=P_RES_NON_LEAP;
    };

    return res;
};

