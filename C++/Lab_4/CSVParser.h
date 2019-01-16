//
// Created by Bayramov Nidjat on 15.01.19.
//

#ifndef LAB_4_CSVPARSER_H
#define LAB_4_CSVPARSER_H

#include <tuple>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

#include "TuplePrinter.h"


template <typename ...Args>
class CSVParser {
    private:
        std::istream& _input_stream;
        size_t _lines_to_skip;


    public:
        explicit CSVParser(std::istream& input_stream, size_t lines_to_skip = 0) :
                _input_stream(input_stream),
                _lines_to_skip(lines_to_skip) {}

        class iterator : public std::iterator<std::input_iterator_tag,
                                std::tuple<Args...>,
                                long,
                                const std::tuple<Args...>*,
                                std::tuple<Args...>> {
            private:
                CSVParser *_parser = nullptr;
                bool _isEnd = false;
                std::size_t _lineNumber = 0;

                std::tuple<Args...> _record;

                //Private functions
                void _getRecord() {
                    std::string line;
                    if (!_isEnd) {
                        std::getline(_parser->_input_stream, line);

                        _isEnd = _parser->_input_stream.eof();

                        _record = _parser->getRecord(line);
                    }
                }
            public:
                explicit iterator() : _isEnd(true){}

                explicit iterator(CSVParser &parser) : _parser(&parser) {
                    auto &input_stream = _parser->_input_stream;
                    for (; !_isEnd && _lineNumber < _parser->_lines_to_skip; _lineNumber++) {
                        input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        _isEnd = input_stream.eof();
                    }
                    _getRecord();
                }

                iterator& operator++() {
                    if (!_isEnd) {
                        _lineNumber++;
                        _getRecord();
                    }
                    return *this;
                }

                const iterator operator++(int) {
                    iterator retVal = *this;
                    ++(*this);
                    return retVal;
                }

                bool operator==(const iterator &other) {
                    return (_isEnd && other._isEnd) || (!_isEnd && !other._isEnd && (_lineNumber == other._lineNumber));
                }

                bool operator!=(const iterator &other) {
                    return !(*this == other);
                }

                std::tuple<Args...> &operator*() {
                    return _record;
                }
        };

        iterator begin() {
            return iterator(*this);
        }
        iterator end() {
            return iterator();
        }

        std::vector<std::string> getTokens(const std::string &line) {
            std::string token;
            std::vector<std::string> tokens;

            std::stringstream tmp_stream(line);

            while (getline(tmp_stream, token, ';')) {
                tokens.push_back(token);
            }

            return tokens;
        }

        template<typename T, typename std::enable_if<!std::is_same<T, std::string>::value>::type* = nullptr>
        static T _get_value(const std::string &token, std::size_t tokenNo) {
            static std::istringstream convertStream;

            T val;
            convertStream.clear();
            convertStream.str(token);
            convertStream >> val;

            return val;
        }

        template<typename T, typename std::enable_if<std::is_same<T, std::string>::value>::type* = nullptr>
        static const T& _get_value(const std::string &token, std::size_t) {
            return token;
        }

        std::tuple<Args...> getRecord(const std::string &line) {
            std::string value;

            if (_input_stream.eof()) {
                return std::tuple<Args...>();
            }

            auto tokens = getTokens(line);
            auto tokensIterator = tokens.begin();

            std::size_t k = 0;
            return std::tuple<Args...>(_get_value<Args>(*tokensIterator++, k++)...);
        }

};
#endif //LAB_4_CSVPARSER_H
