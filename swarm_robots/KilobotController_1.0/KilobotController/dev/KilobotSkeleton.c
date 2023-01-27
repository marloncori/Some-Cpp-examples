// developed by mike rubenstein at harvard university
// licensed under creative commons attribution-NonCommercial-ShareAlike 3.0 Unported (CC BY-NC-SA 3.0)
// more info at http://creativecommons.org/licenses/by-nc-sa/3.0/

// adapted by K-Team SA, 2012

// version 1.0 15.03.2012

#include "libKilobot.h" // include Kilobot library file


static int init=1;
static int robot_id=0;
static int TestLED=0;


// user program function
void user_program(void)
{
	/////////////////////////////////////////////////////////////////////////////////////
	//user program code goes here.  this code needs to exit in a resonable amount of time
	//so the special message controller can also run
	/////////////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////////////
	//
	//  In the example below, the robots are moving if they can't see each other.
	//  Otherwise,they are displaying they distance to each other with the rgb led.
	//  
	////////////////////////////////////////////////////////////////////////////////////

	// if the first time the loop is called, initialise the robot id
	if (init)
	{
		int randseed=0;
		// generate random seed (must be placed AFTER init_robot()
		
		for(int i=0;i<30;i++)
			randseed+=get_ambient_light( );//generate some random sensor data

		srand(randseed);//seed random variable with some sensor data

		// generate robot id
		robot_id = rand() & 255;

		init=0;
	}
	

  // Print the ambient light on the debug port

	kprints("ambient l:");
	kprinti(get_ambient_light());

	kprints("          ");
	
	// Print robot id
	kprints("own id:   ");
	kprinti(robot_id);
	kprints("          ");

	message_out(robot_id,255,0);//set message to be sent over IR

	enable_tx=1;//enable transmission of message every .2 seconds

	//check for message

	_delay_ms(10);//wait 10 ms

	get_message();

	if(message_rx[5]==1)//new message has been received

	{

		set_motor(0,0);

		if(message_rx[3] == 33)
			set_color(3,3,3);//turn RGB LED White

		else if(message_rx[3] < 40)
	    set_color(3,0,0);//turn RGB LED Red

		else if(message_rx[3] < 50)
		  set_color(3,3,0);//turn RGB LED Orange

		else if(message_rx[3] < 60)
		  set_color(0,3,0);//turn RGB LED Green

		else if(message_rx[3] < 70)			
		  set_color(0,3,1);//turn RGB LED Turquoise

		else if(message_rx[3] < 80)
			set_color(0,0,3);//turn RGB LED Blue

		else if(message_rx[3] < 90)
			set_color(3,0,3);//turn RGB LED Violet

		kprints("received:");
		kprints("id mes dis");
		kprinti(message_rx[0]);//send first byte of received message over serial debug cable
		kprinti(message_rx[1]);//send second byte of received message over serial debug cable
		kprinti(message_rx[3]);//send measured distance from transmitting robot over serial debug cable

		kprints("          ");
		kprints("          ");

		_delay_ms(500);//wait 10 ms

		set_color(0,0,0);//turn RGB LED off


	}

	else

	{

	   if(++TestLED > 39)

	   {

	    TestLED = 3;

	    set_motor(0,0);

	    }

	   else if(TestLED <= 15)

	   {

	     set_color(TestLED>>2,0,0);

	     if(TestLED == 4)

	     {

	       set_motor(0xA0,0xA0);

	       _delay_ms(100);

	     }

	     set_motor(cw_in_straight,ccw_in_straight);



	   }

	   else if(TestLED <= 27)

	   {

	     set_color(0, (TestLED>>2)-3,0);

	     if(TestLED == 16)

	     {

	       set_motor(0,0);

	       _delay_ms(50);

	       set_motor(0xA0,0);

	       _delay_ms(100);

	     }

	     set_motor(cw_in_place,0);

	    }

	   else if(TestLED <= 39)

	   {

	     set_color(0,0,(TestLED>>2)-6);

	     if(TestLED == 28)

	     {

	       set_motor(0,0);

	       _delay_ms(50);

	       set_motor(0,0xA0);

	       _delay_ms(100);

	     }

	     set_motor(0,ccw_in_place);

	   }

	   _delay_ms(500);



	}                       


	
}



// main
int main(void)
{
  // no instruction should be placed before init_robot();
	// because nothing is already initialised  !!
	
	// initialise the robot
	init_robot(); 

 
  // loop and run each time the user program
	main_program_loop(user_program); 

	
}

