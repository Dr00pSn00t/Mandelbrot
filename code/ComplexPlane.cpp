#include "ComplexPlane.h"

ComplexPLane::ComplexPlane(int pixelWidth, int pixelHeight)
{
    // Assign m_pixelWidth with the parameter values
    m_pixel_size.push_back(Vector2i(pixelWidth, pixelHeight));

    // Calculate and assign the aspect ratio of the monitor, m_aspectRatio
    // height / width
    m_aspectRatio = static_cast<double>(pixelHeight) / static_cast<double>(pixelWidth); //static casted to doubles to avoid integer division rounding

    // Assign m_plane_center with {0,0}
    m_plane_center.push_back(Vector2f(0, 0));

    // Assign m_plane_size with {BASE_WIDTH, BASE_HEIGHT * m_aspectRatio}
    m_plane_size.push_back(Vector2f(BASE_WIDTH, BASE_HEIGHT * m_aspectRatio));

    // Assign m_zoomCount with 0
    m_zoomCount = 0;

    // Assign m_State with State::CALCULATING to be ready for the initial screen
    m_State = State::CALCULATING; // ???

    // Initialize VertexArray
    // Set its primitive type to Points
    m_vArray.setPrimitiveType(Points);
    // Resize it to pixelWidth * pixelHeight
    m_vArray.resize(pixelWidth * pixelHeight);

}

void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{

}

void ComplexPlane::zoomIn()
{

}

void ComplexPlane::zoomOut()
{

}

void ComplexPlane::setCenter(vector<Vector2i> mousePixel)
{

}

void ComplexPlane::loadText(Text& text)
{

}

void ComplexPlane::updateRender()
{

}

int ComplexPlane::countIterations(vector<Vector2f> coord)
{

}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{

}

ComplexPlane::vector<Vector2f> mapPixelToCoords(vector<Vector2i> mousePixel)
{

}
