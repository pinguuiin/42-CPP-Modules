#include <iostream>
#include "Serializer.hpp"

int	main(void)
{
	Data original;
	Data *restored;
	uintptr_t raw;

	original.id = 42;
	original.zone = 'A';

	raw = Serializer::serialize(&original);
	restored = Serializer::deserialize(raw);

	// Compare original, serialized and deserialized values
	std::cout << "original id: " << original.id << std::endl;
	std::cout << "original zone: " << original.zone << std::endl;

	std::cout << "original pointer: " << &original << std::endl;
	std::cout << "converted unsigned integer: " << raw << std::endl;
	std::cout << "restored pointer: " << restored << std::endl;

	std::cout << "restored id: " << restored->id << std::endl;
	std::cout << "restored zone: " << restored->zone << std::endl;

	// Check if the return value is equal to the original pointer
	if (restored == &original)
		std::cout << "OK: pointers compare equal" << std::endl;
	else
		std::cout << "KO: pointers differ" << std::endl;

	return 0;
}
