#pragma once
#include "component.hpp"
#include "colorsys.hpp"
#include "drawable_image.hpp"
#include <vector>

namespace cp {

    class ColorRectangle : public cp::Component {

    public:        
        std::size_t selectedColorIndex = 0u;        
        sf::Color selectedColor;
        colorsys::Rgb selectedColorRgb;
        std::string selectedColorHex;
        sf::Vector2i cursorPos;
        sf::Vector2i cursorSize = sf::Vector2i(4, 4);
        std::vector<sf::Color> colors;
        cp::DrawableImage image;        

    public:
        ColorRectangle(
            const sf::Vector2i pos,
            const sf::Vector2i size,
            const colorsys::Rgb& color
        );
        void changeColor(const colorsys::Rgb& color);
        void update(const sf::Vector2i& mousePos);
        void draw(sf::RenderWindow& window);

};
    
} // namespace cp
