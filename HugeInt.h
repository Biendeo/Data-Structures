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
#include <cmath>
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
		HugeInt(int m);
		HugeInt(long long n);
		void operator= (HugeInt num);
		void operator= (int m);
		void operator= (long long n);
		friend HugeInt operator+ (HugeInt &num1, HugeInt &num2);
		friend HugeInt operator- (HugeInt &num1, HugeInt &num2);
		friend HugeInt operator* (HugeInt &num1, HugeInt &num2);
		friend HugeInt operator/ (HugeInt &num1, HugeInt &num2);
		friend HugeInt operator% (HugeInt &num1, HugeInt &num2);
		friend std::ostream& operator<< (std::ostream &out, HugeInt &num);

		long long getValue();
		int getExponent();
		DisplayType getDisplayType();
		bool isPositive();
		void setDisplayType(DisplayType type);

		protected:
		/// The value of the number (maximum to 1,000,000,000,000,000) / 10^15.
		long long value;

		/// The sign of the number (0 is positive).
		enum class sign {
			positive,
			negative
		} sign;

		/// The exponent of the number.
		int exponent;

		/// The display type of the number.
		DisplayType display;
	};


	HugeInt::HugeInt() {
		value = 0;
		sign = sign::positive;
		exponent = 0;
		display = DisplayType::Int;
	}

	HugeInt::HugeInt(int m) {
		*this = m;
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

	void HugeInt::operator= (int m) {
		long long n = m;
		if (n == 0) {
			sign = sign::positive;
			exponent = 0;
		} else {
			if (n < 0) {
				sign = sign::negative;
				n *= -1;
			}
			exponent = (int)log10(n);
			for (int i = 15; i > exponent; i--) {
				n *= 10;
			}
		}
		value = n;
	}

	void HugeInt::operator= (long long n) {
		if (n == 0) {
			sign = sign::positive;
			exponent = 0;
		} else {
			if (n < 0) {
				sign = sign::negative;
				n *= -1;
			}
			exponent = (int)log10(n);
			for (int i = 15; i > exponent; i--) {
				n *= 10;
			}
		}
		value = n;
	}

	/// Adds two arrays together.
	HugeInt operator+ (HugeInt &num1, HugeInt &num2) {
		HugeInt addedNum;
		HugeInt largerNum;
		HugeInt smallerNum;

		if (num1.getValue() == 0) {
			return num2;
		} else if (num2.getValue() == 0) {
			return num1;
		} else {
			if (num1.getExponent() <= num2.getExponent()) {
				largerNum = num2;
				smallerNum = num1;
			} else {
				largerNum = num1;
				smallerNum = num2;
			}
			
			addedNum.exponent = largerNum.getExponent();

			for (int i = 0; i < largerNum.getExponent() - smallerNum.getExponent(); i++) {
				smallerNum.value /= 10;
			}
			addedNum.value = largerNum.getValue() + smallerNum.getValue();
			if (addedNum.value >= (long long)pow(10, 15)) {
				addedNum.value /= 10;
				addedNum.exponent++;
			}
		}

		return addedNum;
	}

	std::ostream& operator<< (std::ostream &out, HugeInt &num) {
		long long value = num.getValue();
		int exponent = num.getExponent();
		long long tenPower = pow(10, 15);
		long long reverseTenPower = 10;

		if (num.isPositive() == false) {
			out << "-";
		}
		
		if (num.getValue() == 0) {
			out << "0";
			return out;
		}

		switch (num.getDisplayType()) {
			case HugeInt::DisplayType::Int:
			default:
				if (exponent > 15) {
					for (int i = exponent; i >= 0; i--) {
						if (exponent - i <= 15) {
							out << ((value / tenPower) % 10);
						} else {
							out << "0";
						}

						tenPower /= 10;
					}
				} else {
					for (int i = exponent; i > exponent - 15; i--) {
						if (i < 0) {
							if ((value / (long long)(pow(10, 15 - i))) == 0) {
								break;
							}
						}
						if (i == -1) {
							out << ".";
						}
						out << ((value / tenPower) % 10);
						long long outNum = ((value / tenPower) % 10);
						if (i <= 0) {
							if ((value / tenPower) == 0) {
								break;
							}
						}

						tenPower /= 10;
						reverseTenPower *= 10;
					}
				}
				break;
		}
		return out;
	}

	long long HugeInt::getValue() {
		return value;
	}

	int HugeInt::getExponent() {
		return exponent;
	}

	HugeInt::DisplayType HugeInt::getDisplayType() {
		return display;
	}

	bool HugeInt::isPositive() {
		switch (sign) {
			case sign::positive:
			default:
				return true;
			case sign::negative:
				return false;
		}
	}

	void HugeInt::setDisplayType(HugeInt::DisplayType type) {
		display = type;
	}

}

#endif