# temp-convert
This small program will show you how to pass command-line arguments into the main function. It prints them out so you can see what the input looks like.

It will also show you two different ways of doing flow-control: the if-else-if construct and using the switch construct.

## Usage
The below command will convert 32° Fahrenheit to °Celsius
```
temp-convert 32 f c
```
Three parameters are required, the temperature to convert, the scale to convert _from_, and the scale to convert _to_. There are three temperature scales: Celsius [°C], Fahrenheit [°F], kelvin [K], to choose from. If an invalid option is used an error messages is displayed.

One usability feature I added was to use just the first character of the _from_ and _to_ parameters. I used array indices to access the first character but you could also use String functions (overkill in this case). The character is also converted to Uppercase for use in the flow-control statements and for the ouput formatting.

If not enough parameters are supplied, an error message is displayed.

## Prerequisites
- C++ compiler/linker

## Installation
Clone the repository:
```
https://github.com/PatrickMalloy/temp-convert.git
```

## Compile and Run
```
cd temp-convert;
make;
./temp-convert 32 f c
```
## Enhancements
- Add more temperature scales such as the Rankine or Réaumur
- Add an interactive mode that prompts appropiately
