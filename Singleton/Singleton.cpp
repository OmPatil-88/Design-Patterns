

#include <iostream>
#include <thread>
#include <chrono>

class Singleton
{

private:
    static Singleton *singleton;

    // Declare Variable as per requirement
    std::string str;

    Singleton(const std::string str) : str(str)
    {
    }

public:
    // Singleton should not be clonable
    Singleton(Singleton &other) = delete;
    // Singleton should not be assignable
    void operator=(const Singleton &) = delete;

    // make get instace cusotmize as per need
    static Singleton *GetInstance(const std::string &value);
    std::string value() const
    {
        return str;
    }

    // Add The function as you want
    //...
};

Singleton *Singleton::singleton = nullptr;

Singleton *Singleton::GetInstance(const std::string &value)
{

    if (Singleton::singleton == nullptr)
    {
        Singleton::singleton = new Singleton(value);
    }

    return singleton;
}

void Thread1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("First Thread");
    std::cout << singleton->value() << std::endl;
}

void Thread2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("Second Thread");
    std::cout << singleton->value() << std::endl;
}

int main()
{
    std::cout << "If You see the same value then singleton is used \nIf you see the diffrent value then singleton failed for multiple thread \n RESULT:\n";

    std::thread first(Thread1);
    std::thread second(Thread2);

    first.join();
    second.join();

    return 0;
}