/* Serial_state - show state of FSM by using the serial monitors
 Put your #includes here */
#include <stdio.h>
#include "uart.h"
#include "pinMode.h"
#include "unolib.h"
#include "digitalWrite.h"
#include "delay.h"
/* Put your global variables here */
int state;
int number;
int bit0 = 2;
int bit1 = 4;
int bit2 = 6;
/* Main */ 
int main() {
/* initialize code goes here */
pinMode(bit0, OUTPUT);  
pinMode(bit1, OUTPUT);
pinMode(bit2, OUTPUT);
init_serial();        
state = 0;
number = 0;
// while(1) loop routine runs over and over again forever:
    while(1) {
		printf("Currently in state %d\n", state);
        /* Print a line of text requesting a 0 or 1 */
        /* then input the character and make it an integer */
        puts("Enter 0 or 1:");
        char input = getchar();
        number = input - '0';
        printf("You entered: %d\n", number);
        if (state == 0) {
            if (number == 0) 
                state = 0;
            else if (number == 1) {
                state = 1;
            digitalWrite(bit0, HIGH);
            digitalWrite(bit1, LOW);
            digitalWrite(bit2, LOW);
              puts("Going to State 1");
            }
        }
        else if (state == 1) {
             if (number == 1) 
                state = 1;
            else if (number == 0){
              state = 2;
            digitalWrite(bit0, LOW);
            digitalWrite(bit1, HIGH);
            digitalWrite(bit2, LOW); 
              puts("Going to State 2");
              }
            
        }
        else if (state == 2) {
             if (number == 0) 
                state = 2;
            else if (number == 1){
              state = 3;
            digitalWrite(bit0, HIGH);
            digitalWrite(bit1, HIGH);
            digitalWrite(bit2, LOW);
              puts("Going to State 3");
              }
            
        }
        else if (state == 3) {
             if (number == 0) 
                state = 3;
            else if (number == 1){
              state = 4;
            digitalWrite(bit0, LOW);
            digitalWrite(bit1, LOW);
            digitalWrite(bit2, HIGH);
              puts("Going to State 4");
              }
            
        }
        else if (state == 4) {
             if (number == 1) 
                state = 4;
            else if (number == 0){
              state = 5;
            digitalWrite(bit0, HIGH);
            digitalWrite(bit1, LOW);
            digitalWrite(bit2, HIGH);
              puts("Going to State 5");
              }
            
        }
        else if (state == 5) {
             if (number == 0) 
                state = 5;
            else if (number == 1){
              state = 6;
          printf("Congratulations, you reached the end.");
          for(int i = 0; i < 5; i++){
          digitalWrite(bit0, HIGH);
          delay(100);
          digitalWrite(bit0, LOW);
          delay(100);  
          digitalWrite(bit1, HIGH);
          delay(100);
          digitalWrite(bit1, LOW);
          delay(100);
          digitalWrite(bit2, HIGH);
          delay(100);
          digitalWrite(bit2, LOW);
          delay(100);
          }
      break;
     }
            
   }
  }          
    return 0;
  } 
  


