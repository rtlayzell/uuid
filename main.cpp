#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <uuid.hpp>

int main(int, char**) {
	using namespace ::uuids;
	
	std::vector<uuid> v { 20 };
	
	std::generate(v.begin(), v.end(), random_uuid);
	
	std::copy(v.begin(), v.end(), 
		std::ostream_iterator<uuid>(std::cout, "\n"));
	
	return 0;
}