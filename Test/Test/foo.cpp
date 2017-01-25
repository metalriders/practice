#include "foo.h"

Foo::Foo()
{
}

Foo::~Foo()
{
}

void Foo::HelloWorldTo(std::string name)
{
	std::cout << "Hello world " << name << "\n";
}
