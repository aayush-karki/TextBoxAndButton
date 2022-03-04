#include "SFML/Graphics.hpp"

int main()
{
	// render window
	sf::RenderWindow window( sf::VideoMode( 500, 500 ), "Text and Buttons");

	// event handler
	sf::Event events;
	
	// shape
	sf::CircleShape circle;
	circle.setFillColor( sf::Color::Red );
	circle.setRadius( 100 );

	bool close = false;

	// app main loop
	while( !close )
	{
		// handeling events
		while( window.pollEvent( events ) )
		{
			if( events.type == sf::Event::Closed )
			{
				close = true;
			}
		}

		// logics

		// rendering
		window.clear();
		window.draw( circle );
		window.display();

	}

}