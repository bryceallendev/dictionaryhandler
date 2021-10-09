/*
    DictionaryHandler.cpp

    Definitions for dictionary creation
*/

#include "DictionaryHandler.hpp"

// output words to out stream
void DictionaryHandler::outputWords(std::ostream& out) const {

    // output the dictionary with each "word" on a single line
    std::copy(words.begin(), words.end(),
              std::ostream_iterator<std::string>(out, "\n"));
}
