#ifndef VOLCANO_HPP_INCLUDED
#define VOLCANO_HPP_INCLUDED

#include <list>
#include <iterator>

#include <SFML/Graphics.hpp>

#include "LavaParticle.hpp"

class Volcano : public sf::Drawable, public sf::Transformable {

    int width, height;

    sf::Sprite sprite;

    std::list<LavaParticle*> lava;

    static const int LAVA_N = 500;

public:

    Volcano(int, int, sf::Texture*, sf::IntRect);

    sf::Vector2i getSize();

    void update(float dt);

    void errupt();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();

        target.draw(sprite, states);

        std::list<LavaParticle*>::const_iterator it;
        for(it = lava.begin(); it != lava.end(); it++) {
            target.draw(*(*it), states);
        }
    }
};

#endif // VOLCANO_HPP_INCLUDED
