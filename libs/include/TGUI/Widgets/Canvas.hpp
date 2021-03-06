/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2017 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_CANVAS_HPP
#define TGUI_CANVAS_HPP


#include <TGUI/Widgets/ClickableWidget.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API Canvas : public ClickableWidget
    {
    public:

        typedef std::shared_ptr<Canvas> Ptr; ///< Shared widget pointer
        typedef std::shared_ptr<const Canvas> ConstPtr; ///< Shared constant widget pointer


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor
        ///
        /// @param size  Size of the canvas
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Canvas(const Layout2d& size = {RelLayout{1}, RelLayout{1}});


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Copy constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Canvas(const Canvas& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Move constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Canvas(Canvas&& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Overload of copy assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Canvas& operator= (const Canvas& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Overload of move assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Canvas& operator= (Canvas&& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates a new canvas widget
        ///
        /// @param size  Size of the canvas
        ///
        /// @return The new canvas
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static Canvas::Ptr create(Layout2d size = {RelLayout{1}, RelLayout{1}});


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another canvas
        ///
        /// @param canvas  The other canvas
        ///
        /// @return The new canvas
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static Canvas::Ptr copy(Canvas::ConstPtr canvas);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the widget
        ///
        /// @param size  The new size of the widget
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setSize(const Layout2d& size) override;
        using Transformable::setSize;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Clears the entire canvas with a single color
        ///
        /// This function is usually called once every frame, to clear the previous contents of the canvas.
        ///
        /// @param color Fill color to use to clear the canvas
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void clear(Color color = sf::Color(0, 0, 0, 255));


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Draws a drawable object to the canvas
        ///
        /// @param drawable Object to draw
        /// @param states   Render states to use for drawing
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Draws primitives defined by an array of vertices
        ///
        /// @param vertices    Pointer to the vertices
        /// @param vertexCount Number of vertices in the array
        /// @param type        Type of primitives to draw
        /// @param states      Render states to use for drawing
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void draw(const sf::Vertex* vertices, std::size_t vertexCount,
                  sf::PrimitiveType type, const sf::RenderStates& states = sf::RenderStates::Default);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Updates the contents of the canvas
        ///
        /// This function updates the canvas with what has been drawn so far. Like for windows, calling this
        /// function is mandatory at the end of rendering. Not calling
        /// it may leave the texture in an undefined state.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void display();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Draw the widget to a render target
        ///
        /// @param target Render target to draw to
        /// @param states Current render states
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Function called when one of the properties of the renderer is changed
        ///
        /// @param property  Lowercase name of the property that was changed
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void rendererChanged(const std::string& property) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Widget::Ptr clone() const override
        {
            return std::make_shared<Canvas>(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        sf::RenderTexture m_renderTexture;
        sf::Sprite        m_sprite;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_CANVAS_HPP
