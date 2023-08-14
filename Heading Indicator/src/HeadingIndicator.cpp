#include "HeadingIndicator.hpp"
#include "VertexBufferObject.hpp"
#include <GLES2/gl2.h>
#include <iostream>

void HeadingIndicator::draw()
{
    m_Vbo->activate();

    //Hata Kontrolü
    GLenum error1 = glGetError();
    if(error1 != GL_NO_ERROR)
    {
        std::cout << "activate: " << error1 << std::endl;
    }

    glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, 0);

    //Hata Kontrolü
    GLenum error2 = glGetError();
    if(error2 != GL_NO_ERROR)
    {
        std::cout << "draw: " << error2 << std::endl;
    }

    m_Vbo->deactivate();
    
    //Hata Kontrolü
    GLenum error3 = glGetError();
    if(error3 != GL_NO_ERROR)
    {
        std::cout << "deactivate: " << error3 << std::endl;
    }
}
void HeadingIndicator::drawLine()
{
    m_Vbo->activate();

    glDrawElements(GL_LINE_LOOP, m_IndexCount, GL_UNSIGNED_INT, 0);

    m_Vbo->deactivate();
}

