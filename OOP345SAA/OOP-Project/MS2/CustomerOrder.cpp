#include <vector>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sict {
	/**
	 * Default Constructor that sets the object to a safe empty state
	*/
	CustomerOrder::CustomerOrder() : m_itemInfo{ nullptr }, m_customerName{ "" }, m_productName{ "" }, numItems{0} {}
	/**
	 * One argument constructor that receives a string that contains at least 3 tokens:
	 * - Customer's name
	 * - Name of the product being assembled
	 * - 3..n are names of the items to be added to the Product throughout the assembly process
	 * If no items are requested to be added (no products are present within the string), throw an exception that says so
	 * If items are present, allocate memory for each one
	*/
	CustomerOrder::CustomerOrder(const std::string& record) {
		size_t next_pos = record.find(m_utility.getDelimiter());
		m_customerName = record.substr(0, next_pos);
		m_productName = m_utility.extractToken(record, next_pos);

		size_t delimiter_count = std::count(record.begin(), record.end(), m_utility.getDelimiter());
		numItems = delimiter_count - 1;
		m_itemInfo = new ItemInfo[numItems];

		if (delimiter_count >= 2) {
			for (size_t i = 0; i < numItems; ++i) {
				m_itemInfo[i].s_name = m_utility.extractToken(record, next_pos);
			}
		}
		else
			throw std::string("***No items are found***");
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& other) {
		*this = std::move(other);
	}

	CustomerOrder & CustomerOrder::operator=(CustomerOrder&& other) {
		if (this != &other) {
			m_utility = other.m_utility;
			m_itemInfo = other.m_itemInfo;
			m_customerName = other.m_customerName;
			m_productName = other.m_productName;

			other.m_utility = Utilities::Utilities();
			other.m_itemInfo = { nullptr };
			other.m_customerName = { "" };
			other.m_productName = { "" };
		}
		return *this;
	}

	/**
	 * Destructor that deallocates memory
	*/
	CustomerOrder::~CustomerOrder() {
		delete[] m_itemInfo;
		m_itemInfo = { nullptr };
	}

	/**
	 * Modifier that checks each item request, fills it if the item is available and the request has not been filled and reports the filling in the following format:
	 * Filled CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] OR
	 * Unable to fill CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] already filled
	 * Unable to fill CUSTOMER [PRODUCT][ITEM][SERIAL NUMBER] out of stock 
	 * Also decrements the item stock by one
	*/
	void CustomerOrder::fillItem(ItemSet&, std::ostream&)	{
	}

	/**
	 * Searches the list of items requested and returns true if all have ben filled
	*/
	bool CustomerOrder::isFilled() const {
		return false;
	}

	/**
	 * Receives an item name
	 * search the list for that ItemName, return true if all requests for the item has been filled or if the item is not in the lists
	*/
	bool CustomerOrder::isItemFilled(const std::string &) const {
		return false;
	}

	/**
	 * Returns the name of the customer and their product in the following format:
	 * CUSTOMER [PRODUCT]
	*/
	std::string CustomerOrder::getNameProduct() const {
		return std::string(m_customerName) + "[" + std::string(m_productName) + "]";
	}

	/**
	 * Inserts the data for the current object into the ostream
	 * Has a default showDetail as false
	 * Displays in the following format:
	 * Name       [Product]
	 *            Part 1
	 *            Part 2
	 *            Part 3
	 *            Part 4
	*/
	void CustomerOrder::display(std::ostream & os, bool showDetail) const {
		if (!showDetail) {
			os << getNameProduct() << std::endl;
			for (size_t i = 0; i < numItems - 1; i++)
				os << m_itemInfo[i].s_name << std::endl;
		}
	}
}
