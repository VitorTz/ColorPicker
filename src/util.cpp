#include "../include/util.hpp"



void cp::drawBorder(
    sf::RenderWindow& window,
    const sf::Vector2i& pos,
    const sf::Vector2i& size,
    const sf::Color& color
) {
    float left = pos.x;
    float top = pos.y;
    sf::Vertex lines[] = {
        {{left, top}, color},
        {{left+size.x, top}, color},
        {{left, top}, color},
        {{left, top+size.y+1}, color},
        {{left+size.x, top}, color},
        {{left+size.x, top+size.y}, color},
        {{left, top+size.y}, color},
        {{left+size.x, top+size.y}, color}
    };
    window.draw(lines, 8, sf::Lines);
}


std::string cp::decimalToHex(int decimal) {
    std::stringstream ss;
    ss << std::hex << decimal;  
    std::string s = ss.str();
    return s.size() == 1 ? "0" + s : s; 
}