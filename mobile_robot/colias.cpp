/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com
Project : 
Version : 
Date    : 11/29/2016
Author  : 
Company : 
Comments: 
Chip type               : ATmega168PA
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega168a.h>

#include <delay.h>


#define Left_DIR PORTD.5
#define Right_DIR PORTD.6    
#define DIR_Forward 0
#define DIR_Backward 1
#define STOP 0


#define Left_SPD  OCR2B
#define Right_SPD OCR2A    

//#define Left_En PORTD.3
//#define Right_En PORTB.3    


#define LED_Top PORTB.7
#define LED_W PORTB.6
#define LED_B PORTB.0

#define IR_En PORTB.2  


//ADC
#define Left_Light 0
#define Right_Light 6

#define Front_IR 3
#define Right_IR 2
#define Left_IR 4

unsigned char forward=40;

#define Sensor_Thr 170
#define R_Sensor_Thr 220   
#define Turn_delay 1000   //ms

void move(int left,int right,int saturation);



#define ADC_VREF_TYPE 0x60

// Read the 8 most significant bits
// of the AD conversion result
unsigned char read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==0);
ADCSRA|=0x10;
return ADCH;
}


char Cue_check(int left,int right, int intensity ){
    if (left>intensity || right>intensity)
        return 1;
    else 
        return 0;
}

int Front,Left,Right;
void read_bumper (int IR,int *front, int *left, int *right){
    int i,f,l,r,n=1;   //n is number of samples 
    IR_En=IR;
    delay_ms(5);
    f=0;
    l=0;
    r=0;
    for (i=0;i<n;i++){
        l+=read_adc(Left_IR);
        f+=read_adc(Front_IR);
        r+=read_adc(Right_IR);  
    }
    *left=l/n;
    *front=f/n;
    *right=r/n;
    
  //  IR_En=0;
}

void Motors (int left, int right){
    int spd;   
    
    
    if (left==STOP && right==STOP){
        move(STOP,STOP,80);
        return;    
    } 
//    Left_En=0;
//    Right_En=0;
    spd= forward;
    
    if (right>0)
        OCR2A=0x80 - spd;
    else 
        OCR2A=0x80 + spd;

    if (left>0)
        OCR2B=0x80 - spd;
    else 
        OCR2B=0x80 + spd;
} 

void set_speed(int left, int right){
    OCR2B=0x80 - left;
    OCR2A=0x80 - right;    
}


void initial(){
        int left=0,right=0;
        int i;
        Motors(STOP,STOP);
        for (i=0; i<2;i++){
            LED_Top=1;
            delay_ms(100);
            LED_Top=0;         
            delay_ms(100);
        }        
        
        
        do {
            left=read_adc(Left_Light);
            right=read_adc(Right_Light);
        }while (left>5 || right>5);
}

void Obstacle_avoidance(){
    int turn_delay_plus=Turn_delay; 
    int light_right=0,light_left=0;
   //------------------------------- Honeybee Aggregation
   read_bumper (1,&Front,&Left,&Right); 
   
   if (Front<R_Sensor_Thr || Left<R_Sensor_Thr || Right<R_Sensor_Thr){ 
            delay_ms(100);
            light_left=read_adc(Left_Light);
            light_right=read_adc(Right_Light);
              //--------------- waiting time of cue  
            if (Cue_check(light_left,light_right,20)==1){ 
                Motors(0,0); 
                LED_W=1;      
                IR_En=1;
                delay_ms(1000+(light_left+light_right)*600);     //waiting time of BEECLUST
                IR_En=0;           
                LED_W=0;
                Motors(-1,1);
                delay_ms(Turn_delay);
                Motors(1,1);
                //LED_Top=0;
                return;
            }   
        }     
     //    Motors(1,1);
   
   
//       read_bumper (0,&Front,&Left,&Right);
//      if (Front<R_Sensor_Thr || Left<R_Sensor_Thr || Right<R_Sensor_Thr){       //----- Detect another robot 
//            Motors(0,0); 
//            delay_ms(100);
//            light_left=read_adc(Left_Light);
//            light_right=read_adc(Right_Light);
//              //--------------- waiting time of cue  
//            if (Cue_check(light_left,light_right,15)==1){ 
//                LED_W=1;      
//                IR_En=1;
//                delay_ms(1000+(light_left+light_right)*1000);     //waiting time of BEECLUST
//                IR_En=0;           
//            }
//            LED_W=0;
//            Motors(-1,1);
//            delay_ms(Turn_delay);
//            Motors(1,1);
//            LED_Top=0;
//            return;
//        }     
        
        
   
                                                   
   
   //------------------------------- Obstacle avoidance
     read_bumper (1,&Front,&Left,&Right);    
    if (Front<Sensor_Thr){
        Motors(-1,-1);
        delay_ms(150); 
        if (Left<Right)
            Motors(-1,1);
        else
            Motors(1,-1);
        delay_ms(turn_delay_plus);
        Motors(1,1);
    }
    else if (Left<Sensor_Thr){
        Motors(-1,1);
        delay_ms(turn_delay_plus);
        Motors(1,1);
    }
    else if (Right<Sensor_Thr){
        Motors(1,-1);
        delay_ms(turn_delay_plus);
        Motors(1,1);
    }   
   // }
}

