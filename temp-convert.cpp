#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::stof;

/**
 * Convert a temperature from one scale to another
 * temp-convert 32 f c
 * 
 * @param temperature
 * @param from scale
 * @param to scale
*/
int main(int argc, char* argv[]) {
  float temperature, converted;
  char from, to;
  bool success=false;

  cout << "Number of command line arguments (argc): " << argc << endl; 
       
  for (int i = 0; i < argc; ++i) 
    cout << "argv[" << i << "] : " << argv[i] << endl;

  cout << endl;   
  
  if(argc == 4) {
    // convert temperature character string to a float
    temperature = stof(argv[1]);

    // save just the first character of the character strings
    // and convert to Uppercase
    from = toupper(argv[2][0]);
    to = toupper(argv[3][0]);

    switch(from) {
      case 'F':
        if(to == 'C') {
          // tempC = (tempF - 32) * 5 / 9
          converted = (temperature-32.0)*5/9;
          success=true;
        }
        else if(to == 'K') {
          // tempK = (tempF + 459.67) * 5 / 9
          converted = (temperature+459.67)*5/9;
          success=true;
        }
        else {
          cout << "Invalid 'to' input. Expected (c,f,k)" << endl;
        }
        break;
      case 'C':
        if(to == 'F') {
          // tempF = (tempC * 9 / 5) + 32
          // 9 / 5 == 1.8
          converted = temperature*1.8+32.0;
          success=true;
        }
        else if(to == 'K') {
          // tempK = tempC + 273.15
          converted = temperature+273.15;
          success=true;
        }
        else {
          cout << "Invalid 'to' input. Expected (c,f,k)" << endl;
        }
        break;
      case 'K':
        switch(to) {
          case 'F':
            // tempF = (tempK * 9 / 5) - 459.67
            converted = temperature*1.8-459.67;
            success=true;
            break;
          case 'C':
            // tempC = tempK - 273.15
            converted = temperature - 273.15;
            success=true;
            break;
          default:
            cout << "Invalid 'to' input. Expected (c,f,k)" << endl;
        }
        break;
      default:
       cout << "Invalid 'from' input. Expected (c,f,k)" << endl;
    }
    if(success)
      cout << temperature << from << " is " << converted << to << endl;
  }
  else
    cout << "Invalid number of inputs. Expected (temp, from, to)" << endl;

  return 0; 
}