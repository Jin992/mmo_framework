#include <array>

enum class PositionE{
    x = 0,
    y = 1,
    z = 2
};

enum class RotationE{
    pitch = 0,
    roll = 1,
    yaw = 2
};

enum class VelocityE{
    vx = 0,
    vy = 1,
    vz = 2
};

using MotionVector = std::array<int, 3>;

class Motion {
public:
    Motion()
    : {0,0,0}
    , {0,0,0} 
    , {0,0,0}
    {}

    Motion(const MotionVector &position, const MotionVector &rotation, const MotionVector &velocity)
    : m_position(position), m_rotation(rotation), m_velocity(velocity)
    {}

    void setPosition(const MotionVector &position) { m_position = position; }
    void setRotation(const MotionVector &rotation) { m_rotation = rotation; }
    void setVelocity(const MotionVector &velocity) { m_velocity = velocity; }

    MotionVector getPosition() const { return m_position; }
    MotionVector getRotation() const { return m_rotation; }
    MotionVector getVelocity() const { return m_velocity; }

private:
    MotionVector m_position;
    MotionVector m_rotation;
    MotionVector m_velocity;
};