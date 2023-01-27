
#include <iomanip>
#include <iostream>

int arduinoMap(const float& readValue, const float& maxValue, const float& maxOutput);

int main()
{
  std::cout << "\n\t Voltage equivalent: " << std::setprecision(3) 
  << arduinoMap(1.364, 2.50, 1023.0) << "\n\n";

  std::cout << "\t Speed equivalent: " << std::setprecision(2) 
  << arduinoMap(127.5, 255.0, 1023) << "\n";

 return 0;
}

int arduinoMap(const float& readValue,
		const float& maxValue, const float& maxOutput)
{
   return static_cast<int>((readValue/maxValue) * maxOutput);
}
