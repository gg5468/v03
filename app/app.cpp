#include "app.h"
#include <algorithm>
#include <string>

namespace vsite::oop::v3
{

	results::results(unsigned int c) {
		students = new student[c];
		cap = c;
	};
	void results::add(student s) {
		if (size < cap) {
			students[size] = s;
			size++;
		}
	};
	unsigned int results::has_grade(unsigned int g) {
		unsigned int result = 0;
		for (unsigned int i = 0; i < size; i++) {
			if (students[i].grade == g) {
				result++;
			}
		}
		return result;
	};
	unsigned int results::starts_with_letter(char l) {
		unsigned int result = 0;
		for (unsigned int i = 0; i < size; i++) {
			if (tolower(students[i].name[0]) == tolower(l)) {
				result++;
			}
		}
		return result;
	};





	array::array(unsigned int size, double value) : cap(size) {
		arr = new double[cap];
		for (unsigned int i = 0; i < cap; i++) {
			arr[i] = value;
		}
	}

	unsigned int array::size() {
		return cap;
	}

	double array::at(unsigned int i) {
		if (i >= 0 && i < cap) {
			return arr[i];
		}
		return 0;
	}

	void array::push_back(double v) {
		unsigned int new_cap = cap + 1;
		double* new_arr = new double[new_cap];
		for (unsigned int j = 0; j < cap; j++) {
			new_arr[j] = arr[j];
		}
		new_arr[cap] = v;
		arr = new_arr;
		cap = new_cap;
	}

	array::array(array&& other) : arr(other.arr), cap(other.cap) {
		other.arr = nullptr;
		other.cap = 0;
	}


	array::array(const array& other) : cap(other.cap) {
		arr = new double[cap];
		for (unsigned int i = 0; i < cap; i++) {
			arr[i] = other.arr[i];
		}
	}
};