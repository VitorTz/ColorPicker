#include "../include/color_rectangle.hpp"


cp::ColorRectangle::ColorRectangle(
    const sf::Vector2i pos,
    const sf::Vector2i size,
    const colorsys::Rgb& color
) : cp::Component(pos, size),    
    colors(std::vector<sf::Color>(size.x * size.y, sf::Color::Black)),
    cursorPos(pos),
    image((sf::Vector2f) pos, size) {
        this->changeColor(color);        
    }


void cp::ColorRectangle::changeColor(
    const colorsys::Rgb& color
) {
    const std::size_t total = size.x * size.y;        
    colorsys::Hsv baseColor = colorsys::rgbToHsv(color);            

    for (std::size_t i = 0; i < total; i++) {
        const double row = i / size.x;
        const double col = i % size.x;
        const double s = (col / size.x) * 100.0;
        const double v = (1.0 - row / size.y) * 100.0;                
        const colorsys::Rgb rgb = colorsys::hsvToRgb(
            colorsys::Hsv{baseColor.h, s, v}
        );
        colors[i].r = rgb.r;
        colors[i].g = rgb.g;
        colors[i].b = rgb.b;
        image.setPixel(row, col, colors[i]);
    }
    selectedColor = colors[selectedColorIndex]; 
    selectedColorRgb = {selectedColor.r, selectedColor.g, selectedColor.b};
    selectedColorHex = colorsys::rgbToHex(selectedColorRgb);    
}


void cp::ColorRectangle::update(
    const sf::Vector2i& mousePos
) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false) {
        return;
    }

    const bool isInsideRect = (
        mousePos.x >= pos.x &&
        mousePos.x <= pos.x + size.x &&
        mousePos.y >= pos.y &&
        mousePos.y <= pos.y + size.y
    );
    if (isInsideRect == false) {
        return;
    }

    int left = mousePos.x - pos.x;
    int top = mousePos.y - pos.y;
    if (left == size.x) left = size.x - 1;
    if (top == size.y) top = size.y - 1;
    selectedColorIndex = top * size.x + left;
    selectedColor = colors[selectedColorIndex];
    selectedColorRgb = {selectedColor.r, selectedColor.g, selectedColor.b};
    selectedColorHex = colorsys::rgbToHex(selectedColorRgb);
    cursorPos = {pos.x + left, pos.y + top};    
}


void cp::ColorRectangle::draw(
    sf::RenderWindow& window
) {    
    image.draw(window);    
    cp::drawBorder(window, cursorPos, cursorSize, sf::Color::White);
    cp::drawBorder(
        window, 
        cursorPos - sf::Vector2i(1, 1), 
        cursorSize + sf::Vector2i(2, 2), 
        sf::Color::Black
    );
}