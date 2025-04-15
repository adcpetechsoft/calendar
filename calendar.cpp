#define STR_SIZE 50

#define P_OK 0
#define P_RES_NON_LEAP 20
#define P_ERR_NUM -10
#define P_ERR_VAL -20

#include <stdio.h>
#include <string.h>
#include <time.h>

int calmonth[31];

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

int calendar_fill(int m, int y)
{
    int res;

    int x;
    
    int w;
    int end_date;

    time_t tm01;
    struct tm *ctm01;
    

    for(x=0; x<31; x++)
    {
        calmonth[x]=0;
    };

    tm01=time(NULL);
    ctm01=localtime(&tm01);

    ctm01->tm_year=(y-1900);
    ctm01->tm_mon=(m-1);
    ctm01->tm_mday=1;

    tm01=mktime(ctm01);
    ctm01=localtime(&tm01);

    w=ctm01->tm_wday + 1;

    res=P_OK;

    switch(m)
    {
        case 1: end_date=31; break;
        case 2: 
            if( calendar_leap(y) == P_OK )
            {
                end_date=29;
            }else
            {
                end_date=28;

            };
            break;
        case 3: end_date=31; break;
        case 4: end_date=30; break;
        case 5: end_date=31; break;
        case 6: end_date=30; break;
        case 7: end_date=31; break;
        case 8: end_date=31; break;
        case 9: end_date=30; break;
        case 10: end_date=31; break;
        case 11: end_date=30; break;
        case 12: end_date=31; break;
        default: end_date=P_ERR_NUM; break;
    };

    x=0;
    while(x<end_date && end_date>0)
    {
        calmonth[x]=w;
        x++;
        w++;
        if(w>7)
        {
            w=1;
        };

    };

    res=end_date;


    return res;
};

int calendar_draw(int m, int y)
{
    int res;

    char str01[STR_SIZE];

    int end_date;

    int x;
    int y;
    int z;

    switch(m)
    {
        case 1: snprintf(str01, STR_SIZE, "January"); break;
        case 2: snprintf(str01, STR_SIZE, "February"); break;
        case 3: snprintf(str01, STR_SIZE, "March"); break;
        case 4: snprintf(str01, STR_SIZE, "April"); break;
        case 5: snprintf(str01, STR_SIZE, "May"); break;
        case 6: snprintf(str01, STR_SIZE, "June"); break;
        case 7: snprintf(str01, STR_SIZE, "July"); break;
        case 8: snprintf(str01, STR_SIZE, "August"); break;
        case 9: snprintf(str01, STR_SIZE, "September"); break;
        case 10: snprintf(str01, STR_SIZE, "October"); break;
        case 11: snprintf(str01, STR_SIZE, "November"); break;
        case 12: snprintf(str01, STR_SIZE, "December"); break;
        default: res=P_ERR_VAL; break;

    };

    if( (end_date=calendar_fill(m, y)) > 0 )
    {

        printf("%s %i\n", str01, y);
        printf("S\tM\tT\tW\tH\tF\tS\n");

        x=1;
        y=1;
        z=0;

        while(x<5 && z<=end_date)
        {
            y=1;
            while(y<=7 && x<=end_date)
            {
                if(y==calmonth[z])
                {
                    printf("i", z);
                    z++;
                };

                printf("\t");

                y++;
            };

            printf("\n");

            x++;
        };

        

        res=P_OK;
    }else
    {
        res=P_ERR_VAL;
    };


    return res;
}


int main(int argc, char *argv[])
{
    int x;
    int m;
    int y;

    char str01[STR_SIZE];

    if(argc==3)
    {

        snprintf(str01, STR_SIZE, "%s", argv[1]);
        sscanf(str01, "%i", &m);

        snprintf(str01, STR_SIZE, "%s", argv[2]);
        sscanf(str01, "%i", &y);

        if( calendar_fill(m, y) == P_OK)
        {

        };


        

    };





    return 0;
}
