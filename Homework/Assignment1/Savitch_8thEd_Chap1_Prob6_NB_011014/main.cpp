/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on January 10, 2014, 4:26 PM
 * Savitch 8th Edition Chapter 1 Problem 6
 * Create errors in a previous program
 */

//System Libraries
#include <iostream>
using namespace std;
/* main.cpp:10:21: fatal error:  iostream: No such file or directory
#include < iostream> */
/* main.cpp:23:5: error: ‘cout’ was not declared in this scope
     cout << "Press return after entering a number.\n";
     ^
main.cpp:25:5: error: ‘cin’ was not declared in this scope
     cin >> num1;
     ^
main.cpp:34:28: error: ‘endl’ was not declared in this scope
     cout << "Good-bye." << endl; */
/* main.cpp:10:19: error: missing terminating > character
 #include <iostream */


//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
/* In function `main':
/usr/src/debug/cygwin-1.7.27-2/winsup/cygwin/lib/libcmain.c:39: undefined reference to `WinMain@16'
collect2: error: ld returned 1 exit status
nbproject/Makefile-Debug.mk:62: recipe for target 'dist/Debug/Cygwin_4.x-Windows/savitch_8thed_chap1_prob6_nb_011014.exe' failed
make[2]: *** [dist/Debug/Cygwin_4.x-Windows/savitch_8thed_chap1_prob6_nb_011014.exe] Error 1
make[2]: Leaving directory '/cygdrive/c/Users/Victoria/Documents/NetBeansProjects/Savitch_8thEd_Chap1_Prob6_NB_011014'
nbproject/Makefile-Debug.mk:59: recipe for target '.build-conf' failed
make[1]: *** [.build-conf] Error 2
make[1]: Leaving directory '/cygdrive/c/Users/Victoria/Documents/NetBeansProjects/Savitch_8thEd_Chap1_Prob6_NB_011014'
nbproject/Makefile-impl.mk:39: recipe for target '.build-impl' failed
make: *** [.build-impl] Error 2 */
/* main.cpp:31:32: error: expected ‘)’ before ‘{’ token
 int main(int argc, char** argv { */
/* main.cpp:31:10: error: expected initializer before ‘int’
 int main int argc, char** argv { */
    int num1, num2, sum, prod;
    /* main.cpp:61:12: error: ‘num1’ was not declared in this scope
     cin >> num1;
            ^
main.cpp:71:12: error: ‘num2’ was not declared in this scope
     cin >> num2;
            ^
main.cpp:72:5: error: ‘sum’ was not declared in this scope
     sum = num1 + num2;
     ^
main.cpp:73:5: error: ‘prod’ was not declared in this scope
     prod = num1 * num2; */
    
    cout << "Press return after entering a number.\n";
    /* main.cpp:49:5: error: ‘coot’ was not declared in this scope
     coot << "Press return after entering a number.\n"; */
    /* main.cpp:49:11: error: expected ‘;’ before string constant
     cout  "Press return after entering a number.\n"; */
    /* main.cpp:54:5: error: expected ‘;’ before ‘cout’
     cout << "Enter the first integer: "; */
    /* main.cpp:49:13: warning: missing terminating " character [enabled by default]
     cout << "Press return after entering a number.\n; */
    /* main.cpp:49:10: error: no match for ‘operator>>’ (operand types are ‘std::ostream {aka std::basic_ostream<char>}’ and ‘const char [39]’)
     cout >> "Press return after entering a number.\n"; */
    cout << "Enter the first integer: ";
    cin >> num1;
    /* main.cpp:61:10: error: expected ‘;’ before ‘num1’
     cin  num1; */
    /* main.cpp:61:9: error: no match for ‘operator>’ (operand types are ‘std::istream {aka std::basic_istream<char>}’ and ‘int’)
     cin > num1; */
    /* main.cpp:61:9: error: no match for ‘operator<<’ (operand types are ‘std::istream {aka std::basic_istream<char>}’ and ‘int’)
     cin << num1; */
    /* main.cpp:61:5: error: ‘cen’ was not declared in this scope
     cen >> num1; */
    cout << "Enter the second integer: ";
    cin >> num2;
    sum = num1 + num2;
    /* main.cpp:83:17: error: expected ‘;’ before ‘num2’
     sum = num1  num2; */
    prod = num1 * num2;
    cout << "The sum of " << num1 << " and "
         << num2 << " is " << sum << ".\n"
         << "The product of " << num1 << " and "
         << num2 << " is " << prod << ".\n";
    cout << "Good-bye." << endl;
    /* main.cpp:89:28: error: ‘enl’ was not declared in this scope
     cout << "Good-bye." << enl; */
    
    return 0;
    /* main.cpp:95:5: error: ‘retuurn’ was not declared in this scope
     retuurn 0;
     ^
     main.cpp:95:13: error: expected ‘;’ before numeric constant
     retuurn 0; */
/* main.cpp:62:13: error: expected ‘}’ at end of input
     return 0; */
}

