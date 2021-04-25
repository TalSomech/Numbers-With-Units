//
// Created by tal on 07/04/2021.
//

#pragma once

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace ariel {
    class NumberWithUnits {
    private:
        double _num;
        std::string _unit;
        inline static std::unordered_map<std::string, std::unordered_map<std::string, double>> _types;


    public:
        NumberWithUnits(){};
        NumberWithUnits(double num, const std::string& unit) {

            if (_types.find(unit) == _types.end())
                throw std::out_of_range("Wrong unit");
            else {
                _num = num;
                _unit = unit;
            }
        };


        static void read_units(std::ifstream &file);

        static void insert(const std::string &type1, const std::string &type2, double num);

        static bool check_units(const NumberWithUnits &n1, const NumberWithUnits &n2) {
            if (_types.find(n1._unit)->second.find(n2._unit) == _types.find(n1._unit)->second.end()) {
                return false;
            }
            return true;

        }
//
//        static std::vector<std::string> get_types() {
//            return _typs;
//        }
//
//        static std::unordered_map<std::string, double> get_type_group(std::string type) {
//            return _types.at(type);
//        }

        static double conversion(const std::string &to, const std::string &from) {
            if (_types.find(from)->second.find(to) == _types.find(from)->second.end()) {
                std::stringstream errMsg;
                errMsg << "Units do not match - ["<<from<<"] cannot be converted to ["<<to<<"]";
                throw std::out_of_range(errMsg.str());
            }
            return _types.find(from)->second.find(to)->second;
            //return _types[from][to];
        };


        NumberWithUnits operator+(NumberWithUnits const &n2);

        NumberWithUnits &operator+=(NumberWithUnits const &other) {

            _num += other._num * conversion(_unit, other._unit);
            return *this;
        };

        NumberWithUnits operator+() {
            return NumberWithUnits(_num, _unit);
        };

        NumberWithUnits operator-(NumberWithUnits const &other);

        NumberWithUnits &operator-=(const NumberWithUnits &other) {

            _num -= other._num * conversion(_unit, other._unit);
            return *this;

        };

        NumberWithUnits operator-() {
            return NumberWithUnits(_num*(-1), _unit);
        };

        bool operator<(NumberWithUnits const &other) const;

        bool operator<=(const NumberWithUnits &other) const;

        bool operator>(const NumberWithUnits &other) const;

        bool operator>=(const NumberWithUnits &other) const;

        bool operator==(const NumberWithUnits &other) const;

        bool operator!=(const NumberWithUnits &other) const;

        NumberWithUnits &operator++() {
            _num++;
            return *this;
        }

        const NumberWithUnits operator++(int) {
            _num++;
            return NumberWithUnits(_num - 1, _unit);
        }

        NumberWithUnits &operator--() {
            _num--;
            return *this;
        };

        const NumberWithUnits operator--(int) {
            _num--;
            return NumberWithUnits(_num + 1, _unit);
        }

        friend NumberWithUnits operator*(const NumberWithUnits &cur,const double num) {
            return NumberWithUnits(cur._num * num, cur._unit);
        };

        friend NumberWithUnits operator*(const double num, const NumberWithUnits &cur) {
            return NumberWithUnits(cur._num * num, cur._unit);
        };

        friend std::ostream &operator<<(std::ostream &os, const NumberWithUnits &c);

        friend std::istream& operator>>(std::istream &is, NumberWithUnits &c);


    };
}
