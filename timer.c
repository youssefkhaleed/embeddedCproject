#include "lcd_drivers.h"
#include "delays.h"
#include "leds_on.h"
#include "leds_off.h"
#include "switches_inputs.h"
void timer(int m,int s)
{

int j=m;
int i=s;
int k;
	leds_on();

  for(; j>=0 ; j--)                       // minute parameter 
	{
	for (; i>=0 ;i--)                   // second parameter
	{
		spaces(4);                        // displaying 4 spaces
	  LCD4bits_Data((j/10)+'0');         // tens of minute
	  LCD4bits_Data((j%10)+'0');        // units of minute
	  LCD4bits_Data(':');
	  LCD4bits_Data((i/10) +'0');       // tens of second
	  LCD4bits_Data((i%10)+'0');       // units of second 
    k=delay_mil();                   // wait for 1 second
	  if(k==1) 
		{	
		   leds_off();
			return;
		}                 // check if switch 1 is pressed or not 
		LCD4bits_Cmd(0x01);             // clear lcd display 
	 }
i=59;                                // reset second every loop
}
   finished();

}
