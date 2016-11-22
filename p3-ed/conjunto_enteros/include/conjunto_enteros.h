
#ifndef __CONJUNTO_ENTEROS_H
#define __CONJUNTO_ENTEROS_H

#include <vector>
#include <iostream>

class ConjuntoEnteros {

private:
	std::vector<int> data_;

public:
	struct RangoEnteros {
		int lower;
		int upper;

		friend std::ostream& operator<<(std::ostream& os, RangoEnteros const& r) {
			return os << "range{lower=" << r.lower << ", upper=" << r.upper << "};";
		}
	};


	ConjuntoEnteros() {};

	std::vector<int> const& data() const { return data_; }

    std::vector<int>& data() { return data_; }

	void add(int i) { data_.push_back(i); };

	unsigned long size() const { return data_.size(); }

	bool contains(ConjuntoEnteros const& o);

	RangoEnteros const range() const;

	friend bool operator<(ConjuntoEnteros const& lhs, ConjuntoEnteros const& rhs);

	friend bool operator>(ConjuntoEnteros const& lhs, ConjuntoEnteros const& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(ConjuntoEnteros const& lhs, ConjuntoEnteros const& rhs) {
		return !(lhs < rhs);
	}

	friend bool operator<=(ConjuntoEnteros const& lhs, ConjuntoEnteros const& rhs) {
		return !(rhs < lhs);
	}

	friend std::ostream& operator<<(std::ostream& os, ConjuntoEnteros const& v);

	friend std::istream& operator>>(std::istream& is, ConjuntoEnteros& v);
};

#endif
