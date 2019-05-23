
#include <SFML/Graphics.hpp>
#include "Volcano.hpp"

#define WIDTH 800
#define HEIGHT 600

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Volcano", sf::Style::Fullscreen);
    int width = window.getSize().x;
    int height = window.getSize().y;

    sf::Texture texture;
    sf::Clock clock;
    sf::Time elapsed = clock.getElapsedTime();

    texture.loadFromFile("volcano-white.png");

    Volcano volcano(width/4, height/4, &texture, sf::IntRect( 0,0,500,500));

    volcano.setPosition(sf::Vector2f((width-volcano.getSize().x)/2,
                        height-volcano.getSize().y));

    //LavaParticle testp(sf::Vector2f(300,300));

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
        volcano.update(elapsed.asSeconds());
        window.draw(volcano);
        //testp.update(elapsed.asSeconds());
        //window.draw(testp);
        window.display();
        elapsed = clock.restart();
    }
}
