#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

void drawPythagoreanTree(sf::RenderTarget&, const float, const int);

int main()
{
    const float L = 150;
    const int N = 14;

    const unsigned width = static_cast<unsigned>(6 * L);
    const unsigned height = static_cast<unsigned>(4 * L);
    sf::RenderWindow window(sf::VideoMode(width, height), "Pythagorean Tree");
    while (window.isOpen())
    {
        for (sf::Event event; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        drawPythagoreanTree(window, L, N);
        window.display();
    }
}

void drawPythagoreanTree(sf::RenderTarget& target, const int N,
                         const sf::RectangleShape& parent)
{
    static const float halfSqrt2 = sqrt(2.f) / 2;

    if (N < 1) return;
    target.draw(parent);
    auto const& sz = parent.getSize();
    auto const& tf = parent.getTransform();

    auto childL = parent;                    // copy parent's color and rotation
    childL.setSize(sz * halfSqrt2);          // resize
    childL.setOrigin(0, childL.getSize().y); // bottom left corner
    childL.setPosition(tf.transformPoint({0, 0})); // reposition
    childL.rotate(-45);
    drawPythagoreanTree(target, N - 1, childL);

    auto childR = parent;               // copy parent's color and rotation
    childR.setSize(sz * halfSqrt2);     // resize
    childR.setOrigin(childR.getSize()); // bottom right corner
    childR.setPosition(tf.transformPoint({sz.x, 0})); // reposition
    childR.rotate(45);
    drawPythagoreanTree(target, N - 1, childR);
}

void drawPythagoreanTree(sf::RenderTarget& target, const float L, const int N)
{
    sf::RectangleShape rect{{L, L}};
    // set origin to center of the rect, easier to center position on screen
    rect.setOrigin(rect.getSize() / 2.f);
    rect.setPosition(target.getSize().x / 2.f, target.getSize().y - L / 2.f);
    rect.setFillColor(sf::Color::Black);
    drawPythagoreanTree(target, N, rect);
}

