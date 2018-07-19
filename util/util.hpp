#include <sstream>
#include <sstream>

namespace util
{

static inline std::string to_string(double v, int precision = 3)
{
	std::stringstream ss;
	ss.precision(precise);
	ss << std::fixed << v;
	std::string out;
	ss >> out;

	return out;
}



}

