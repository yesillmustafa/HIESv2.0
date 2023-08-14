#ifndef VertexBufferObject_hpp
#define VertexBufferObject_hpp

#include "VertexTypes.hpp"

class VertexBufferObject
{
private:
    unsigned int m_VboId;
    unsigned int m_IboId;

public:
    VertexBufferObject();
    ~VertexBufferObject();

    void build(const Vertex3TexList &vertices, const IndexList &indices);
    void build(const Vertex3List &vertices, const IndexList &indices);
    void activate();
    void deactivate();
};

#endif
