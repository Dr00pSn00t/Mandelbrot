#include "ComplexPlane.h"

int main()
{
	const string font_name = "arial.ttf";   

	//create the window
    int pixelWidth = VideoMode::getDesktopMode().width / 2;
    int pixelHeight = VideoMode::getDesktopMode().height / 2;
    VideoMode vm(pixelWidth, pixelHeight);
    RenderWindow window(vm, "Mandelbrot", Style::Default);

	//create the plane
	ComplexPlane plane(pixelWidth, pixelHeight);

	//text and font
    Font font;
    if (!font.loadFromFile(font_name))
    {
        cout << "Error loading " << font_name << endl; 
    }

    Text text;
    text.setFont(font);
    text.setCharacterSize(25);
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
				if (event.mouseButton.button == sf::Mouse::Left)			//handle left click to zoom in and center the window
				{
					plane.zoomIn();
					plane.setCenter(Vector2i(event.mouseButton.x, event.mouseButton.y));
				}
				if (event.mouseButton.button == sf::Mouse::Right)			//handle right click to zoom out and center the window
				{
					plane.zoomOut();
					plane.setCenter(Vector2i(event.mouseButton.x, event.mouseButton.y));
				}
			}
			if (event.type == sf::Event::MouseMoved)				//update cursor location 
			{
				plane.setMouseLocation(Vector2i(event.mouseButton.x, event.mouseButton.y));
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update
		****************************************
		*/

		plane.updateRender();		//update the scene
		plane.loadText(text);

		/*
		****************************************
		Draw the scene
		****************************************
		*/

		window.clear();					//draw and display
		window.draw(plane);
		window.draw(text);
		window.display();

    }
}

