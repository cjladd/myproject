#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


#include "HashTable.h"


class WordChecker
{
public:

    // convert a string to all upper or lower case
    static void str_toupper(std::string &str);

    /// \brief in-place convert string to lower case
    /// \return ref to transformed string
    static void str_tolower(std::string &str);

    //load dictionary from an external file
    void load( std::string fileName );

    //find if a word is in dictionary or not
    bool find( std::string ) const;

    //find near misses
    void findNearMiss( std::string word, std::vector<std::string>& nearMisses ) const;

private:
    // one additional letter
    void findByAddLetter( std::string word, std::vector<std::string>& nearMisses ) const;

    // one miss letter
    void findByMissLetter( std::string word, std::vector<std::string>& nearMisses ) const;

    // swap adjacent letters
    void findBySwap( std::string word, std::vector<std::string>& nearMisses ) const;

    // Replace individual letter
    void findByReplace( std::string word, std::vector<std::string>& nearMisses ) const;

    // Find pair
    void findByPair( std::string word, std::vector<std::string>& nearMisses ) const;

private:
    HashTable<std::string, std::string>     m_table;
	//or
	//unordered_map<std::string, std::string> m_table;

};
