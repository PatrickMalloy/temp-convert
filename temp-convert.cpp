#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  float temp, converted;
  char from, to;

  cout << "Number of command line arguments (argc): " << argc << endl; 
       
  for (int i = 0; i < argc; ++i) 
    cout << "argv[" << i << "] : " << argv[i] << endl;       
  
  if(argc == 4) {
    temp = stof(argv[1]);
    from = toupper(argv[2][0]);
    to = toupper(argv[3][0]);
    cout << temp << from << " is ";

    switch(from) {
      case 'F':
        if(to == 'C') {
          converted = (temp-32)*5/9;
        }
        else if(to == 'K') {
          converted = (temp+459.67)*5/9;
        }
        break;
      case 'C':
        if(to == 'F') {
          converted = temp*1.8+32; // 9/5 == 1.8
        }
        else if(to == 'K') {
          converted = temp+273.15;
        }
        break;
      case 'K':
        switch(to) {
          case 'F':
            converted = temp*1.8-459.67;
            break;
          case 'C':
            converted = temp - 273.15;
            break;
        }
        break;
      default:
        cout << "invalid 'from' input" << endl;
    }
    cout << converted << to << endl;
  }
  else
    cout << "Invalid number of inputs. Expected (temp, from, to)" << endl;

  return 0; 
}