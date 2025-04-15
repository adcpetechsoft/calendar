/*
    Month Year Calendar inquiry Display
    As a submission to https://code.golf/calendar#c

    Note:
    This program can run without error if self installed 
    But Errors happpend on submission to the indicated website

    Created by: amd

*/


// ---------------------------------
// Preprocessor Declaration


#define STR_SIZE 50

#define P_OK 0
#define P_RES_NON_LEAP 20
#define P_ERR_NUM -10
#define P_ERR_VAL -20

#include <stdio.h>
#include <string.h>
#include <time.h>



// ---------------------------------
// Function calendar_leap declaration
// use to inquire for leap year
int calendar_leap(int y)
{
     // ***********************
    // Variable Declaration
    int res;

     // ***********************
    // Actual Function

    // Test the variable for leapyear

    if( (y%4==0) && (y%100 != 0) || (y%400 == 0) )
    {
        // If leapyear
        res=P_OK;
    }else
    {
        // If ordinary year
        res=P_RES_NON_LEAP;
    };

    // return the result
    return res;

};



// ---------------------------------
// Function calendar_inquire declaration
// use to inquire the week according to the given month, day and year
int calendar_inquire(int month, int day, int year)
{
    // ***********************
    // Variable Declaration
    int res;

    int week;

    time_t tm01;
    struct tm *ctm01;

    // ***********************
    // Actual Function

    // Intialize calendar according to present
    tm01=time(NULL);
    ctm01=localtime(&tm01);

    // Setting the Calendar from parameters
    ctm01->tm_mon=(month-1);
    ctm01->tm_year=(year-1900);
    ctm01->tm_mday=(day);

    // Conditioning the inputed parameters
    tm01=mktime(ctm01);
    ctm01=localtime(&tm01);

    // Getting the week
    week=(ctm01->tm_wday)+1;

    // place the result
    res=week;


    // return the result
    return res;

};


// ---------------------------------
// Function calendar_display declaration
// use to display the whole month of the year
int calendar_display(int month, int year)
{
    // ***********************
    // Variable Declaration
    int res;

    int x;
    int w;

    int end_date;
    int mfirstday;

    char str01[STR_SIZE];



    // ***********************
    // Actual Function

    // Setting the result to  OK as initial
    res=P_OK;

    // Setting the Month Name and end date
    switch(month)
    {
        case 1: end_date=31; (str01, STR_SIZE, "January"); break;
        case 2: snprintf(str01, STR_SIZE, "February");
                if( (calendar_leap(year)) == P_OK )
                {
                    end_date=29;
                }else
                {
                    end_date=28;
                };
        
                break;
        case 3: end_date=31;snprintf(str01, STR_SIZE, "March"); break;
        case 4: end_date=30;snprintf(str01, STR_SIZE, "April"); break;
        case 5: end_date=31;snprintf(str01, STR_SIZE, "May"); break;
        case 6: end_date=30;snprintf(str01, STR_SIZE, "June"); break;
        case 7: end_date=31;snprintf(str01, STR_SIZE, "July"); break;
        case 8: end_date=31;snprintf(str01, STR_SIZE, "August"); break;
        case 9: end_date=30;snprintf(str01, STR_SIZE, "September"); break;
        case 10: end_date=31;snprintf(str01, STR_SIZE, "October"); break;
        case 11: end_date=30;snprintf(str01, STR_SIZE, "November"); break;
        case 12: end_date=31;snprintf(str01, STR_SIZE, "December"); break;
        default: res=P_ERR_NUM; break;
    };



    // Display the Calendar if OK
    if(res==P_OK)
    {
        mfirstday=calendar_inquire(month, 1, year);

        printf("Mo Tu We Th Fr Sa Su\n");

        w=2;

        while(w!=mfirstday)
        {
            printf("   ");
            w++;
            if(w>7)
            {
                w=1;
            };
        };

        x=1;
        while(x<=end_date && x<=31)
        {
            printf("%2i ", x);
            w++;
            if(w>7)
            {
                w=1;
            };

            if(w==2)
            {
                printf("\n");
            };

            x++;

        };

        printf("\n");
        

    };


    // return the result
    return res;
};

// *********************************
// ---------------------------------
// Program Entry Point
int main(int argc, char *argv[])
{
    // ***********************
    // Variable Declaration
    int x;
    int i;

    int m;
    int y;

    char str01[STR_SIZE];
    char str02[STR_SIZE];

    
    // ***********************
    // Actual Program Run


    // Test for inputed Arg
    if(argc>1)
    {
        x=1;

        // Scanning the Arg then call the display
        while(x<argc)
        {
            // Getting the Month from ARG
            snprintf(str01, STR_SIZE, "%s", argv[x]);
            sscanf(str01, "%i", &m);

            // Getting the Year from ARG
            snprintf(str02, STR_SIZE, "%s", argv[x+1]);
            sscanf(str02, "%i", &y);

            // Calling the function to display
            calendar_display(m, y);

            // Print Spacing for display good purpose
            printf("\n");

            // increment for other input
            x++;
            x++;

        };

    }else
    {
        // Display if situaltion is on ARG
        printf("ERROR: No Arg input. Input <MM> <YYYY> as ARG...\n\n");
    }


    // Program END
    return 0;

};

