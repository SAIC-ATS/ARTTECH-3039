#include "MyClass.h"


float MyClass::getDifficultInt() const
{
    float j = 0;

    for (std::size_t i = 0; i < 100000000; ++i)
    {
        j += ofRandom(0.001);

        if (!isThreadRunning())
        {
            break;
        }
    }

    return j;
}

void MyClass::threadedFunction()
{
    while (isThreadRunning())
    {
        float myDifficultInteger = getDifficultInt();

        channel.send(myDifficultInteger);
    }
}
