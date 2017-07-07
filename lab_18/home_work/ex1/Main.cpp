#include "Parrot.h"
#include "Hamster.h"

int main(){

	/*Parrot pet("Mike", "Black", "Eagle", 3, 5, 1);
	pet.setOwner("Kirill");*/

	Hamster pet("Mike", "Black", "Eagle", 3, 5);
	pet.setOwner("Kirill");

	pet.Name();
	pet.Color();
	pet.Type();
	pet.Age();
	pet.Weight();
	//pet.Fly();
	pet.Sound();
	pet.OwnerName();





	return 0;
}
