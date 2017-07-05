#include "Cat.h"
#include "Dog.h"

int main() {
	
	Pet* cat = new Cat("Nikki", 4, "White");
	cat->show();
	cat->type();
	cat->sound();

	std::cout << std::endl;

	Cat c("Mike", 6, "Gray");
	c.show();
	c.type();
	c.sound();
	std::cout << "my damage is " << c.attack() << std::endl;

	std::cout << std::endl;

	Dog d("Beowulf", 2, "black", "");
	d.set_owner_name("Kirill");
	d.show();
	d.type();
	d.sound();
	std::cout << "My owner is " << d.get_owner_name() << std::endl;;
	std::cout << "Food store decrease " << d.eat()<< std::endl;
	
	return 0;
}