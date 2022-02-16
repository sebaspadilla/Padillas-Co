# Padillas-Co mini-project

- [Padillas-Co mini-project](#padillas-co-mini-project)
  * [Description](#description)
  * [Dependencies](#dependencies)
  * [Build and Run](#build-and-run)
  * [Highlighted use of C++ features](#highlighted-use-of-c-features)
  * [Corner cases](#corner-cases)
  * [Future improvements](#future-improvements)

## Description
'Padillas-Co mini-project' implements a basic program to handle the accounts of a business.  
The purpose of the project is to demonstrate the design and implementation of the program and the use of different C++ features. Rather than the final program itself.  
Highlighted features used, corner cases and improvements are commented further in the README.

## Dependencies
A CMake and a C++ compiler environment has to be setup.

## Build and Run
1. Create a `build` folder in the repository's root.
2. Open a cmd inside the `build` folder and build the project with CMake. You can do it by running the following commands:
```
 > cmake -G "MinGW Makefiles" ..
 > cmake --build .
```
3. The program launcher `PadillasCo.exe` is generated in the folder.
4. Run the program launcher.

## Highlighted use of C++ features
Having in mind the requirements of the project I would like to highlight some features of C++ used:
- OOP: Inheritance, encapsulation, abstraction...
- Containers
- Smart Pointers
- Templates

## Corner cases
Some corner cases have been identified during the implementation of the project. These should be fixed in future development of the project.  
Here are some of them listed:
- Create an AdultAccount and afterwards set an age under 18 years. The account remains an "adult account". Same vice versa.
- The ID assignation for new accounts is very weak. Once some accounts have been created and deleted, creation of new accounts might fail.

## Future improvements
Some improvements that should be interesting to implement:
- Unit-testing
- Link Adult-Kid accounts 
    
    
#### *Developer: Sebastian Padilla https://github.com/sebaspadilla*
