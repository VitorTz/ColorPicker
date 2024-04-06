#include "../include/color_gradient.hpp"


cp::ColorGradient::ColorGradient(
    const sf::Vector2i pos,
    const sf::Vector2i size
) : cp::Component(pos, size),
    colors(colorsys::createGradient(size.y)),
    selectedColorIndex(0),
    selectedColor(colors[selectedColorIndex]),
    cursorPos(pos),
    cursorSize({size.x, 2}), 
    image(sf::Vector2f(pos), size) {
    
    for (std::size_t top = 0; top < colors.size(); top++) {
        const colorsys::Rgb& rgbColor = colors[top];
        const sf::Color color(rgbColor.r, rgbColor.g, rgbColor.b);
        for (std::size_t left = 0; left < size.x; left++) {
            image.setPixel(top, left, color);
        }
    }
}


void cp::ColorGradient::update(
    const sf::Vector2i mousePos
) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false) {
        return;
    }
    
    const bool isInsideGradient = (
        mousePos.x >= pos.x &&
        mousePos.x <= pos.x + size.x &&
        mousePos.y >= pos.y &&
        mousePos.y <= pos.y + size.y
    );
    if (!isInsideGradient) {
        return;
    }

    int y = mousePos.y - pos.y;
    if (y >= 180) { y = colors.size(); }

    selectedColor = colors[y];
    selectedColorIndex = y;
    cursorPos = {pos.x, pos.y + y};
}


void cp::ColorGradient::draw(
    sf::RenderWindow& window
) {
    image.draw(window);
    cp::drawBorder(
        window,
        cursorPos,
        cursorSize,
        sf::Color::White
    );
    cp::drawBorder(
        window,
        cursorPos - sf::Vector2i(1, 1),
        cursorSize + sf::Vector2i(2, 2),
        sf::Color::Black
    );
}