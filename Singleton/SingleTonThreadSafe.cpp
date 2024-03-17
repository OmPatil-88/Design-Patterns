

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

typedef int t_instance_release_status;
typedef int t_instance_cout;
#define STAUTS_REFCOUNT_REMOVED 1
#define STAUTS_INSTANCE_RELEASED 2
#define STAUTS_INVALID_INSTANCE 3

class Singleton
{

private:
    static Singleton *singleton;
    static std::mutex mutex_;
    static t_instance_cout refCount;

    // Declare Variable as per requirement
    std::string str;

    Singleton(const std::string str) : str(str)
    {
    }

    ~Singleton()
    {
    }

public:
    // Singleton should not be clonable
    Singleton(Singleton &other) = delete;
    // Singleton should not be assignable
    void operator=(const Singleton &) = delete;

    // make get instace customize as per need
    static Singleton *GetInstance(const std::string &value);
    static t_instance_release_status ReleaseInstance();
    std::string value() const
    {
        return str;
    }

    // Add The function as you want
    //...
};

Singleton *Singleton::singleton = nullptr;
int Singleton::refCount = 0;
std::mutex Singleton::mutex_;

Singleton *Singleton::GetInstance(const std::string &value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (Singleton::singleton == nullptr)
    {
        Singleton::singleton = new Singleton(value);
        refCount = 1;
    }
    refCount;
    return singleton;
}

t_instance_release_status Singleton::ReleaseInstance()
{
    if (Singleton::singleton == nullptr)
        return STAUTS_INVALID_INSTANCE;

    std::lock_guard<std::mutex> lock(mutex_);
    refCount--;
    if (Singleton::refCount == 0)
    {
        return STAUTS_INSTANCE_RELEASED;
    }
    return STAUTS_REFCOUNT_REMOVED;
}

void Thread1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("First Thread");
    std::cout << singleton->value() << std::endl;
    Singleton::ReleaseInstance() == STAUTS_INSTANCE_RELEASED ? std::cout << "Instance Released\n" : std::cout << "RefCount Removed\n";
}

void Thread2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::GetInstance("Second Thread");
    std::cout << singleton->value() << std::endl;
    Singleton::ReleaseInstance() == STAUTS_INSTANCE_RELEASED ? std::cout << "Instace Released\n" : std::cout << "RefCount Removed\n";
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