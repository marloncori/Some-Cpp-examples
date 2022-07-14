#include <iostream>
#include <cstdlib>
#include <errno.h>
#include <system_error>

#define left_joystick_x  "A0"
#define left_joystick_y  "A1"
#define right_joystick_x "A2"
#define right_joystick_y "A3"

class Arduino {
   private:
     const std::string msg;
   public:
      Arduino();
      print(const std::string& msg);
      println(const std::string& msg);
};

Arduino::Arduino(){
   std::cout << "\n Program is about to start...\n\n" << std::endl;
}

Arduino::print(const std::string& msg){
   std:: cout << msg;
}

Arduino::println(const std::string& msg){
     std::cout << msg << std::endl;

}

int x_axis_degree = 90;
int y_axis_degree = 90;
int z_axis_degree = 85;
int clamp_degree = 90;

Arduino Serial;

int analogRead(const std::string& pot){
   int value = 0;

   if(pot.compare("A0") == 0){
     std::cout << "Potentiometer value (connected at " << pot << " pin): ";
   }
   else if(pot.compare("A1") == 0){
     std::cout << "Potentiometer value (connected at " << pot << " pin): ";
   }
   else if(pot.compare("A2") == 0){
     std::cout << "Potentiometer value (connected at " << pot << " pin): ";
   }
   else if(pot.compare("A3") == 0){
     std::cout << "Potentiometer value (connected at " << pot << " pin): ";
   }
   else {
     std::cerr << "Invalid potentiometer pin!" << std::endl;
     exit(-1);
   }
   std::cin >> value;
     if(value < 0 || value > 1023){
       throw std::system_error(errno,
         std::system_category(), "Invalid value! Range: 0 ... 1023");
     }
     else {
        std::cout << " ---> The value read is: " << value << std::endl;
     }
  return value;
}

void loop() {
    int left_joystick_x_value = analogRead(left_joystick_x);
    int left_joystick_y_value = analogRead(left_joystick_y);
    int right_joystick_x_value = analogRead(right_joystick_x);
    int right_joystick_y_value = analogRead(right_joystick_y);

    if(left_joystick_x_value < 340) y_axis_degree -=7;
    else if(left_joystick_x_value > 680) y_axis_degree +=7;

    if(left_joystick_y_value < 340) clamp_degree -=5;
    else if(left_joystick_y_value > 680) clamp_degree +=5;

    if(right_joystick_x_value < 340) x_axis_degree -=7;
    else if(right_joystick_x_value > 680) x_axis_degree +=7;

    if(right_joystick_y_value < 340) z_axis_degree -=7;
    else if(right_joystick_y_value > 680) z_axis_degree +=7;

    z_axis_degree = std::min(145, std::max(15, z_axis_degree));
    x_axis_degree = std::min(175, std::max(40, x_axis_degree));
    y_axis_degree = std::min(150, std::max(5, y_axis_degree));
    clamp_degree = std::min(90, std::max(75, clamp_degree));

	Serial.println("\n --------------------- ");
	Serial.println("  -- ROBOT -- ARM --");
	Serial.println(" --------------------- ");
    Serial.print("\n\t ::: x_axis_degree: ");
    Serial.println(std::to_string(x_axis_degree));
    Serial.print("\t ::: y_axis_degree: ");
    Serial.println(std::to_string(y_axis_degree));
    Serial.print("\t ::: z_axis_degree: ");
    Serial.println(std::to_string(z_axis_degree));
    Serial.print("\t ::: clamp_degree: ");
    Serial.println(std::to_string(clamp_degree));
}

int main(){

    loop();

  return 0;
}
