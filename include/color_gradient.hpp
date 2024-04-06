#pragma once 
#include "colorsys.hpp"
#include "component.hpp"
#include "drawable_image.hpp"


namespace cp {

    class ColorGradient : public cp::Component {
    
    public:        
        std::vector<colorsys::Rgb> colors;
        std::size_t selectedColorIndex;
        colorsys::Rgb selectedColor;
        sf::Vector2i cursorPos;
        sf::Vector2i cursorSize;
        cp::DrawableImage image;

    public:
        ColorGradient(
            const sf::Vector2i pos,
            const sf::Vector2i size
        );
        void update(const sf::Vector2i mousePos);
        void draw(sf::RenderWindow& window) override;

    };
    
} // namespace cp
