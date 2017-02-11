#include "Circle.h"


const float Circle::DEFAULT_EPSILON = 0.0001;


Circle::Circle(): Circle(glm::vec2(0, 0), 0)
{
}


Circle::Circle(const glm::vec2& center, float radius):
    _center(center),
    _radius(radius)
{
}


bool Circle::fromPoints(const glm::vec2& pt1,
                        const glm::vec2& pt2,
                        const glm::vec2& pt3,
                        Circle& circle,
                        float epsilon)
{
    if (!_isPerpendicular(pt1, pt2, pt3, epsilon))
    {
        return _calcCircle(pt1, pt2, pt3, circle, epsilon);
	}
    else if (!_isPerpendicular(pt1, pt3, pt2, epsilon))
    {
        return _calcCircle(pt1, pt3, pt2, circle, epsilon);
    }
    else if (!_isPerpendicular(pt2, pt1, pt3, epsilon))
    {
        return _calcCircle(pt2, pt1, pt3, circle, epsilon);
    }
    else if (!_isPerpendicular(pt2, pt3, pt1, epsilon))
    {
        return _calcCircle(pt2, pt3, pt1, circle, epsilon);
    }
    else if (!_isPerpendicular(pt3, pt2, pt1, epsilon))
    {
        return _calcCircle(pt3, pt2, pt1, circle, epsilon);
    }
    else if (!_isPerpendicular(pt3, pt1, pt2, epsilon))
    {
        return _calcCircle(pt3, pt1, pt2, circle, epsilon);
    }
    else
    {
        return false;
	}
}


Circle::~Circle()
{
}


glm::vec2 Circle::center()
{
    return _center;
}


float Circle::radius()
{
    return _radius;
}


bool Circle::_isPerpendicular(const glm::vec2& pt1,
                              const glm::vec2& pt2,
                              const glm::vec2& pt3,
                              float epsilon)
{
    // Check the given point are perpendicular to x or y axis 

    glm::vec2 dA = pt2 - pt1; // delta line A
    glm::vec2 dB = pt3 - pt2; // delta line B
	// checking whether the line of the two pts are vertical
    
	if (fabs(dA.x) <= epsilon && fabs(dB.y) <= epsilon)
    {
		ofLogVerbose("Circle::_isPerpendicular") << "Circle: The points are pependicular and parallel to x-y axis.";
		return false;
	}

    
	if (std::fabs(dA.y) <= epsilon)
    {
        ofLogVerbose("Circle::_isPerpendicular") << "Circle: A line of two point are perpendicular to x-axis 1.";
		return true;
	}
    else if (std::fabs(dB.y) <= epsilon)
    {
        ofLogVerbose("Circle::_isPerpendicular") << "Circle: A line of two point are perpendicular to x-axis 2.";
		return true;
	}
    else if (std::fabs(dA.x)<= epsilon)
    {
        ofLogVerbose("Circle::_isPerpendicular") << "Circle: A line of two point are perpendicular to y-axis 1.";
		return true;
	}
    else if (std::fabs(dB.x)<= epsilon)
    {
        ofLogVerbose("Circle::_isPerpendicular") << "Circle: A line of two point are perpendicular to y-axis 2.";
		return true;
	}
    else
    {
        // it just isn't.  passed the tests
        return false;   
    } 
}

bool Circle::_calcCircle(const glm::vec2& pt1,
                         const glm::vec2& pt2,
                         const glm::vec2& pt3,
                         Circle& circle,
                         float epsilon)
{
    glm::vec2 dA = pt2 - pt1;
    glm::vec2 dB = pt3 - pt2;
	
    if (std::fabs(dA.x) <= epsilon && std::fabs(dB.y) <= epsilon)
    {
		circle._center.x = 0.5f * (pt2.x + pt3.x);
		circle._center.y = 0.5f * (pt1.y + pt2.y);
        circle._radius = glm::distance(circle._center, pt1);
        return true;
	}
	
	// isPerpendicular() assure that xDelta(s) are not zero
	float mA = dA.y / dA.x; // 
	float mB = dB.y / dB.x;

	if (std::fabs(mA - mB) <= epsilon)
    {
        // checking whether the given points are colinear. 	
        circle._radius = 0;
		return false;
	}

	// calc center
    circle._center.x = mA * mB * ( pt1.y - pt3.y );
    circle._center.x += mB * ( pt1.x + pt2.x );
    circle._center.x -= mA * ( pt2.x + pt3.x );
    circle._center.x /= ( 2.0f * ( mB - mA ) );
    
	circle._center.y = -1.0f * (circle._center.x - (pt1.x + pt2.x) / 2.0f ) / mA;
    circle._center.y += ( pt1.y + pt2.y ) / 2.0f;
    
    circle._radius = glm::distance(circle._center, pt1);

    return true;
}
