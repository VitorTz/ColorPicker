#include "../include/window.hpp"

cp::Window::Window(

) : window(
    sf::VideoMode(cp::constants::SCREEN_WIDTH, cp::constants::SCREEN_HEIGHT),
    cp::constants::WINDOW_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {
    window.setFramerateLimit(cp::constants::FPS);
}


void cp::Window::handleInput() {
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            window.close();
        }
    }
}


void cp::Window::update() {
    const sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    picker.update(mousePos);
}


void cp::Window::render() {
    window.clear(cp::constants::WINDOW_BG_COLOR);
    picker.draw(window);
    window.display();
}


void cp::Window::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
}
