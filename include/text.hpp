#pragma once
#include "component.hpp"


namespace cp {

    class Text : public cp::Component {

        private:
            sf::Text text;
            sf::Font font;
            std::string txtStr;

        public:
            Text(
                std::string txt,
                const sf::Vector2i pos
            );
            void changeTxt(const std::string& txt);
            const std::string& getTxt() const;
            void draw(sf::RenderWindow& window);
        
    };
    
} // namespace cp
