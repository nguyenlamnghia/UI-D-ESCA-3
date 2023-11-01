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
    Q_PROPERTY(int cpuPercentage READ percentage NOTIFY cpuChanged)
    Q_PROPERTY(QString cpuText READ time NOTIFY cpuChanged)

public:
    explicit CpuBackend(QObject *parent = nullptr);

signals:
    void cpuChanged();

private:
    int cpuPercentage() const;
    QString cpuText() const;
    QTimer m_timer;
    double cpu_m_steps = 0;
    int cpu_usage = 0;
    unsigned int user, total = 0;
    std::tuple<unsigned int, unsigned int> readFile();

};

#endif // CPUBACKEND_H
