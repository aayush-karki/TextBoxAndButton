#include "SFML/Graphics.hpp"
#include <filesystem>

#include <iostream>
#include <sstream>

#include "TextBox.h"
#include "Button.h"

// ==========================================================================

int main()
{
	// render window
	sf::RenderWindow window( sf::VideoMode( 500, 500 ), "Text and Buttons");

	// event handler
	sf::Event events;
	// shape
	sf::CircleShape circle;
	//circle.setFillColor( sf::Color::Red );

	// getting the cwd
	std::string cwd = std::filesystem::current_path().string();
	sf::Font font;
	if( !font.loadFromFile( cwd + "\\Fonts\\arial.ttf" ) )
	{
		std::cout << "Error!!! while loading font" << std::endl;
	}

	TextBox myTextBox( 25, sf::Color::White, false);
	myTextBox.SetFont( font );
	myTextBox.SetPosition( sf::Vector2f( 200, 200 ) );
	myTextBox.SetLimit( true, 10 );

	bool close = false;

	Button myButton( "Click Me", { 200,50 }, 20, sf::Color::Green, sf::Color::Black );
	myButton.SetFont( font );
	myButton.SetPosition( { 200,300 } );

	// app main loop
	while( !close )
	{
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::Return ) )
		{
			myTextBox.setSelected( true );
		}
		else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
		{
			myTextBox.setSelected( false );
		}

		// handeling events
		while( window.pollEvent( events ) )
		{
			if( events.type == sf::Event::Closed )
			{
				close = true;
			}
			else if( events.type == sf::Event::TextEntered )
			{
				myTextBox.TypeOn( events );
			}
			else if( events.type == sf::Event::MouseMoved )
			{
				if( myButton.IsMouseOverBtn( window ) )
				{
					myButton.SetBtnBackColor( sf::Color::Blue );
				}
				else
				{
					myButton.SetBtnBackColor( sf::Color::Green );
				}
			}
		}

		// logics

		// rendering
		window.clear();
		myTextBox.Draw( window );
		myButton.Draw( window );
		window.display();

	}

}