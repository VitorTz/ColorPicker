#pragma once
#include <SFML/Graphics.hpp>


namespace cp {

    class DrawableImage {

        private:
            sf::Image image;
            sf::Vector2f pos;

        public:
            DrawableImage(
                const sf::Vector2f pos,
                const sf::Vector2i size
            ) : pos(pos) {
                image.create(size.x, size.y, sf::Color::White);
            }
            void setPixel(
                const int row,
                const int col,
                sf::Color color
            ) {
                image.setPixel(col, row, std::move(color));
            }
            void draw(sf::RenderWindow& window) {
                sf::Sprite sprite;
                sf::Texture texture;
                texture.loadFromImage(image);
                sprite.setTexture(texture);
                sprite.setPosition(pos);
                window.draw(sprite);
            }

    };
    
} // namespace cp
