#include "main.h"

void BRIGHT(void)
{
   switch(light_state1)
	 {
	   case BRIGHT_STATE:
		 {
		   PC0_low();
			 PC1_low();
		 }break;
		 
		 case BLACK_STATE:
		 {
		   PC0_high();
			 PC1_high();
		 }break;
	 }
	 
	 switch(light_state2)
	 {
	   case BRIGHT_STATE:
		 {
		   PC2_low();
			 PC13_low();
		 }break;
		 
		 case BLACK_STATE:
		 {
		   PC2_high();
			 PC13_high();
		 }break;
	 }
	 
	 switch(light_state3)
	 {
	   case BRIGHT_STATE:
		 {
		   PC14_low();
			 PC15_low();
		 }break;
		 
		 case BLACK_STATE:
		 {
		   PC14_high();
			 PC15_high();
		 }break;
	 }

}
