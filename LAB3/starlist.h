#ifndef STARLIST_H
#define STARLIST_H

#include <QAbstractListModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "star.h"

class StarList :public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QAbstractListModel* starModel READ getModel CONSTANT)

private:
    QList<Star> listOfStars; // непосредственно данные
    QAbstractListModel *getModel();

public:
    StarList(QObject *parent = nullptr);
    ~StarList() override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum ResentRoles {
            name = Qt::DisplayRole,
            constellation = Qt::UserRole + 1,
            apparentMagnitude = Qt::UserRole + 2,
            distance = Qt::UserRole + 3,
            coordinates = Qt::UserRole + 4,

       };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void add(const QString& Name, const QString& Constellation, const int ApparentMagnitude, const QString& DistanceFromEarth, const QString& Coordinates);
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE void edit(const QString& Name, const QString& Constellation, const int ApparentMagnitude, const QString& DistanceFromEarth, const QString& Coordinates,const int index);
    Q_INVOKABLE int find(const int count);

};


#endif // STARLIST_H
