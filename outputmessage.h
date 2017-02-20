#ifndef OUTPUTMESSAGE_H
#define OUTPUTMESSAGE_H

#include <iostream>
using namespace std;

class OutputMessage
{
public:
    explicit OutputMessage();
    static void outputMessage(string message) { std::cout << message << std::endl; }
};

#endif // OUTPUTMESSAGE_H
