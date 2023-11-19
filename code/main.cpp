#include "ComplexPlane.h"

int main()
{
    const string font_name =        //haven't chosen a font yet..

    int pixelWidth = VideoMode::getDesktopMode().width / 2;
	int pixelHeight = VideoMode::getDesktopMode().height / 2;
	VideoMode vm(pixelWidth, pixelHeight);
    RenderWindow window(vm, "Mandelbrot", Style::Default);

    Font font;
    if (!font.loadFromFile(font_name))
    {
        cout << "Error loading " << font_name << endl; 
    }

    Text text;
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);

    while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					update = true;
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

    }
}

