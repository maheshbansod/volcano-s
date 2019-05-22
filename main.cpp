
#include <SFML/Graphics.hpp>
#include "Volcano.hpp"

#define WIDTH 800
#define HEIGHT 600

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Volcano");
    int width = window.getSize().x;
    int height = window.getSize().y;

    sf::Texture texture;

    texture.loadFromFile("volcano-white.png");

    Volcano volcano(width/2, height/2, &texture, sf::IntRect( 0,0,500,500));

    volcano.setPosition(sf::Vector2f(width/4, height/2));

    while(window.isOpen()) {
        window.clear();

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type==sf::Event::MouseButtonPressed) {
                volcano.errupt();
            } else if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        volcano.update();
        window.draw(volcano);
        window.display();
    }
}
