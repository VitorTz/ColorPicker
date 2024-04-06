#include "../include/text.hpp"


cp::Text::Text(
    std::string txt,
    const sf::Vector2i pos
) : cp::Component(pos, {}),
    txtStr(std::move(txt)) {
    font.loadFromFile("assets/Poppins-Regular.ttf");
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
}


void cp::Text::changeTxt(const std::string& txt) {
    this->txtStr = txt;
    text.setString(txt);    
}


void cp::Text::draw(sf::RenderWindow& window) {
    text.setPosition(sf::Vector2f(pos.x, pos.y));
    window.draw(text);
}