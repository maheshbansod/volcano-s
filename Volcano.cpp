#include "Volcano.hpp"
#include <iostream>

Volcano::Volcano(int width, int height, sf::Texture* texture, sf::IntRect bounds)
    {
    this->width = width;
    this->height = height;

    sprite.setTexture(*texture);
    sprite.setTextureRect(bounds);
    sprite.setColor(sf::Color(255,127,0));
    sprite.setScale(sf::Vector2f(width/(float)bounds.width, height/(float)bounds.height));
    //sprite.setSize(sf::Vector2f(width, height));
    /**create and initialize variables**/
    /**set width and height of texture**/
}

void Volcano::update(float dt) {
    /**update logic for if volcano errupts
     * or maybe just spark-like behaviour when not errupted**/
     std::list<LavaParticle*>::iterator it = lava.begin();
     while(it != lava.end()) {
        (*it)->update(dt);
        it++;
     }
}

void Volcano::errupt() {
    /**Create fire and stuff**/
    sf::Vector2f pos = this->getPosition();
    for(int i=0;i<LAVA_N;i++) {
        LavaParticle *p = new LavaParticle(sf::Vector2f(width/2-15+rand()%30, 0));
        //LavaParticle *p = new LavaParticle(sf::Vector2f(30,30));
        lava.push_back(p);
     //   std::cout << p->getPosition().x << "," <<p->getPosition().y << std::endl;
    }
}

sf::Vector2i Volcano::getSize() {
    return sf::Vector2i(width, height);
}
