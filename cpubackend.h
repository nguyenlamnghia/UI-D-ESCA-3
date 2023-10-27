#ifndef CPUBACKEND_H
#define CPUBACKEND_H

#include <QObject>
#include <tuple>

#include <QObject>
#include <QQmlEngine>
#include <QTimer>
#include <QFile>

class CpuBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int percentage READ percentage NOTIFY cpuChanged)
    Q_PROPERTY(QString time READ time NOTIFY timeChanged)
//    Q_PROPERTY(bool waterActive READ waterActive NOTIFY waterActiveChanged)

public:
    explicit CpuBackend(QObject *parent = nullptr);

signals:
    void cpuChanged();
    void timeChanged();
//    void waterActiveChanged();

private:
    int percentage() const;
    QString time() const;
//    bool waterActive() const;
    QTimer m_timer;
    double m_steps = 0;
    int cpu_usage = 0;
    unsigned int user, total = 0;
    int m_direction = 1;
    std::tuple<unsigned int, unsigned int> readFile();

};

#endif // CPUBACKEND_H
