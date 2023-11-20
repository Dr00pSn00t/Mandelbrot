#ifndef COMPLEXPLANEH
#define COMPLEXPLANEH
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>


using namespace sf;
using namespace std;

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;
const float BASE_ZOOM = 0.5;

enum State { CALCULATING, DISPLAYING };

class ComplexPlane : public Drawable
{
public:
    ComplexPlane(int pixelWidth, int pixelHeight);
    const void draw(RenderTarget& target, RenderStates states);
    void zoomIn();
    void zoomOut();
    void setCenter(vector<Vector2i> mousePixel);
    void setMouseLocation(Vector2i mousePixel);
    void loadText(Text& text);
    void updateRender();

    int countIterations(vector<Vector2f> coord);
    void iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b);
    vector<Vector2f> mapPixelToCoords(vector<Vector2i> mousePixel);
    

private:
    VertexArray m_vArray;
    State m_State;
    vector<Vector2f> m_mouseLocation;
    vector<Vector2i> m_pixel_size;
    vector<Vector2f> m_plane_center;
    vector<Vector2f> m_plane_size;
    int m_zoomCount;
    float m_aspectRatio;
};