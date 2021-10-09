/*
    WordProcessor.cpp

    Definitions for word reading functions
*/

#include "WordProcessor.hpp"
#include <ctype.h>
#include <vector>
#include <locale>
#include <memory>

// constructor with input stream and processWord function
WordProcessor::WordProcessor(std::istream& in, WordProcessorHandler& handler)
    : input(in), handler(handler)
{}

// read all the words from a file and apply process() to them
void WordProcessor::read() {

    // word separator for :,(,),.,;,",&,<,>,_,[,],,
    const auto temp = std::ctype<char>::classic_table();
    std::vector<std::ctype<char>::mask> mask(temp, temp + std::ctype<char>::table_size);
    mask[':'] |= std::ctype_base::space;
    mask['('] |= std::ctype_base::space;
    mask[')'] |= std::ctype_base::space;
    mask['.'] |= std::ctype_base::space;
    mask[';'] |= std::ctype_base::space;
    mask['"'] |= std::ctype_base::space;
    mask['&'] |= std::ctype_base::space;
    mask['<'] |= std::ctype_base::space;
    mask['>'] |= std::ctype_base::space;
    mask['_'] |= std::ctype_base::space;
    mask['['] |= std::ctype_base::space;
    mask[']'] |= std::ctype_base::space;
    mask[','] |= std::ctype_base::space;

    // add new mask to locale
    // note use of new without delete (standard technique for this)
    input.imbue(std::locale(input.getloc(), new std::ctype<char>(std::data(mask))));

    // read and process all words in the file
    std::string word;
    int position = 0;
    while (input >> word) {

        // words must begin with an alphabetic character
        if (!isalpha(word[0]))
            continue;
    }
}
