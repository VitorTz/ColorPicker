#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <sstream>


namespace cp {

    void drawBorder(
        sf::RenderWindow& window,
        const sf::Vector2i& pos,
        const sf::Vector2i& size,
        const sf::Color& color
    );

    std::string decimalToHex(int decimal);

} // namespace cp


