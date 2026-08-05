#pragma once

#include <cstdint>  // uintptr_t
#include "Data.hpp"

class Serializer {

	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

	private:
		// Not initializable
		Serializer() = delete;
		Serializer(const Serializer &o) = delete;
		Serializer &operator=(const Serializer &o) = delete;
		~Serializer() = delete;
};
