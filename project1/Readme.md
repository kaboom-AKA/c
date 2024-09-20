Project 1: Multi-Functional Command Line Application
Overview
This project is a command-line application that provides users with multiple functionalities, including a Hangman game, basic arithmetic calculations, and word counting. Users can navigate through the options until they choose to exit the program.

Features
Hangman Game: Play a classic word-guessing game.
Basic Arithmetic Calculation: Perform simple arithmetic operations.
Word Count: Count the number of words in a provided text.
Exit Option: Gracefully exit the application after user confirmation.
Getting Started
Prerequisites
C Compiler (e.g., GCC)
Access to terminal/command line
Installation
Clone the repository or download the source files.
Ensure the executables for Hangman, math operations, and word counting are available in the same directory or modify the system() calls accordingly.
Usage
Compile the code:

bash
Copy code
gcc -o main main.c
Run the application:

bash
Copy code
./main
Follow the on-screen instructions to select an option by entering the corresponding number.

Exit Program
To exit, choose option 4. You will be prompted to confirm your choice by typing 'Y' or 'y'.

Code Structure
Main Function: Handles user input and navigation between options.
ExitProgram Function: Confirms user intention to exit the application.
