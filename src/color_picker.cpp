#include "../include/color_picker.hpp"


cp::ColorPicker::ColorPicker(

) : gradient({300, 15}, {30, 180}),
    rectangle({15, 15}, {280, 180}, gradient.selectedColor),
    colorRect({40.f, 40.f}),
    rgbTxt("", {335, 60}),
    hexTxt("", {335, 80}) {  
    colorRect.setPosition(
        {
            gradient.pos.x + gradient.size.x + 5.f,
            static_cast<float>(gradient.pos.y)
        }
    );
}


void cp::ColorPicker::changeColor() {
    const colorsys::Rgb oldColor = gradient.selectedColor;
}


void cp::ColorPicker::update(
    const sf::Vector2i& mousePos
) {
    const colorsys::Rgb oldColor = gradient.selectedColor;
    gradient.update(mousePos);
    const colorsys::Rgb currentColor = gradient.selectedColor;
    if (oldColor.equal(currentColor) == false) {
        rectangle.changeColor(currentColor);
    }
    rectangle.update(mousePos);
    colorRect.setFillColor(rectangle.selectedColor);
    rgbTxt.changeTxt(rectangle.selectedColorRgb.toString());
    hexTxt.changeTxt("hex(" + rectangle.selectedColorHex + ')');
}   


void cp::ColorPicker::draw(
    sf::RenderWindow& window
) {
    gradient.draw(window);
    rectangle.draw(window);
    window.draw(colorRect);
    rgbTxt.draw(window);
    hexTxt.draw(window);
}