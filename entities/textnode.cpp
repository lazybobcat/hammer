#include "textnode.h"
#include "../utils.h"

TextNode::TextNode(const std::string& text, const FontHolder& fonts) :
    mText(text, fonts.get(Fonts::Main), 20),
    mShow(true)
{
    centerOrigin(mText);
    mText.setColor(sf::Color::White);
}

void TextNode::setText(const std::string &text)
{
    mText.setString(text);
    centerOrigin(mText);
}

void TextNode::show()
{
    mShow = true;
}

void TextNode::hide()
{
    mShow = false;
}

void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(mShow)
        target.draw(mText, states);
}
