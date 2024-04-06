#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "util.hpp"


namespace colorsys {


    class Rgb {

        public:
            int r = 0;
            int g = 0;
            int b = 0;
        
        public:
            Rgb();
            Rgb(
                const int r,
                const int g,
                const int b
            );
            bool equal(const colorsys::Rgb& rgb) const;
            std::string toString() const {
                std::string s = "rgb(" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ")";
                return s;
            }
    };


    class Hsv {

        public:
            int h = 0; // [0-360]
            double s = 0.0; // [0-100]
            double v = 0.0; // [0-100]
        
        public:
            Hsv();
            Hsv(
                const int h,
                const double s,
                const double v
            );
            bool equal(const colorsys::Hsv& hsv) const;

    };


    colorsys::Hsv rgbToHsv(const colorsys::Rgb& in);

    colorsys::Rgb hsvToRgb(const colorsys::Hsv& in);

    std::string rgbToHex(const colorsys::Rgb& rgb);

    std::vector<colorsys::Rgb> createGradient(const int height);
    
} // namespace colorsys

