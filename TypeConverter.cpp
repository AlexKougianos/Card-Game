#include "TypeConverter.hpp"

// returns an int according to the TYPE enum in the .hpp
int getCorrectType(int type) {
	if(type >= 1 && type <= 5)
		return 1;
	if(type >= 6 && type <= 12)
		return 2;
	if(type >= 13 && type <= 17)
		return 3;
	if(type >= 18 && type <= 22)
		return 4;
}
