#pragma once
#include "color_gradient.hpp"
#include "color_rectangle.hpp"
#include "text.hpp"
#include <SFML/Graphics/RectangleShape.hpp>


namespace cp {

    class ColorPicker {

    private:
        cp::ColorGradient gradient;
        cp::ColorRectangle rectangle;
        sf::Color selectedColor;
        sf::RectangleShape colorRect;        
        cp::Text rgbTxt;
        cp::Text hexTxt;

    private:
        void changeColor();

    public:
        ColorPicker();
        void update(const sf::Vector2i& mousePos);
        void draw(sf::RenderWindow& window);

};
    
} // namespace cp
