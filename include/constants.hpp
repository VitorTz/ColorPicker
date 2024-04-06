#pragma once
#include <SFML/Graphics/Color.hpp>

namespace cp::constants {
    
    constexpr unsigned int SCREEN_WIDTH = 460u;
    constexpr unsigned int SCREEN_HEIGHT = 230u;
    constexpr char WINDOW_TITLE[] = "Color Picker";
    const sf::Color WINDOW_BG_COLOR = sf::Color(18, 18, 18);
    constexpr int FPS = 30;

} // namespace cp
