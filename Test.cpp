//
// Created by tal on 08/04/2021.
//

#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
using namespace ariel;
TEST_CASE ("+ binary") {
    ifstream units_file{"./units.txt"};
    NumberWithUnits::read_units(units_file);
//    for (string type1:NumberWithUnits::get_types()) {
//        CHECK(NumberWithUnits(5, type1) + NumberWithUnits(5, type1) == NumberWithUnits(10, type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)) {
//                    CHECK(NumberWithUnits(5, type1) + NumberWithUnits(5, type2.first) ==
//                          NumberWithUnits(NumberWithUnits::conversion(type2.first, type1, 5) + 5, type1));
//                    CHECK(NumberWithUnits(5, type2.first) + NumberWithUnits(5, type1) ==
//                          NumberWithUnits(NumberWithUnits::conversion(type1, type2.first, 5) + 5, type2.first));
//        }
//    }
            CHECK(NumberWithUnits(5, "kg") + NumberWithUnits(5, "kg") == NumberWithUnits(10, "kg"));
            CHECK(NumberWithUnits(5, "g") + NumberWithUnits(5, "kg") == NumberWithUnits(5005, "g"));
            CHECK(NumberWithUnits(5, "kg") + NumberWithUnits(5, "g") == NumberWithUnits(5.005, "kg"));
    CHECK_THROWS(NumberWithUnits(5, "kg") + NumberWithUnits(5, "m"));
}

TEST_CASE ("- binary") {
//    ifstream units_file{"./units.txt"};
//    NumberWithUnits::read_units(units_file);
//    for(string type1:NumberWithUnits::get_types()){
//                CHECK(NumberWithUnits(5,type1)-NumberWithUnits(3,type1)==NumberWithUnits(2,type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)){
//                    CHECK(NumberWithUnits(5,type1)-NumberWithUnits(5,type2.first)==NumberWithUnits(NumberWithUnits::conversion(type2.first,type1,5)-5,type1));
//                    CHECK(NumberWithUnits(5,type2.first)-NumberWithUnits(5,type1)==NumberWithUnits(NumberWithUnits::conversion(type1,type2.first,5)-5,type2.first));
//        }
//    }
            CHECK(NumberWithUnits(5, "kg") - NumberWithUnits(3, "kg") == NumberWithUnits(2, "kg"));
            CHECK(NumberWithUnits(5, "g") - NumberWithUnits(5, "kg") == NumberWithUnits(-4995, "g"));
            CHECK(NumberWithUnits(5, "kg") - NumberWithUnits(5, "g") == NumberWithUnits(4.995, "kg"));
    CHECK_THROWS(NumberWithUnits(5, "kg") - NumberWithUnits(5, "m"));
}

TEST_CASE ("+=") {
//    ifstream units_file{"./units.txt"};
//    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{5, "kg"};
    NumberWithUnits b{5, "g"};

//    for(string type1:NumberWithUnits::get_types()){
//                a=NumberWithUnits(5,type1);
//                a+=NumberWithUnits(3,type1);
//                CHECK(a==NumberWithUnits(8,type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)){
//                a=NumberWithUnits(5,type2.first);
//                a+=NumberWithUnits(5,type1);
//                    CHECK(a==NumberWithUnits(NumberWithUnits::conversion(type2.first,type1,5)+5,type1));
//        }
//    }
    a += NumberWithUnits(3, "kg");
            CHECK(a == NumberWithUnits(8, "kg"));
    a += NumberWithUnits(5, "g");
            CHECK(a == NumberWithUnits(8.005, "kg"));
    b += a;
            CHECK(b == NumberWithUnits(8010, "g"));
    CHECK_THROWS(NumberWithUnits(5, "kg") - NumberWithUnits(5, "m"));
}

TEST_CASE ("-=") {
//    ifstream units_file{"./units.txt"};
//    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{5, "kg"};
    NumberWithUnits b{5, "g"};
//    for(string type1:NumberWithUnits::get_types()){
//        a=NumberWithUnits(5,type1);
//        a-=NumberWithUnits(3,type1);
//                CHECK(a==NumberWithUnits(8,type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)){
//            a=NumberWithUnits(5,type2.first);
//            a-=NumberWithUnits(5,type1);
//                    CHECK(a==NumberWithUnits(NumberWithUnits::conversion(type2.first,type1,5)+5,type1));
//        }
//    }
    a -= NumberWithUnits(3, "kg");
            CHECK(a == NumberWithUnits(2, "kg"));
    a -= NumberWithUnits(5, "g");
            CHECK(a == NumberWithUnits(1.995, "kg"));
    b -= a;
            CHECK(b == NumberWithUnits(-1990, "g"));
    CHECK_THROWS(NumberWithUnits(5, "kg") - NumberWithUnits(5, "m"));
}

