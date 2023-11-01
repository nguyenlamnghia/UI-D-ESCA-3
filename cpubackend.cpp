#include "cpubackend.h"
#include<QDebug>

std::tuple<unsigned int, unsigned int> CpuBackend::readFile() {
    char line[40];
    unsigned int total_now = 0, user_now = 0, pos = 0;

    QString filename = "/proc/stat";
    QFile file(filename);

    //Tries to open the file else throws error.
    if(file.open(QIODevice::ReadOnly)) {
        file.readLine(line, 40);
        char* str = strtok(line," ");
        while (str != nullptr) {
            total_now += std::strtoul(str, nullptr, 0);
            if(pos < 4) user_now += std::strtoul(str, nullptr, 0);
            str = strtok(nullptr, " ");
            pos++;
        }
        return std::make_tuple(user_now, total_now);
    } else {
        throw file.error();
    }

}


CpuBackend::CpuBackend(QObject *parent) : QObject(parent) {


    std::tuple<unsigned int, unsigned int> tuple = readFile();
    user = std::get<0>(tuple);
    total = std::get<1>(tuple);

    m_timer.setInterval(3);
    m_timer.setSingleShot(false);
    m_timer.start(1000);
    connect(&m_timer, &QTimer::timeout, this, [this]() {
        unsigned int total_now = 0, user_now = 0;
        std::tuple<unsigned int, unsigned int> tuple = readFile();
        user_now = std::get<0>(tuple);
        total_now = std::get<1>(tuple);
        unsigned int user_over_period = user_now - user, total_over_period = total_now - total;
        cpu_m_steps = static_cast<double>(user_over_period)/total_over_period * 100;
        cpu_usage = cpu_m_steps;
        total = total_now;
        user = user_now;

        cpuChanged();
    });
}

int CpuBackend::cpuPercentage() const { return (cpu_m_steps-50); }

QString CpuBackend::cpuText() const {
    return QString::number(cpu_usage) + "%";
}