float correction;
//int sum=0;

void move(int left,int right,int saturation)
{  
//    float c=(correction*sum+((float)right/left))/(sum+1);
//    correction=c;      
//    sum=sum+1;

    correction=1;
            
    if (left > saturation) left = saturation;
    if (left < (-1*saturation)) left = -1*saturation;           
    if (right > saturation) right = saturation;
    if (right < (-1*saturation)) right = -1*saturation;            
//old one 
//    OCR2A=  (128-left);
//    OCR2B=  (128-(correction *right));

    if (left<=0){
//        Left_DIR=DIR_Backward;
        Left_SPD= 255+ left; 
    }
    else{ 
        Left_DIR=DIR_Forward;
        Left_SPD= 255- left; 
    }        

    if (right<=0){
//        Right_DIR=DIR_Backward;
        Right_SPD= 255+ right; 
    }
    else{ 
        Right_DIR=DIR_Forward;
        Right_SPD= 255- right; 
    }        


}


void main(void)
{
// Declare your local variables here

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=0x80;
CLKPR=0x00;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

// Input/Output Ports initialization
// Port B initialization
// Func7=Out Func6=Out Func5=In Func4=In Func3=Out Func2=Out Func1=In Func0=Out 
// State7=0 State6=0 State5=T State4=T State3=0 State2=0 State1=T State0=0 
PORTB=0x00;
DDRB=0xCD;

// Port C initialization
// Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=Out Func5=Out Func4=Out Func3=Out Func2=In Func1=In Func0=In 
// State7=T State6=0 State5=0 State4=0 State3=0 State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x78;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Fast PWM top=0xFF
// OC0A output: Non-Inverted PWM
// OC0B output: Non-Inverted PWM
TCCR0A=0x00;
TCCR0B=0x00;
TCNT0=0x00;
OCR0A=0x00;
OCR0B=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Fast PWM top=0xFF
// OC2A output: Non-Inverted PWM
// OC2B output: Non-Inverted PWM
ASSR=0x00;
TCCR2A=0xA3;
TCCR2B=0x04;
TCNT2=0x00;
OCR2A=0xFF;
OCR2B=0xFF;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// Interrupt on any change on pins PCINT0-7: Off
// Interrupt on any change on pins PCINT8-14: Off
// Interrupt on any change on pins PCINT16-23: Off
EICRA=0x00;
EIMSK=0x00;
PCICR=0x00;

// Timer/Counter 0 Interrupt(s) initialization
TIMSK0=0x00;

// Timer/Counter 1 Interrupt(s) initialization
TIMSK1=0x00;

// Timer/Counter 2 Interrupt(s) initialization
TIMSK2=0x00;

// USART initialization
// USART disabled
UCSR0B=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
ADCSRB=0x00;
DIDR1=0x00;

// ADC initialization
// ADC Clock frequency: 125.000 kHz
// ADC Voltage Reference: AVCC pin
// ADC Auto Trigger Source: ADC Stopped
// Only the 8 most significant bits of
// the AD conversion result are used
// Digital input buffers on ADC0: On, ADC1: On, ADC2: On, ADC3: On
// ADC4: On, ADC5: On
DIDR0=0x00;
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0x86;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

while (1)
      {         
      int light_left, light_right,leave_cue_flag=0;
      long int leave_counter=0; 
      int left_motor_speed, right_motor_speed,con=0;   

      initial();   //wait until light disappears 

     // Motors(0,0);   
      
      
//      PORTD.5=0;
//      PORTD.6=0;
//      OCR2A=150;
//      OCR2B=255;
//      while (1);  
      
        LED_Top=1;
              
      //forward=35;
      while (1){     
        con =4;
//        delay_ms(200);                                           
        //----------------------------------- check for obstacles & Robot 
        Obstacle_avoidance();     
        //----------------------------------- read light sensors
        light_left=read_adc(Left_Light);
        light_right=read_adc(Right_Light); 
        //------------------------------------------------ don't follow light if robot on a cue, 
        if (Cue_check(light_left,light_right,20)==1){ 
            right_motor_speed= forward;
            left_motor_speed= forward; 
            leave_cue_flag=1;      
        } 
        else if (leave_cue_flag==0){                      
        //----------------------------------- Calculate related speed based on light intensity
            if ( (light_left >=5 && light_left<10) || (light_right>=5 && light_right<10)){    
                //LED_Top=1;
                light_left=light_left*3;
                light_right=light_right*3;
            }
            right_motor_speed= ((light_left-light_right)*con)+forward;
            left_motor_speed= ((light_right-light_left)*con)+forward;         
        }       
        
        
        move(left_motor_speed,right_motor_speed,60);    // set speed of forward 
        
        //------------------------  resting delay
       // delay_ms(5);   
        if (leave_cue_flag){
            leave_counter++;
            if (leave_counter>300){
                leave_counter=0;
                leave_cue_flag=0;
            }
        }
      }
    }
}