#include <iostream>

#include "conjunto_enteros.h"

/**
 *	Sin RangoEnteros
 */
// bool operator<(ConjuntoEnteros const& lhs, ConjuntoEnteros const& rhs) {
// 	std::vector<int> lhs_data = lhs.data(), rhs_data = rhs.data();

// 	if((lhs_data.size() == 0) || (rhs_data.size() == 0)) {
// 		return (lhs_data.size() < rhs_data.size());
// 	}

// 	// Preamble
// 	typename std::vector<int>::iterator it;
// 	int lhs_smallest, rhs_smallest;

// 	// First block
// 	it = lhs_data.begin(); 
// 	lhs_smallest = (*it);

// 	while(it != lhs_data.end()) {
// 		++it;

// 		lhs_smallest = (lhs_smallest < (*it)) ? lhs_smallest : *(it); 
// 	}

// 	// Second block
// 	it = rhs_data.begin();
// 	rhs_smallest = (*it);

// 	while(it != rhs_data.end()) {
// 		++it;

// 		rhs_smallest = (rhs_smallest < (*it)) ? rhs_smallest : *(it); 
// 	}

// 	return (lhs_smallest < rhs_smallest);
// }


ConjuntoEnteros::RangoEnteros const ConjuntoEnteros::range() const {
	if(size() == 0) {
		// error
	}

	typename std::vector<int>::const_iterator it = data().begin();
	ConjuntoEnteros::RangoEnteros r;

	r.lower = (*it);
	r.upper = (*it);

	++it;
	while(it != data().end()) {
		int x = (*it); ++it;

		r.lower = (r.lower < x) ? r.lower : x;
		r.upper = (r.upper > x) ? r.upper : x; 
	}

	return r;
}

bool operator<(ConjuntoEnteros const& lhs, ConjuntoEnteros const& rhs) {
	return ((lhs.range().lower) < (rhs.range().upper));
}

bool ConjuntoEnteros::contains(ConjuntoEnteros const& o) {
	ConjuntoEnteros::RangoEnteros rt = range(), ro = o.range();

	return ((rt.lower < ro.lower) && (rt.upper > ro.upper));
}

std::ostream& operator<<(std::ostream& os, ConjuntoEnteros const& v) {
	for(typename std::vector<int>::const_iterator it = v.data().begin(); it != v.data().end(); ++it) {
		os << (*it) << std::endl;
	}

	return os;
}

std::istream& operator>>(std::istream& is, ConjuntoEnteros& v) {
	while(is) {
		int i; is >> i;

		v.add(i);
	}

	return is;
}