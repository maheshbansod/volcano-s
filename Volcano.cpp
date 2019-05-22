#include "Volcano.hpp"

Volcano::Volcano(int width, int height, sf::Texture* texture, sf::IntRect bounds)
    {
    this->width = width;
    this->height = height;

    setTexture(*texture);
    setTextureRect(bounds);
    setColor(sf::Color(255,127,0));
    setScale(sf::Vector2f(width/(float)bounds.width, height/(float)bounds.height));
    /**create and initialize variables**/
    /**set width and height of texture**/
}

void Volcano::update() {
    /**update logic for if volcano errupts
     * or maybe just spark-like behaviour when not errupted**/
}

void Volcano::errupt() {
    /**Create fire and stuff**/
}
