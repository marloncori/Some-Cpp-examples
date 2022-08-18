#include <iostream>
#include <cmath>
#include <windows.h>
#include <tuple>

float Hilfe, diskr; 

std::tuple<float, float, float> NimmDaten();
bool EineReeleLoesung(float value);
bool ZweiReeleLoesungen(float value);
bool ZweiKomplexeLoesungen(float value);
bool NichtGleichNull(float value);
std::string GleichungLoesen(float a, float b, float c);

int main(){
   float a, b, c;
   std::string solution;
   
   system("color 2e");
   std::cout << "\n\n\t [INFO] PROGRAM IS ABOUT TO START... " << std::endl;	
   
   Sleep(2000);      
   std::tie(a, b, c) = NimmDaten();

    std::cout << "\n You\'ve chosen these values: \n\t A = " << a 
	   << "\n\t B = " << b << "\n\t C = "<< c << std::endl;
   Sleep(2000);

   solution = GleichungLoesen(a, b, c);
    std::cout << solution << std::endl;
   
   Sleep(1000);
   std::cout << "\n\n\t [INFO] END OF PROGRAM. " << std::endl;
  
  return 0;
}

std::tuple<float, float, float> NimmDaten(){
	float A, B, C;
	
	std::cout << "\n Loesen einer Gleichung der volgender Form: \n\n\t a*x^2 + b*x + c = 0 " << std::endl;
	std::cout << "\n\n\t\t a = ";
	std::cin >> A;
	std::cout << "\n\n\t\t b = ";
	std::cin >> B;
	std::cout << "\n\n\t\t c = ";
	std::cin >> C;
	Sleep(1000);	
   return std::make_tuple(A, B, C);
}

bool EineReeleLoesung(float value){
	if(value != 0.0){
		return false;
	}
  return true;
}

bool ZweiReeleLoesungen(float value){
	if(value < 0.0){
		return false;
	}
	else if(value > 0.0){
		return true;
	}
}


bool ZweiKomplexeLoesungen(float value){
	if(value > 0.0){
		return false;
	}
	else if(value < 0.0){
		return true;
	}
}

bool NichtGleichNull(float value){
	if(value != 0){
		return true;
	}
	else {
		return false;
	}
}

std::string GleichungLoesen(float a, float b, float c){
	std::string result;
	
	if(NichtGleichNull(a)){
   	  Hilfe = -0.5 * (b / a);
   	  diskr = Hilfe * ((Hilfe - c) / a);
   	  if(EineReeleLoesung(diskr)){
   	 	 result = " \n ::: There is only one solution: \n\t ---> x = " + std::to_string(Hilfe) + "\n";
	  } 
 	  else if(ZweiReeleLoesungen(diskr)){
		 result = " \n ::: There are two real solutions: \n\t ---> x1 = " + std::to_string(Hilfe + std::sqrt(diskr)) 
		   + " \n\t ---> x2 = " + std::to_string(Hilfe - std::sqrt(diskr)) + "\n";
	  }
	  else if(ZweiKomplexeLoesungen(diskr)){
	  	 result = " \n ::: There are two complex solutions: \n\t ---> x1 = " + std::to_string(Hilfe) + " + "  + std::to_string(std::sqrt(-diskr))
		    + " \n\t ---> x2 = " + std::to_string(Hilfe) + " - " + std::to_string(std::sqrt(-diskr)) + "\n";
	  }
   } 
   else if(NichtGleichNull(b)){
   	  result = "    x = " + std::to_string(-c/b) + "\n";
   } 
   else if(NichtGleichNull(c)){
   	  result = "  Die Gleichung kann icht geloest werden!\n";
   } 
   else {
   	  result = "  Es gibt unendlich viele Loesungen...\n";
   }  
   return result;
}
