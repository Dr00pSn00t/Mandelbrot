#include "ComplexPlane.h"
#include <cmath> //For powers, zoomIn()

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
    // Assign m_pixelWidth with the parameter values
    m_pixel_size = Vector2i(pixelWidth, pixelHeight);

    // Calculate and assign the aspect ratio of the monitor, m_aspectRatio
    // height / width
    m_aspectRatio = static_cast<double>(pixelHeight) / static_cast<double>(pixelWidth); //static casted to doubles to avoid integer division rounding

    // Assign m_plane_center with {0,0}
    m_plane_center = Vector2f(0, 0);

    // Assign m_plane_size with {BASE_WIDTH, BASE_HEIGHT * m_aspectRatio}
    m_plane_size = Vector2f(BASE_WIDTH, BASE_HEIGHT * m_aspectRatio);

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
    //his function only needs one line of code:
    target.draw(m_vArray);
}

void ComplexPlane::zoomIn()
{
    // Increment m_zoomCount
    m_zoomCount++;

    // Set a local variable for the x size to BASE_WIDTH * (BASE_ZOOM to the m_ZoomCount power)
    int x_size = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);

    // Set a local variable for the y size to BASE_HEIGHT * m_aspectRatio * (BASE_ZOOM to the m_ZoomCount power)
    int y_size = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);

    // Assign m_plane_size with this new size
    m_plane_size = Vector2f(x_size, y_size);

    // Set m_State to CALCULATING
    m_State = State::CALCULATING;
}

void ComplexPlane::zoomOut()
{
    // Decrement m_zoomCount
    m_zoomCount--;

    // Set a local variable for the x size to BASE_WIDTH * (BASE_ZOOM to the m_ZoomCount power)
    int x_size = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);

    // Set a local variable for the y size to BASE_HEIGHT * m_aspectRatio * (BASE_ZOOM to the m_ZoomCount power)
    int y_size = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);

    // Assign m_plane_size with this new size
    m_plane_size = Vector2f(x_size, y_size);

    // Set m_State to CALCULATING
    m_State = State::CALCULATING;
}

void ComplexPlane::setCenter(Vector2i mousePixel)
{
    // Use ComplexPlane::mapPixelToCoords to find the Vector2f coordinate in the complex plane that corresponds to the screen pixel location
    // Assign m_plane_center with this coordinate
    m_plane_center = ComplexPlane::mapPixelToCoords(mousePixel);

    // Set m_State to CALCULATING
    m_State = State::CALCULATING;
}

void ComplexPlane::setMouseLocation(Vector2i mousePixel)
{
    // Use ComplexPlane::mapPixelToCoords to find the Vector2f coordinate in the complex plane that corresponds to the screen pixel location
    // Assign m_mouseLocation with this coordinate
    m_mouseLocation = ComplexPlane::mapPixelToCoords(mousePixel);
}

void ComplexPlane::loadText(Text& text)
{
    /* Use a stringstream and the corresponding member variables to create the following output:

    Mandelbrot Set
    Center: (0, 0)                  // m_plane_center
    Cursor: (-1.05313, 0.828125)    // m_mouseLocation
    Left-click to Zoom in
    Right-click to Zoom out
    
    */

    stringstream info_message;

    info_message <<
    "Mandelbrot Set" << endl <<
    "Center: (" << m_plane_center.x << ", " << m_plane_center.y << ")" << endl <<
    "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")" << endl <<
    "Left-click to Zoom in" << endl <<
    "Right-click to Zoom out";
    
    text.setString(info_message.str());
}

void ComplexPlane::updateRender()
{
    // If m_State is CALCULATING
    if (m_State == CALCULATING)
    {   
        // Create a double for loop to loop through all pixels in the screen height and width
            // Use j for x and i for y 
                // Note:  be careful not to transpose these!
        for (int j = 0; j < m_pixel_size.x; j++) {
            for (int i = 0; i < m_pixel_size.y; i++) 
            {
                // Set the position variable in the element of VertexArray that corresponds to the screen coordinate j,i
                    // This involves mapping the two-dimensional position at j,i to its one-dimensional array index:
                         // vArray[j + i * pixelWidth].position = { (float)j,(float)i };
                m_vArray[j + i * m_pixel_size.x].position = { (float)j,(float)i };

                // Use ComplexPlane::mapPixelToCoords to find the Vector2f coordinate in the complex plane that corresponds to the screen pixel location at j,i
                // Call ComplexPlane::countIterations with the Vector2f coordinate as its argumentand store the number of iterations
                int iter = ComplexPlane::countIterations(ComplexPlane::mapPixelToCoords(Vector2i(j, i))); // ???

                // Declare three local Uint8 variables r,g,b to store the RGB values for the current pixel
                    // Uint8 is an alias for unsigned char
                Uint8 r;
                Uint8 g;
                Uint8 b;

                // Pass the number of iterations and the RGB variables into ComplexPlane::iterationsToRGB
                    // This will assign the RGB values by reference
                ComplexPlane::iterationsToRGB(iter, r, g, b);

                // Set the color variable in the element of VertexArray that corresponds to the screen coordinate j,i
                m_vArray[j + i * m_pixel_size.x].color = { r,g,b };
            }
        }
        // Set the state to DISPLAYING
        m_State = State::DISPLAYING;
    }
}

int ComplexPlane::countIterations(Vector2f coord)
{
    // Count the number of iterations of the set for the given coordinate as specified above
    // ???
}

void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b)
{

}

Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel)
{

}
