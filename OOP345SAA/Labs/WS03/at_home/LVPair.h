#ifndef _SICT_LVPAIR_H
#define _SICT_LVPAIR_H

#include <iostream>

namespace sict
{
	/*
	
	defines a class template for a label-value pair (for example, a product label stored in an std::string object and a quantity stored in an int object)
	
	*/
	template <typename L, typename V>
	class LVPair
	{
		L m_label;
		V m_value;
	public:
		// leaves the object in a safe empty state
		LVPair()
			: m_label{}
			, m_value{}
		{
		}

		// an overloaded constructor that copies the values received 
		// in its parameters into the instance variables
		LVPair(const L& label, const V& value)
			: m_label(label)
			, m_value(value)
		{
		}

		// a query that inserts into os the label and value 
		// stored in the current object separated by 
		// a space - colon - space string(� : �) 
		void display(std::ostream& os) const
		{
			os << m_label << " : " << m_value << std::endl;
		}

	};

	// a non - friend helper function that inserts into the 
	// os object the LVPair object referenced in the 2nd function parameter
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

	// manage the addition and pretty displaying of individual labeled values
	template <typename L, typename V>
	class SummableLVPair : LVPair
	{
		V m_initialValueForSummation;
		size_t m_minFieldWidth = 0;
	public:

		// leaves the object in a safe empty state
		SummableLVPair()
		{
		}

		// calls the base class 2-argument constructor, passes the values received 
		// to the base class and increases the stored field width if it is less than 
		// the return of characters required to display the label for all LVPair objects
		// This class assumes that the type of the first parameter has a member function named size(), which returns that value
		SummableLVPair(const L& label, const V& v)
		{
		}

		// returns the initial value for summations of LVPair objects
		const V& getInitialValue()
		{
		}

		V append(const L& label, const V& value) const
		{
		}

		// receives two unmodifiable references - one to a label (label) and another to a partially 
		// accumulated sum (sum) � and returns the sum of the value of the current object 
		// and the partially accumulated sum in a V object
		V sum(const L& label, const V& sum) const
		{
		}

		// a query that inserts into the std::ostream object the label and value stored in the base class
		// Before calling the display() function on the base class, this query sets the std::ostream object to left - 
		// justified insertion and a field width equal to that stored for objects of this class
		void display(std::ostream& os) const
		{
		}
	};

}


#endif // !_SICT_LVPAIR_H
