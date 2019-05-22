#ifndef VOLCANO_HPP_INCLUDED
#define VOLCANO_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Volcano : public sf::Drawable, public sf::Transformable {

    int width, height;

    sf::Sprite sprite;

public:

    Volcano(int, int, sf::Texture*, sf::IntRect);

    void update();

    void errupt();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(sprite);
    }
};

#endif // VOLCANO_HPP_INCLUDED
