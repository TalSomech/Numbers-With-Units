//
// Created by tal on 07/04/2021.
//
#include <iostream>
#include "NumberWithUnits.hpp"
#include <string>
#include <algorithm>
//#define  epsilon  0.0001;
using namespace std;
using namespace ariel;

const double epsilon=0.0001;
void NumberWithUnits::read_units(ifstream &file) {
    string type1;
    string type2;
    double num1=0, num2=0;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            replace(line.begin(), line.end(), '=', ' ');
            std::istringstream stream(line);
            stream >> num1 >> type1 >> num2 >> type2;
            insert(type1, type2, num2);
            insert(type2, type1, 1 / num2);
            _types[type1][type2] = num2;
            _types[type2][type1] = 1 / num2;
            _types[type1][type1] = 1;
            _types[type2][type2] = 1;
            // insert(type2, type1, 1 / num2);
//            _types[type1][type2]=num2;
//            _types[type2][type1]=num2;
        }
    }
}

void NumberWithUnits::insert(const std::string &type1, const std::string &type2, const double num) {
//static void NumberWithUnits::insert(string type1, string &type2, double num) {
    double temp=0;
    for (const auto &keyval:_types[type1]) {
        if (_types[type2][keyval.first] == 0) {
            temp = 1 / keyval.second;
            _types[keyval.first][type2] = num * temp;
            _types[type2][keyval.first] = (1 / (num * temp));
        }
    }

}


NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &other) {


    return NumberWithUnits(_num - (other._num * NumberWithUnits::conversion(_unit, other._unit)), _unit);
}

NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &n2) {
    NumberWithUnits a = NumberWithUnits(this->_num + (n2._num * NumberWithUnits::conversion(this->_unit, n2._unit)),
                                        this->_unit);
    return a;
}

bool NumberWithUnits::operator<(NumberWithUnits const &other) const {

    return _num <= other._num * NumberWithUnits::conversion(_unit, other._unit)-epsilon;
}

bool NumberWithUnits::operator<=(const NumberWithUnits &other) const {

    return (!(*this > other));
}

bool NumberWithUnits::operator>(const NumberWithUnits &other) const {

    return _num >= other._num * conversion(_unit, other._unit)+epsilon;
}

bool NumberWithUnits::operator>=(const NumberWithUnits &other) const {

    return (!(*this < other));
}

bool NumberWithUnits::operator==(const NumberWithUnits &other) const {
    if (other._unit == _unit) {
        return abs(_num - other._num) < epsilon;
    }
    if (!(check_units((*this), other))) {
        throw invalid_argument("Wrong conversion");
    }

    return abs(_num - other._num * conversion(_unit, other._unit)) < epsilon;
}

bool NumberWithUnits::operator!=(const NumberWithUnits &other) const {
    if (!check_units(*this, other)) {
        throw invalid_argument("Wrong conversion");
    }
        //return true;
    return (!(*this == other));
}



std::ostream &ariel::operator<<(ostream &os, const NumberWithUnits &c) {
    return (os << c._num << '[' << c._unit << ']');
}

std::istream &ariel::operator>>(std::istream &is, NumberWithUnits &c) {
    double num = 0;
    string inp_t;
    char suff = ']';
    is >> num;
    is >> suff;
    while (suff != ']') {
        if (suff != '[') {
            inp_t.push_back(suff);
        }
        is>>suff;
    }
    if (NumberWithUnits::_types.find(inp_t) != NumberWithUnits::_types.end()) {
        c._num = num;
        c._unit = inp_t;
    }
    else {
        throw std::invalid_argument{"no such unit in stock"};

    }
    return is;
}













