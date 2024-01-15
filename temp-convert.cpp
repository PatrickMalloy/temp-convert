#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::stof;

int main(int argc, char* argv[]) {
  float temp, converted;
  char from, to;

  cout << "Number of command line arguments (argc): " << argc << endl; 
       
  for (int i = 0; i < argc; ++i) 
    cout << "argv[" << i << "] : " << argv[i] << endl;

  cout << endl;   
  
  if(argc == 4) {
    // convert temperature character string to a float
    temp = stof(argv[1]);

    // save just the first character of the character strings
    // and convert to Uppercase
    from = toupper(argv[2][0]);
    to = toupper(argv[3][0]);

    switch(from) {
      case 'F':
        if(to == 'C') {
          // tempC = (tempF - 32) * 5 / 9
          converted = (temp-32.0)*5/9;
        }
        else if(to == 'K') {
          // tempK = (tempF + 459.67) * 5 / 9
          converted = (temp+459.67)*5/9;
        }
        else {
          cout << "Invalid 'to' input. Expected (c,f,k)" << endl;
        }
        break;
      case 'C':
        if(to == 'F') {
          // tempF = (tempC * 9 / 5) + 32
          // 9 / 5 == 1.8
          converted = temp*1.8+32.0;
        }
        else if(to == 'K') {
          // tempK = tempC + 273.15
          converted = temp+273.15;
        }
        else {
          cout << "Invalid 'to' input. Expected (c,f,k)" << endl;
        }
        break;
      case 'K':
        switch(to) {
          case 'F':
            // tempF = (tempK * 9 / 5) - 459.67
            converted = temp*1.8-459.67;
            break;
          case 'C':
            // tempC = tempK - 273.15
            converted = temp - 273.15;
            break;
          default:
            cout << "Invalid 'to' input. Expected (c,f,k)" << endl;
        }
        break;
      default:
       cout << "Invalid 'from' input. Expected (c,f,k)" << endl;
    }
    cout << temp << from << " is " << converted << to << endl;
  }
  else
    cout << "Invalid number of inputs. Expected (temp, from, to)" << endl;

  return 0; 
}