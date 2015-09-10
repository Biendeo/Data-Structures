#pragma once

/**
	\class HugeInt
	\brief A set of functions that make big integers easy to use.
	\author Thomas Moffet (Biendeo)
	\date 10/09/2015 - 10/09/2015

	LONG DESCRIPTION LONG DESCRIPTION
	Ideally this should work on all compilers for all systems.

	Priority: Low.
*/

#ifdef __cplusplus

#include <iostream>
#include <cstdlib>
#include <stdexcept>

namespace Biendeo {

	class HugeInt {
		public:
		enum class DisplayType {
			Int,
			CommaInt,
			ScientificE,
			Scientific10
		};

		HugeInt();
		HugeInt(int n);
		HugeInt(long long n);
		void operator= (HugeInt num);
		void operator= (int num);
		void operator= (long long num);
		friend HugeInt operator+ (HugeInt &num1, HugeInt &num2);
		friend HugeInt operator- (HugeInt &num1, HugeInt &num2);
		friend HugeInt operator* (HugeInt &num1, HugeInt &num2);
		friend HugeInt operator/ (HugeInt &num1, HugeInt &num2);
		friend HugeInt operator% (HugeInt &num1, HugeInt &num2);
		friend std::ostream& operator<< (std::ostream &out, HugeInt &num);

		DisplayType getDisplayType();
		void setDisplayType(DisplayType type);

		private:
		/// The value of the number (maximum to 1,000,000,000,000,000) / 10^15.
		long long value;

		/// The exponent of the number.
		int exponent;

		/// The display type of the number.
		DisplayType display;

	};


	HugeInt::HugeInt() {
		value = 0;
		exponent = 0;
		display = DisplayType::Int;
	}

	HugeInt::HugeInt(int n) {
		*this = n;
		display = DisplayType::Int;
	}

	HugeInt::HugeInt(long long n) {
		*this = n;
		display = DisplayType::Int;
	}

	void HugeInt::operator= (HugeInt num) {
		value = num.value;
		exponent = num.exponent;
	}

	void HugeInt::operator= (int n) {
		exponent = (int)log10(n);
		for (int i = 15; i > exponent; i--) {
			n *= 10;
		}
		value = n;
	}

	void HugeInt::operator= (long long n) {
		exponent = (int)log10(n);
		for (int i = 15; i > exponent; i--) {
			n *= 10;
		}
		value = n;
	}

	std::ostream& operator<< (std::ostream &out, HugeInt &num) {
		switch (num.getDisplayType()) {
			case HugeInt::DisplayType::Int:
			default:
				break;
		}
		return out;
	}

	HugeInt::DisplayType HugeInt::getDisplayType() {
		return display;
	}

	void HugeInt::setDisplayType(HugeInt::DisplayType type) {
		display = type;
	}

}

#endif