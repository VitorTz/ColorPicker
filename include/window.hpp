#pragma once
#include <SFML/Graphics.hpp>
#include "constants.hpp"
#include "color_picker.hpp"


namespace cp {

    class Window {

        private:
            sf::RenderWindow window;
            cp::ColorPicker picker;
        
        private:
            void handleInput();
            void update();
            void render();

        public:
            Window();
            void run();

    };
    
} // namespace cp
