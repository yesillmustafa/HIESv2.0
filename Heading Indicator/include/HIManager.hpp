#ifndef HIManager_hpp
#define HIManager_hpp

class HeadingIndicator;

class HIManager
{
    public:
    
    static HIManager* getInstance();
    HeadingIndicator* createCircle();
    HeadingIndicator* createFlight();
    HeadingIndicator* createScaleTriangles();
    
    private:
    static HIManager* m_Instance;
    HIManager();
};

#endif

