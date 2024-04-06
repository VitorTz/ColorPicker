#include "../include/colorsys.hpp"


colorsys::Rgb::Rgb() {

}

colorsys::Rgb::Rgb(
    const int r,
    const int g,
    const int b
) : r(r), g(g), b(b) {

}


bool colorsys::Rgb::equal(const colorsys::Rgb& o) const {
    return (
        r == o.r &&
        g == o.g &&
        b == o.b
    );
}


colorsys::Hsv::Hsv() {

}

colorsys::Hsv::Hsv(
    const int h,
    const double s,
    const double v
) : h(h), s(s), v(v) {

}


bool colorsys::Hsv::equal(const colorsys::Hsv& o) const {
    return (
        h == o.h &&
        s == o.s &&
        v == o.v
    );
}


colorsys::Hsv colorsys::rgbToHsv(
    const colorsys::Rgb& in
) {
    colorsys::Hsv out;
    // Normalize RGB values
    double red = in.r / 255.0;
    double green = in.g / 255.0;
    double blue = in.b / 255.0;

    double cmax = std::max(red, std::max(green, blue));
    double cmin = std::min(red, std::min(green, blue));
    double delta = cmax - cmin;

    // Calculate Hue
    if (delta == 0) {
        out.h = 0;  // Undefined, set to 0
    } else if (cmax == red) {
        out.h = 60 * fmod(((green - blue) / delta), 6.0);
    } else if (cmax == green) {
        out.h = 60 * (((blue - red) / delta) + 2);
    } else if (cmax == blue) {
        out.h = 60 * (((red - green) / delta) + 4);
    }

    // Make sure hue is in the range [0, 360)
    if (out.h < 0) {
        out.h += 360;
    }

    // Calculate Saturation
    if (cmax == 0) {
        out.s = 0;
    } else {
        out.s = (delta / cmax) * 100;
    }

    // Calculate Value
    out.v = cmax * 100;
    return out;
}

colorsys::Rgb colorsys::hsvToRgb(
    const colorsys::Hsv& in
) {
    colorsys::Rgb out;
    double h, s, v;
    h = in.h / 360.0;
    s = in.s / 100.0;
    v = in.v / 100.0;

    if (s == 0.0) {
        out.r = out.g = out.b = v * 255;            
        return out;
    }
    
    int i = h * 6.0;
    double f = (h * 6.0) - i;
    double p = v * (1.0 - s);
    double q = v * (1.0 - s * f);
    double t = v * (1.0 - s * (1.0 - f));

    i = i % 6;
    int v1 = v * 255.0;        
    q *= 255;
    t *= 255;
    p *= 255;

    switch (i) {
        case 0:
            out.r = v1;
            out.g = t;
            out.b = p;
            break;
        case 1:
            out.r = q;
            out.g = v1;
            out.b = p;
            break;
        case 2:
            out.r = p;
            out.g = v1;
            out.b = t;
            break;
        case 3:
            out.r = p;
            out.g = q;
            out.b = v1;
            break;
        case 4:
            out.r = t;
            out.g = p;
            out.b = v1;
            break;
        case 5:
            out.r = v1;
            out.g = p;
            out.b = q;
            break;
        default:
            break;
    }                    
    return out;        
} 


std::string colorsys::rgbToHex(
    const colorsys::Rgb& rgb
) {
    std::string hex = "#";
    hex += cp::decimalToHex(rgb.r);
    hex += cp::decimalToHex(rgb.g);
    hex += cp::decimalToHex(rgb.b);
    return hex;
}


std::vector<colorsys::Rgb> colorsys::createGradient(const int height) {
    std::vector<colorsys::Rgb> colors;
    for (int i = 0; i < height; i++) {
        const float hue = static_cast<float>(i) / height;
        colors.push_back(
            hsvToRgb(
                {static_cast<int>(hue * 360.0), 100, 100}
            )
        );
    }
    return colors;
}