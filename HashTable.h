#ifndef _HASH_H_
#define _HASH_H_

#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

class TableException: public std::logic_error
{
public:
	TableException(const std::string& msg="")
		: std::logic_error(msg.c_str())
	{}
};

// Hash Table with seperate chaining
template <  typename KeyType, // type of items in hash table
            typename ItemType  // type of search keys
         >
class HashTable
{
public:
	// default constructor:
    // create an empty hash table with capacity 1000
	HashTable();

    // copy constructor
    // perform a deep copy
	HashTable(const HashTable<KeyType, ItemType>& table );

    // destructor
    // Deallocated all dynamically allocated memory space 
	~HashTable();

    //have to overload assignment operator
    HashTable& operator = (const HashTable& rhs) const;

	//hash table operations

    // Check if the hash table is empty or not
    // return true if it is empty
	bool isEmpty( void ) const;

    // Return the number of items in the hash table
	long  getSize( void ) const;

    // Return the current capacity of the hash table
    long  getCapacity(void) const;

    // Return the load factor of the hash table
    // load_factor = getSize() / getCapacity
    double  getLoadFactor(void) const;


    // Insert a new item into hash table.
    // After insertion, if the load factor is greater
    // than 2.0/3.0, double the capacity and perform rehashing
	void insert(const KeyType newKey, const ItemType& newItem);

    // Remove an item with a specific search key from the hash table
    // If no such item exists, do nothing
    // After removement, if the load factor is less than 1/4,
    // decrease the capacipty of the hash table by half, and perform rehash
	void remove( const KeyType searchKey );

    // Return the value of an item with a specific search key
    // If the key doesn't exist in the hash table, insert it
    // to to the hash table, and its value will be created using the default 
    // constructor
    ItemType& operator [](KeyType searchKey) const;
 
    // Check if a given key exits in the hash table. 
    // return true if exists, otherwise false.
    bool exist(KeyType searchKey) const;

    // This function is used to print the whole hash table. For debug only
    // void print ( std::ostream& ) const;


    //Hash function
    long hash(const KeyType key) const
    {
        return std::hash<KeyType>{}(key) % m_capacity;
    }

private:

    struct ListNode
    {
        KeyType     key;
        ItemType    item;
        ListNode(KeyType k, ItemType i)
            : key(k), item(i)
        {}
    };

    // hash table is defined as a dynamic array  of ListNode pointers
    vector<ListNode>*   m_table; 
    
	long				m_size; // number of items in the table
    long                m_capacity; //capacity of the hash table
};

/* impelment of all methods come here */

template<typename KeyType, typename ItemType>
HashTable<KeyType, ItemType>::HashTable()
    : m_size(0), m_capacity(1000) {
    m_table = new vector<ListNode>[m_capacity];
}

// Check if the hash table is empty or not
// return true if it is empty
template<typename KeyType, typename ItemType>
bool HashTable<KeyType, ItemType>::isEmpty(void) const {
    return m_size == 0;
}

// Return the number of items in the hash table
template<typename KeyType, typename ItemType>
long  HashTable<KeyType, ItemType>::getSize(void) const {
    return m_size;
}

// Return the current capacity of the hash table
template<typename KeyType, typename ItemType>
long  HashTable<KeyType, ItemType>::getCapacity(void) const {
    return m_capacity;
}

template<typename KeyType, typename ItemType>
double  HashTable<KeyType, ItemType>::getLoadFactor(void) const {
    return m_size*1.0 / m_capacity;
}



/*
	Put your implementaiton of the following methods here:
		
	copy constructor
	destructor
	assignment operator
	insert
	remove
	[]
	exist

*/

#endif



