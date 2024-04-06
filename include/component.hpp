#pragma once
#include <SFML/Graphics.hpp>


namespace cp {


    class Component {

        public:
            sf::Vector2i pos;
            sf::Vector2i size;

        public:
            Component(
                const sf::Vector2i pos,
                const sf::Vector2i size
            ) : pos(pos), size(size) { }
            virtual ~Component() = default;
            virtual void draw(sf::RenderWindow& window) = 0;

    };
    
} // namespace cp
