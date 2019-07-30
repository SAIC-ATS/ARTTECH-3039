#include "ofApp.h"


void ofApp::setup()
{
    // print Hello World!
    //    std::cout << "Hello world." << std::endl;
    //
    // float myFloat = 33.55;
    //    std::cout << myFloat << std::endl;
    // std::cout << "The value of my float is = " << myFloat << std::endl;

    // int i = 33;
    // std::cout << i << std::endl;
    
    // i = i + 10;
    // i += 10;
    
    //i = i + 1;
    //i += 1;
    //i++;
    
    // i = i - 1;
    // i -= 1;
    // i--; // Post-decrement operator
    // --i; // Pre-decrement operator
    
    // i = i * 10;
    // i *= 10;

    // i = i / 10;
    // i /= 10;
    
    //std::cout << i << std::endl;

    
    for (int myFavNum = 0; myFavNum <= 25; myFavNum += 5)
    {
        std::cout << myFavNum << std::endl;
    }

//    0, 3, 6, 9, 12

    for (int i = 0; i <= 12; i += 3)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
//    0, -10, -20, -30, -40

    for (int i = 0; i >= -40; i -= 10)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

//    100, 200, 300, 400, 500

    for (int i = 100; i <= 500; i += 100)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
//    500, 250, 125, 62.5, 31.25
    
    for (float i = 500; i >= 31.25; i /= 2.0)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

//    2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048

    for (float i = 2; i <= 2048; i *= 2.0)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
//    2, 4, 16, 256, 65536, 4294967296

    long squaredNumber = 2;
    for (int i = 0; i < 6; i++)
    {
        std::cout << squaredNumber << " ";
        squaredNumber *= squaredNumber;
    }
    std::cout << std::endl;

    // Fail.
    //    for (uint64_t i = 2; i <= 4294967296; i *= i)
    //    {
    //        std::cout << i << " ";
    //    }
    //    std::cout << std::endl;

    
    std::cout << std::numeric_limits<int>::lowest() << " -> " << std::numeric_limits<int>::max() << std::endl;
    
    std::cout << "# of bytes used for an int: " << sizeof(int) << std::endl;
    
    std::cout << std::numeric_limits<long>::lowest() << " -> " << std::numeric_limits<long>::max() << std::endl;
    
    std::cout << "# of bytes used for an long: " << sizeof(long) << std::endl;

    // int
    // unsigned int
    // long
    // unsigned long
    //
    // uint32_t
    // uint64_t
    //
    // std::size_t
    
//    std::cout << std::numeric_limits<int>::max() << std::endl;
//    std::cout << std::numeric_limits<long>::max() << std::endl;

    
    // Close the program.
    ofExit();
}

