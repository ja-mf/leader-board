#ifndef GENINFO_H
#define GENINFO_H

#include <QThread>
#include <QtWebSockets>

class GenInfo : public QThread
{
    Q_OBJECT
public:
    explicit GenInfo(QObject *parent = 0);

    //QWebSocket *pSocket;

private:
    void run();

signals:
    void enviarInfo(QString msg);
public slots:

};

#endif // GENINFO_H
