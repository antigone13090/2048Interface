#ifndef TEST_H
#define TEST_H

#include <QObject>
typedef int mat[4][4];

class Test: public QObject
{
    Q_OBJECT
public:
    QString init();
    Q_INVOKABLE void increment();
    Q_PROPERTY(QString a READ init NOTIFY cptChanged)
    //QString readCompteur();
signals:
    void cptChanged();

private:
    int fcompteur;
    int** grid;
};

#endif // TEST_H
