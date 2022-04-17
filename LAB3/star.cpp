#include "star.h"

Star::Star()
{
}
void Star::SetID(const QString &ID)
{
    id = ID;
}
void Star::SetName(const QString &Name)
{
    name = Name;
}
void Star::SetСonstellation(const QString &Сonstellation)
{
 constellation = Сonstellation;
}
void Star::SetApparentMagnitude(const int ApparentMagnitude)
{
   apparentMagnitude = ApparentMagnitude;
}
void Star::SetDistance(const QString &DistanceFromEarth)
{
distance = DistanceFromEarth;
}
void Star::SetCoordinates(const QString &Coordinates)
{
coordinates = Coordinates;
}
QString Star::ID() const
{
    return id;
}
QString Star::Name() const
{
    return name;
}
QString Star::Сonstellation() const
{
    return constellation;
}
int Star::ApparentMagnitude() const
{
    return apparentMagnitude;
}
QString Star::DistanceFromEarth() const
{
    return distance;
}
QString Star::Coordinates() const
{
    return coordinates;
}
QStringList Star::getСonstellations()
{
    QStringList value;
    value.append("Андромеда");
    value.append("Близнецы");
    value.append("Большая Медведица");
    value.append("Большой Пёс");
    value.append("Весы");
    value.append("Водолей");
    value.append("Возничий");
    value.append("Волк");
    value.append("Волопас");
    return value;
}

