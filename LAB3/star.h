#ifndef STAR_H
#define STAR_H

#include <QObject>

class Star
{
public:
    Star();
    //virtual ~Star();

    QString ID() const;
    QString Name() const;
    QString Сonstellation() const;
    int ApparentMagnitude() const;
    QString DistanceFromEarth() const;
    QString Coordinates() const;

    void SetID(const QString &ID);
    void SetName(const QString &Name);
    void SetСonstellation(const QString &Value);
    void SetApparentMagnitude(const int ApparentMagnitude);
    void SetDistance(const QString &DistanceFromEarth);
    void SetCoordinates(const QString &Coordinates);

    static QStringList getСonstellations();

private:
    QString id;
    QString name;
    QString constellation;
    int apparentMagnitude;
    QString distance;
    QString coordinates;

};

#endif // STAR_H
