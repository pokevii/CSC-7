/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: grizz
 *
 * Created on October 26, 2021, 8:25 PM
 */

#include <iostream>
#include <string>

#include "GeneralHashFunctions.h"

int main(int argc, char* argv[])
{
   const std::string key = "Then out spake brave Horatius, "
   "The Captain of the Gate: "
   "To every man upon this earth "
   "Death cometh soon or late. "
   "And how can man die better "
   "Than facing fearful odds, "
   "For the ashes of his fathers, "
   "And the temples of his gods.";

   std::cout << "General Purpose Hash Function Algorithms Test"   << std::endl;
   std::cout << "By Arash Partow - 2002"                          << std::endl;
   std::cout << "Modified by Joshua Grizzell - 2021"              << std::endl;
   std::cout << "Original string: \n"            << key           << std::endl;
   std::cout << " 1. RS-Hash Function Value:   " << RSHash  (key) << std::endl;
   std::cout << " 2. JS-Hash Function Value:   " << JSHash  (key) << std::endl;
   std::cout << " 3. PJW-Hash Function Value:  " << PJWHash (key) << std::endl;
   std::cout << " 4. ELF-Hash Function Value:  " << ELFHash (key) << std::endl;
   std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
   std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
   std::cout << " 7. DJB-Hash Function Value:  " << DJBHash (key) << std::endl;
   std::cout << " 8. DEK-Hash Function Value:  " << DEKHash (key) << std::endl;
   std::cout << " 9. FNV-Hash Function Value:  " << FNVHash (key) << std::endl;
   std::cout << "10. BP-Hash Function Value:   " << BPHash  (key) << std::endl;
   std::cout << "11. AP-Hash Function Value:   " << APHash  (key) << std::endl;

   return 1;
}
