#include <iostream>
#include <memory>

struct Base
{
    virtual void foo() {}
    /* virtual */ ~Base() { std::cout << "~Base" << std::endl; }
};

struct Derived : public Base
{
    void foo() override { std::cout << "foo()" << std::endl; }
    ~Derived() { std::cout << "~Derived" << std::endl; }
};

auto greater_than(int a,int b) {
	return (a>b) ? a : b;
}

int main()
{
	char *c;int i;
	c=(char *) &i;
	int a[20];
	auto aa=alignof(Derived);

	greater_than(2,3);

    std::unique_ptr<Base> ptr = std::make_unique<Derived>();
    ptr->foo(); // correctly prints foo()
    // prints only ~Base, ~Derived was not called, memory is leaking
}
