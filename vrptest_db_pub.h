#ifndef VRPTEST_DB_PUB_H
#define VRPTEST_DB_PUB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class vrptest_DB_Pub : public QObject
{
    Q_OBJECT
public:
    explicit vrptest_DB_Pub(QObject *parent = 0);

    void Initialization();




signals:

public slots:
};

#endif // VRPTEST_DB_PUB_H
