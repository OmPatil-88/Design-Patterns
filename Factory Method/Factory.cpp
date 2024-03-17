#include <iostream>

// The Interface of the product which includes declarations of all operations which must implement

class Product
{
public:
    virtual std::string Operation() const = 0;
    virtual ~Product() {}
};

/*
With the reference of above interface define implementation of specific products classes
we have to implement the inteface method and also we can add more methods which are product specific
*/

class FirstProduct : public Product
{
public:
    std::string Operation() const override
    {
        return "Result of the FirstProduct";
    }
};

class SecondProduct : public Product
{
public:
    std::string Operation() const override
    {
        return "Result of the SecondProduct";
    }
};

/*
    The Creator class declares the factory method that is supposed to return an object
    of product class. The Creators subclasses usually provide the implementation of this method
*/

class Creator
{
public:
    virtual Product *FactoryMethod() const = 0;
    virtual ~Creator(){};

    std::string SomeOperation() const
    {

        Product *product = this->FactoryMethod();

        std::string result = "Creator: The same creator's code has worked with" + product->Operation();

        delete product;
        return result;
    }
};

class FirstProductCreator : public Creator
{
public:
    Product *FactoryMethod() const override
    {
        return new FirstProduct();
    }
};

class SecondProductCreator : public Creator
{
public:
    Product *FactoryMethod() const override
    {
        return new SecondProduct();
    }
};

/*

    The client code works with an instance of a concrete creator

*/

void ClientCode(const Creator &creator)
{

    std::cout << "Client: I'm not aware of the creator's class, but it still works. \n"
              << creator.SomeOperation() << std::endl;
}

int main()
{

    std::cout << "App: Launched with the Creator of FirstProduct.\n";
    Creator *Firstcreator = new FirstProductCreator();
    ClientCode(*Firstcreator);
    std::cout << std::endl;

    std::cout << "App: Launched with the Creator of SecondProduct.\n";
    Creator *SecondProduct = new SecondProductCreator();
    ClientCode(*SecondProduct);
    std::cout << std::endl;

    delete Firstcreator;
    delete SecondProduct;
    return 0;
}