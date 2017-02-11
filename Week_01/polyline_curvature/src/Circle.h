// Modified FROM : http://paulbourke.net/geometry/circlefrom3/

// Circle.h: interface for the Circle class.
// Circle class.
// Purpose : Represent the circle object
// Input : 3 different points
// Process : Calcuate the radius and center
// Output : Circle
//           
// This class originally designed for representation of discretized curvature information 
// of sequential pointlist  
// KJIST CAD/CAM     Ryu, Jae Hun ( ryu@geguri.kjist.ac.kr)
// Last update : 1999. 7. 4

#pragma once


#include "ofMain.h"


class Circle
{
public:
    /// \brief Create default circle with position 0, 0 and radius 0.
	Circle();

    /// \brief Create a circle with the given center and radius.
    /// \param center The center of the circle.
    /// \param radius The radius of the circle.
    Circle(const glm::vec2& center, float radius);

    /// \brief Destroy the Circle.
    virtual ~Circle();

    /// \returns the radius of the Circle.
    float radius();

    /// \returns the center of the Circle.
	glm::vec2 center();

    /// \brief Create a circle from three co-planar points.
    /// \param p1 co-planar point 1.
    /// \param p2 co-planar point 2.
    /// \param p3 co-planar point 3.
    /// \param circle The circle to create.
    /// \param epsilon T
    /// \returns true if a valid Circle was created.
    static bool fromPoints(const glm::vec2& p1,
                           const glm::vec2& p2,
                           const glm::vec2& p3,
                           Circle& circle,
                           float epsilon = DEFAULT_EPSILON);

    /// \brief Default epsilon.
    static const float DEFAULT_EPSILON;

private:
    /// \returns true if the three points lie on a plane.
    static bool _isPerpendicular(const glm::vec2& pt1,
                                 const glm::vec2& pt2,
                                 const glm::vec2& pt3,
                                 float epsilon = DEFAULT_EPSILON);

    static bool _calcCircle(const glm::vec2& pt1,
                            const glm::vec2& pt2,
                            const glm::vec2& pt3,
                            Circle& circle,
                            float epsilon = DEFAULT_EPSILON);

    /// \brief The Circle center.
    glm::vec2 _center;


    /// \brief The Circle radius.
    float _radius = 0;

};
