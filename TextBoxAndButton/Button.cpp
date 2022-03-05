#include "Button.h"
/// 
/// @brief setter funciton to set the position
/// 
/// sets the button and then centers the text
/// 
void Button::SetPosition( sf::Vector2f a_pos )
{
	m_button.setPosition( a_pos );

	// getting the start pos of the text such that it is always centered
	float xPosText = ( a_pos.x + m_button.getLocalBounds().width / 2 ) -
		( m_text.getGlobalBounds().width / 2 );
	float yPosText = ( a_pos.y + m_button.getLocalBounds().height / 2 ) -
		( m_text.getGlobalBounds().height / 2 );

	m_text.setPosition( xPosText, yPosText );
}

bool Button::IsMouseOverBtn( sf::RenderWindow& a_window )
{
	int mousePosX = sf::Mouse::getPosition( a_window ).x;
	int mousePosY = sf::Mouse::getPosition( a_window ).y;

	float btnStartPosX = m_button.getPosition().x;
	float btnStartPosY = m_button.getPosition().y;

	float btnPosXwidth = btnStartPosX + m_button.getLocalBounds().width;
	float btnPosYheight = btnStartPosY + m_button.getLocalBounds().height;

	//if(mousePosX <  )
	return false;
}