#include "HIManager.hpp"
#include "VertexTypes.hpp"
#include "VertexBufferObject.hpp"
#include "HeadingIndicator.hpp"

#include <glm/glm.hpp>



HIManager* HIManager::m_Instance = nullptr;

HIManager::HIManager()
{

}

HIManager* HIManager::getInstance()
{
    if(m_Instance==nullptr)
    {
        m_Instance = new HIManager();
    }
    return m_Instance;
}

HeadingIndicator* HIManager::createCircle()
{
    Vertex3TexList vertices;
    IndexList indices;

    float radius = 0.8f;
    int numSegments = 72;

    float angle = 360.0f / numSegments;
    int vertexCount = numSegments + 1; // Include the center vertex

    vertices.clear();
    indices.clear();

    Vertex3Tex centerVertex;
    centerVertex.pos = glm::vec3(0.0f, 0.0f, 0.0f);
    centerVertex.tex = glm::vec2(0.5f, 0.5f); // Texture center coordinates
    vertices.push_back(centerVertex);

    for (int i = 0; i < vertexCount; i++) {
        float newAngle = i * angle;
        float x = radius * cos(glm::radians(newAngle));
        float y = radius * sin(glm::radians(newAngle));
        float z = 0.0f;

        Vertex3Tex vertex;
        vertex.pos = glm::vec3(x, y, z);
        vertex.tex = glm::vec2((cos(glm::radians(newAngle)) + 1.0f) * 0.5f, (sin(glm::radians(newAngle)) + 1.0f) * 0.5f);
        vertices.push_back(vertex);
    }
    for (int i = 0; i < numSegments; i++) {
        indices.push_back(0);
        indices.push_back(i + 1);
        indices.push_back(i + 2);
    }

    VertexBufferObject* vbo = new VertexBufferObject();
    vbo->build(vertices,indices);
    HeadingIndicator* frame = new HeadingIndicator();
    frame->m_Vbo = vbo;
    frame->m_IndexCount = indices.size();
    frame->m_VertexCount = vertices.size();
    frame->m_Color = glm::vec3(1.0f, 0.0f, 0.0f);

    return frame;
}

HeadingIndicator* HIManager::createFlight()
{
    float temp = 0.8f;
    // Define the vertices for the airplane miniature
    Vertex3List vertices;
    vertices.push_back({ glm::vec3(0.0f*temp, 0.55f*temp, 0.0f)});     //0
    vertices.push_back({ glm::vec3(-0.10f*temp, 0.05f*temp, 0.0f)});  //1
    vertices.push_back({ glm::vec3(-0.35f*temp, -0.15f*temp, 0.0f)}); //2
    vertices.push_back({ glm::vec3(-0.38f*temp, -0.08f*temp, 0.0f)}); //3
    vertices.push_back({ glm::vec3(-0.38f*temp, -0.27f*temp, 0.0f)}); //4
    vertices.push_back({ glm::vec3(-0.35f*temp, -0.23f*temp, 0.0f)}); //5
    vertices.push_back({ glm::vec3(-0.10f*temp, -0.25f*temp, 0.0f)}); //6
    vertices.push_back({ glm::vec3(-0.10f*temp, -0.35f*temp, 0.0f)}); //7
    vertices.push_back({ glm::vec3(-0.22f*temp, -0.5f*temp, 0.0f)});  //8
    vertices.push_back({ glm::vec3(-0.07f*temp, -0.5f*temp, 0.0f)});  //9
    vertices.push_back({ glm::vec3(-0.07f*temp, -0.45f*temp, 0.0f)}); //10
    vertices.push_back({ glm::vec3(0.0f*temp, -0.55f*temp, 0.0f)});   //11
    vertices.push_back({ glm::vec3(0.10f*temp, 0.05f*temp, 0.0f)});   //12
    vertices.push_back({ glm::vec3(0.35f*temp, -0.15f*temp, 0.0f)});  //13
    vertices.push_back({ glm::vec3(0.38f*temp, -0.08f*temp, 0.0f)});  //14
    vertices.push_back({ glm::vec3(0.38f*temp, -0.27f*temp, 0.0f)});  //15
    vertices.push_back({ glm::vec3(0.35f*temp, -0.23f*temp, 0.0f)});  //16
    vertices.push_back({ glm::vec3(0.10f*temp, -0.25f*temp, 0.0f)});  //17
    vertices.push_back({ glm::vec3(0.10f*temp, -0.35f*temp, 0.0f)});  //18
    vertices.push_back({ glm::vec3(0.22f*temp, -0.5f*temp, 0.0f)});   //19
    vertices.push_back({ glm::vec3(0.07f*temp, -0.5f*temp, 0.0f)});   //20
    vertices.push_back({ glm::vec3(0.07f*temp, -0.45f*temp, 0.0f)});  //21

    // Define the indices to draw the line
    IndexList indices = { 0, 1, 2,3 ,4 ,5 ,6 ,7 ,8, 9, 10, 11, 21, 20, 19, 18, 17, 16, 15, 14, 13 ,12 };

    // Create a new VertexBufferObject
    VertexBufferObject* vbo = new VertexBufferObject();
    vbo->build(vertices,indices);

    // Create a new HeadingIndicator instance for the airplane
    HeadingIndicator* airplane = new HeadingIndicator();
    airplane->m_Vbo = vbo;
    airplane->m_IndexCount = indices.size();
    airplane->m_VertexCount = vertices.size();
    airplane->m_Color = glm::vec3(1.0f, 1.0f, 1.0f); // Set the airplane color

    return airplane;
}
HeadingIndicator* HIManager::createScaleTriangles()
{
    Vertex3List vertices;
    IndexList indices;
    float radius= 0.75f;
    float innerRadius = 0.7f;
    float temp=1.5f;
    int numTriangles = 8;
    int numVertices = numTriangles * 3;
    float angle = 360.0f / numTriangles;

    for (int i = 0; i <= numTriangles; i++)
    {
        float newAngle = i * angle;
        float newAngle1 = (i* angle) -temp ;
        float newAngle2 = (i* angle) +temp ;
        float x1 = radius * cos(glm::radians(newAngle1));
        float y1 = radius * sin(glm::radians(newAngle1));
        float z1 = 0.0f;
        float x2 = radius * cos(glm::radians(newAngle2));
        float y2 = radius * sin(glm::radians(newAngle2));
        float z2 = 0.0f;
        float x3 = innerRadius * cos(glm::radians(newAngle));
        float y3 = innerRadius * sin(glm::radians(newAngle));
        float z3 = 0.0f;

        Vertex3 vertex1;
        Vertex3 vertex2;
        Vertex3 vertex3;

        vertex1.pos = glm::vec3(x1, y1, z1);
        vertex2.pos = glm::vec3(x2, y2, z2);
        vertex3.pos = glm::vec3(x3, y3, z3);
        vertices.push_back(vertex1);
        vertices.push_back(vertex2);
        vertices.push_back(vertex3);

    }
    for (int i = 0; i <= numTriangles ; i++) {
        indices.push_back(i*3);
        indices.push_back(i*3+1);
        indices.push_back(i*3+2);
    }

    VertexBufferObject* vbo = new VertexBufferObject();
    vbo->build(vertices,indices);
    HeadingIndicator* scale = new HeadingIndicator();
    scale->m_Vbo = vbo;
    scale->m_IndexCount = indices.size();
    scale->m_VertexCount = vertices.size();
    scale->m_Color = glm::vec3(1.0f, 1.0f, 1.0f);


    return scale;
}
   
