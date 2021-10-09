/*
    DictionaryHandler.hpp

    Declarations for dictionary creation
*/

#ifndef INCLUDED_DICTIONARYHANDLER_HPP
#define INCLUDED_DICTIONARYHANDLER_HPP

#include "WordProcessorHandler.hpp"
#include <istream>
#include <ostream>
#include <string>
#include <iterator>
#include <set>

class DictionaryHandler : public WordProcessorHandler {
public:

    // output words to out stream
    void outputWords(std::ostream& out) const;

private:
    std::set<std::string> words;
};

#endif
