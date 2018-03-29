#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#define N 64
// Prototypes
void alarmHandler(int);
void quitHandler(int);
int main () {

// set signal handlers
signal ( SIGALRM, alarmHandler );
signal ( SIGINT, quitHandler );
    
    char quit[5] = {'e','x','i','t','\0'};
    char userName[N]= {'\0'};
    alarm(30);
    printf("Enter user Name: ");
    scanf("%s", userName);
   
   while( strcmp(userName,"exit")!=0){
    printf("Your Username is: %s\n\n", userName);
    printf("Enter Username: ");
    scanf("%s", userName);
    alarm(30);
   }
    exit(0);
}

void alarmHandler( int theAlarm ) {
  printf("\n30 second alarm, Time up\n");
  printf("\nEnter user Name: ");
  fflush(stdout);
  alarm(30);
  return;
 }
void quitHandler ( int theInt) {
  printf("\nEnter exit to quit\n");
  printf("Enter user Name: ");
  fflush(stdout);
  alarm(30);    // reset alarm
  return;
}