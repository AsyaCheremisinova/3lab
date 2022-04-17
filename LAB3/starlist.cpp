#include "starlist.h"
#include <QDebug>

StarList::StarList(QObject* parent):QAbstractListModel(parent)
{
    add("Альферац","Андромеда",2,"96,87 световых лет","+29‪°5′26″");
    add("Поллукс","Близнецы",1,"33,78 световых лет","+28‪°1′34″");
    add("Алиот","Большая Медведица",2,"82,52 световых лет","+55°57");
}
StarList::~StarList()
{}

int StarList::rowCount(const QModelIndex&) const
{
    return listOfStars.size();
}


QVariant StarList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfStars.size())
            return QVariant();
      {
        switch (role) {
                case name:
                    return QVariant(listOfStars.at(index.row()).Name());
                case constellation:
                    return QVariant(listOfStars.at(index.row()).Сonstellation());
                case apparentMagnitude:
                    return QVariant(listOfStars.at(index.row()).ApparentMagnitude());
                case distance:
                    return QVariant(listOfStars.at(index.row()).DistanceFromEarth());
                case coordinates:
                    return QVariant(listOfStars.at(index.row()).Coordinates());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> StarList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[name] = "nameOfStar";
    roles[constellation] = "constellationOfStar";
    roles[apparentMagnitude] = "apparentMagnitudeOfStar";
    roles[distance] = "distanceOfStar";
    roles[coordinates] = "coordinatesOfStar";
       return roles;
}

void StarList::add(const QString& Name, const QString& Constellation, const int ApparentMagnitude, const QString& DistanceFromEarth, const QString& Coordinates)
{
    Star star;
    star.SetName(Name);
    star.SetСonstellation(Constellation);
    star.SetApparentMagnitude(ApparentMagnitude);
    star.SetDistance(DistanceFromEarth);
    star.SetCoordinates(Coordinates);

    beginInsertRows(QModelIndex(),listOfStars.size(),listOfStars.size());
    listOfStars.append(star);  //добавление в конец списка
    endInsertRows();

}

QAbstractListModel* StarList::getModel(){
    return this;
}

void StarList::del(const int index){

     if (index >= 0 && index < listOfStars.size())
     {

    // сообщение модели о процессе удаления данных
         beginRemoveRows(QModelIndex(), index, index);
        listOfStars.removeAt(index);
              endRemoveRows();
     }
     else qDebug() << "Error index";

}

void StarList::edit( const QString& Name, const QString& Constellation, const int ApparentMagnitude, const QString& DistanceFromEarth, const QString& Coordinates, const int index) {
     if(index >= 0 && index < listOfStars.size() )
     {
        auto& currentStar = listOfStars[index];
        if (currentStar.Name().compare(Name)!=0 || currentStar.Сonstellation().compare(Constellation)!=0 ||currentStar.ApparentMagnitude()!=0 ||currentStar.DistanceFromEarth().compare(DistanceFromEarth)!=0 ||currentStar.Coordinates().compare(Coordinates)!=0)
        {
            currentStar.SetName(Name);
            currentStar.SetСonstellation(Constellation);
            currentStar.SetApparentMagnitude(ApparentMagnitude);
            currentStar.SetDistance(DistanceFromEarth);
            currentStar.SetCoordinates(Coordinates);

            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
           // qDebug() << listOfStars[index].getNumberBibl();
        }

     }
      else qDebug() << "Error index";
}
int StarList::find(const int count)
{
    int kol = 0;
    for(int i = 0; i<listOfStars.size();i++)
    {
        if(listOfStars[i].ApparentMagnitude() > count)
        {
            kol++;
        }
    }
    return kol;
}
