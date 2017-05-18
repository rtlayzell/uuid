#include "bits/uuid.hpp"
#include "bits/random_uuid_generator.hpp"
#include <chrono>

namespace uuids {
	template <typename _UniformRandomNumberGenerator = ::std::default_random_engine>
	uuid random_uuid() {
		static random_uuid_generator<_UniformRandomNumberGenerator> gen(
			static_cast<typename _UniformRandomNumberGenerator::result_type>(
				::std::chrono::system_clock::now().time_since_epoch().count()));

		return gen();
	}

	uuid sequential_uuid() {
		//static const std::uint32_t mask = 0x00ffffff;
		return random_uuid(); /// TODO: implement COMB uuid.
	}

	uuid system_uuid() {
		return random_uuid();
	}
}