TEST_CASE ("<") {
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
//    for(string type1:NumberWithUnits::get_types()){
//                CHECK(NumberWithUnits(3,type1)<NumberWithUnits(9,type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)){
//            if(type2.second<1)
//                    CHECK(NumberWithUnits(5,type2.first)<NumberWithUnits(5,type1));
//            else{
//                CHECK_FALSE(NumberWithUnits(5,type1)<NumberWithUnits(5,type2.first));
//            }
//        }
//    }
            CHECK(NumberWithUnits(5, "kg") < NumberWithUnits(10, "kg"));
            CHECK(NumberWithUnits(5, "g") < NumberWithUnits(10, "kg"));
            CHECK_FALSE(NumberWithUnits(5, "kg") < NumberWithUnits(10, "g"));
//            CHECK_FALSE(NumberWithUnits(5, "kg") < NumberWithUnits(10, "m"));

}
TEST_CASE("<="){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
//    for(string type1:NumberWithUnits::get_types()){
//                CHECK(NumberWithUnits(3,type1)<=NumberWithUnits(9,type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)){
//            if(type2.second<=1)
//                        CHECK(NumberWithUnits(5,type2.first)<=NumberWithUnits(5,type1));
//            else{
//                        CHECK_FALSE(NumberWithUnits(5,type1)<=NumberWithUnits(5,type2.first));
//            }
//        }
//    }
            CHECK(NumberWithUnits(5, "kg") <= NumberWithUnits(10, "kg"));
            CHECK(NumberWithUnits(5, "g") <= NumberWithUnits(10, "kg"));
            CHECK_FALSE(NumberWithUnits(5, "kg") <= NumberWithUnits(10, "g"));
            CHECK(NumberWithUnits(5, "kg") <= NumberWithUnits(5, "kg"));
}
TEST_CASE(">"){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
//    for(string type1:NumberWithUnits::get_types()){
//                CHECK(NumberWithUnits(3,type1)<=NumberWithUnits(9,type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)){
//            if(type2.second<=1)
//                        CHECK(NumberWithUnits(5,type2.first)<=NumberWithUnits(5,type1));
//            else{
//                        CHECK_FALSE(NumberWithUnits(5,type1)<=NumberWithUnits(5,type2.first));
//            }
//        }
//    }
            CHECK(NumberWithUnits(10, "kg") > NumberWithUnits(4, "kg"));
            CHECK(NumberWithUnits(5, "kg") > NumberWithUnits(10, "g"));
            CHECK_FALSE(NumberWithUnits(5, "kg") > NumberWithUnits(10, "kg"));
            //CHECK_THROWS(NumberWithUnits(5, "kg") > NumberWithUnits(10, "m"));

}
TEST_CASE(">="){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
//    for(string type1:NumberWithUnits::get_types()){
//                CHECK(NumberWithUnits(9,type1)>=NumberWithUnits(3,type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)){
//            if(type2.second>=1)
//                        CHECK(NumberWithUnits(5,type2.first)>=NumberWithUnits(5,type1));
//            else{
//                        CHECK_FALSE(NumberWithUnits(5,type1)>=NumberWithUnits(5,type2.first));
//            }
//        }
//    }
CHECK(NumberWithUnits(10, "kg") >= NumberWithUnits(5, "kg"));
CHECK(NumberWithUnits(5, "kg") >= NumberWithUnits(10, "g"));
CHECK(NumberWithUnits(5, "kg") >= NumberWithUnits(10, "g"));
CHECK_FALSE(NumberWithUnits(5, "g") >= NumberWithUnits(5, "kg"));
//CHECK_THROWS(NumberWithUnits(5, "kg") >= NumberWithUnits(10, "m"));
}
TEST_CASE("=="){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
//    for(string type1:NumberWithUnits::get_types()){
//                CHECK(NumberWithUnits(9,type1)==NumberWithUnits(9,type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)){
//                        CHECK(NumberWithUnits(5,type2.first)+NumberWithUnits(5,type1)==NumberWithUnits::conversion(type1,type2.first,5)+5);
//        }
//    }
CHECK(NumberWithUnits(10, "kg") == NumberWithUnits(10, "kg"));
    CHECK(NumberWithUnits(10000, "g") == NumberWithUnits(10, "kg"));
    //CHECK_FALSE(NumberWithUnits(10000, "g") == NumberWithUnits(10, "m"));
}
TEST_CASE("!="){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
//    for(string type1:NumberWithUnits::get_types()){
//                CHECK(NumberWithUnits(5,type1)!=NumberWithUnits(9,type1));
//        for(auto type2:NumberWithUnits::get_type_group(type1)){
//                    CHECK(NumberWithUnits(3,type2.first)+NumberWithUnits(5,type1)!=NumberWithUnits::conversion(type1,type2.first,5)+5);
//        }
//    }
/*    CHECK(NumberWithUnits(1, "kg") != NumberWithUnits(10, "kg"));
    CHECK(NumberWithUnits(100, "g") != NumberWithUnits(10, "kg"));
    CHECK(NumberWithUnits(10000, "g") != NumberWithUnits(10, "kg"));*/
}

TEST_CASE("++ prefix"){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{5,"kg"};
    double ch=a.getNum();
    a++;
    CHECK(ch+1==a.getNum());

}
TEST_CASE("++ postfix"){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{5,"kg"};
    CHECK(++a==NumberWithUnits(6,"kg"));
}
TEST_CASE("-- prefix"){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{5,"kg"};
    double ch=a.getNum();
    a--;
    CHECK(ch-1==a.getNum());
}
TEST_CASE("-- postfix"){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{5,"kg"};
    CHECK(--a==NumberWithUnits(4,"kg"));
}
TEST_CASE("*"){
//    ifstream units_file{"units.txt"};
//    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{5,"kg"};
    CHECK(a*5==NumberWithUnits(25,"kg"));
}
TEST_CASE(">>"){
    NumberWithUnits a;
    istringstream sample_input{"700 [ kg ]"};
    sample_input>>a;
    CHECK(a==NumberWithUnits(700,"kg"));
}
TEST_CASE("<<"){
    NumberWithUnits a{5,"kg"};
    ostringstream sample_output;
    sample_output<<a;
    ostringstream sample_output2{"5[kg]"};
    //CHECK(sample_output==sample_output2);
}
