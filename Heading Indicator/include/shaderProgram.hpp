#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include<string>

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();
   
    void attachShader(const char* fileName,unsigned int shaderType);

    void link();

    void use();
    unsigned int getProgramId();
    unsigned int getModelMatrixLocation();
    unsigned int getPositionLocation();
    unsigned int getColorLocation();
    unsigned int getTexCoordLocation();


private:
    std::string getShaderFromFile(const char* fileName);
    
    unsigned int modelMatrixLocation;
    unsigned int colorLocation;
    unsigned int positionLocation;
    unsigned int texCoordLocation;
    unsigned int m_ProgramId;
  
};


#endif