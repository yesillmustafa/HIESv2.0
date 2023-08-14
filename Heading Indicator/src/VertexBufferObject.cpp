#include "VertexBufferObject.hpp"
#include "VertexTypes.hpp"
#include <GLES2/gl2.h>
#include <iostream>

VertexBufferObject::VertexBufferObject()
{
    m_VboId = 0;
    m_IboId = 0;
}

VertexBufferObject::~VertexBufferObject()
{
    if (m_VboId)
    {
        glDeleteBuffers(1, &m_VboId);
    }
    if (m_IboId)
    {
        glDeleteBuffers(1, &m_IboId);
    }
}

void VertexBufferObject::build(const Vertex3TexList &vertices, const IndexList &indices)
{
    glGenBuffers(1, &m_VboId);
    glBindBuffer(GL_ARRAY_BUFFER, m_VboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex3Tex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &m_IboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);
}

void VertexBufferObject::build(const Vertex3List &vertices, const IndexList &indices)
{
    glGenBuffers(1, &m_VboId);
    glBindBuffer(GL_ARRAY_BUFFER, m_VboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &m_IboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);
}

void VertexBufferObject::activate()
{
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, m_VboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IboId);
    //Hata Kontrolü
    GLenum error = glGetError();
    if(error != GL_NO_ERROR)
    {
        std::cout << "bindbuffer: " << error << std::endl;
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3Tex), (void*)offsetof(Vertex3Tex, pos));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3Tex), (void*)offsetof(Vertex3Tex, tex));
    //Hata Kontrolü
    GLenum error1 = glGetError();
    if(error1 != GL_NO_ERROR)
    {
        std::cout << "glVertexAttribPointer error: " << error1 << std::endl;
    }
}

void VertexBufferObject::deactivate()
{

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
