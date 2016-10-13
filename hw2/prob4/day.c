#include<stdio.h>
#include <stdlib.h>

static char daytab[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int dayofyear(int year,int month,int day);
void monthofday(int year,int yearday,int *pmonth,int *pday);

int main(int argc, char * argv[]){
  int day,mon,dat;
  int val1,val2,val3;
  char * input1 = argv[1];
  char * input2 = argv[2];
  char * input3 = argv[3];
  val1 = atoi(input1);
  val2 = atoi(input2);
  val3 = atoi(input3);

  if (!val3){

  monthofday(val1,val2,&mon,&dat);

  printf("%d %d",mon,dat);
}
else {
  day=dayofyear(val1,val2,val3);

  printf("%d\n",day);
}
  return 0;
}

int dayofyear(int year, int month, int day){
  int i, leap;

  leap=year%4==0 && year%100 !=0 || year %400 == 0;

    if(month < 1 || month > 12)
        return -1;

    if(day < 1 || day > daytab[leap][month])
        return -1;

    for(i=1;i<month;i++)
        day += daytab[leap][i];

    return day;
}
void monthofday(int year,int yearday,int *pmonth,int *pday)
{
    int i,leap;

    if(year < 1)
    {
        * pmonth = -1;
        * pday = -1;
        return;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for(i=1;i<=12 && yearday > daytab[leap][i];i++)
        yearday -= daytab[leap][i];

    if(i > 12 && yearday > daytab[leap][12])
    {
        * pmonth = -1;
        * pday = -1;
    }
    else
    {
        * pmonth = i;
        * pday = yearday;
    }
}
