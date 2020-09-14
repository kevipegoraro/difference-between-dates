
// C++ program to calculate number of minutes lived
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
  
// Days in each month
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 
  
// Count the number of bixest years   
int countLeapYears(ano,mes,dia) 
{ 
    int anos = ano; 
    // Check if the current year needs to be considered 
    // for the count of leap years or not 
    if (mes <= 2) 
        anos--; 
  
    // An year is a leap year if it is a multiple of 4, 
    // multiple of 400 and not a multiple of 100. 
    return anos / 4 - anos / 100 + anos / 400; 
} 
  
// Returns the number of days between two dates
int getDifference(ano,mes,dia,anoA,mesA,diaA) 
{ 
    long int n1 = ano*365 + dia;  
    for (int i=0; i<mes - 1; i++) 
        n1 += monthDays[i]; 
 
    n1 += countLeapYears(ano,mes,dia); 
    
    long int n2 = anoA*365 + diaA; 
    for (int i=0; i<mesA - 1; i++) 
    n2 += monthDays[i]; 
    n2 += countLeapYears(anoA,mesA,diaA); 
   
    return (n2 - n1); 
}   
  
// Driver function  
int main() 
{ 
   char a[11],c[5],p[5],at[11];
   int ano,mes,dia,anoA,mesA,diaA;
   long int md,mins;
   md=24*60; 
   printf("Enter your birthday in the format Day\\Month\\Year:\n");
   scanf("%s", a);
   c[0]=a[0]; c[1]=a[1];
   dia=atoi(c);
   c[0]=a[3]; c[1]=a[4];
   mes=atoi(c);
   c[0]=a[6]; c[1]=a[7]; c[2]=a[8]; c[3]=a[9];
   ano=atoi(c);
   if (ano>0 & dia<32 & dia>0 & mes<13 & mes>0) 
   {
         printf("Enter today's date in the format Day\\Month\\Year:\n");
         scanf("%s", at);
   	p[0]=at[0]; p[1]=at[1];
   	diaA=atoi(p);
   	p[0]=at[3]; p[1]=at[4];
   	mesA=atoi(p);
   	p[0]=at[6]; p[1]=at[7]; p[2]=at[8]; p[3]=at[9];
   	anoA=atoi(p);
   	if (anoA>0 & diaA<32 & diaA>0 & mesA<13 & mesA>0) 
            {
	   mins=md*getDifference(ano,mes,dia,anoA,mesA,diaA);
	   printf("Your birth is: %i\\%i\\%i \n",dia,mes,ano);
	   printf("Today's date is: %i\\%i\\%i \n",diaA,mesA,anoA);
	   printf("The days lived are %ld and the minutes lived are: %ld \n", mins/md,mins); 
	   } else printf("Current date invalid, type in format 00\\00\\0000.\n");
   } else printf("Invalid birthday, type in format 00\\00\\0000.\n");	   
   return 0; 
} 

