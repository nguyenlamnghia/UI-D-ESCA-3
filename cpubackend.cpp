#include "cpubackend.h"
#include<QDebug>

#include <QStorageInfo>
#include <QDebug>

void printRootDriveInfo() {
    QStorageInfo storage = QStorageInfo::root();

    qDebug() << storage.rootPath();
    if (storage.isReadOnly())
        qDebug() << "isReadOnly:" << storage.isReadOnly();

    qDebug() << "name:" << storage.name();
    qDebug() << "filesystem type:" << storage.fileSystemType();
    qDebug() << "size:" << storage.bytesTotal()/1024/1024 << "MB";
    qDebug() << "free space:" << storage.bytesAvailable()/1024/1024 << "MB";
}


// Some func for ram
int CpuBackend::parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}
double CpuBackend::getRam(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/meminfo", "r");
    int memFree = -1;
    int memTotal = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "MemFree:", 6) == 0){
            memFree = parseLine(line);
        }
        if (strncmp(line, "MemTotal:", 6) == 0){
            memTotal = parseLine(line);
        }
    }
    fclose(file);
    return static_cast<double>(memTotal-memFree)/memTotal * 100;
}

double CpuBackend::getCpu()
{
    double percent;
    FILE* file;
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;

    file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow,
           &totalSys, &totalIdle);
    fclose(file);

    if (totalUser < lastTotalUser || totalUserLow < lastTotalUserLow ||
        totalSys < lastTotalSys || totalIdle < lastTotalIdle){
        //Overflow detection. Just skip this value.
        percent = -1.0;
    }
    else{
        total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow) +
                (totalSys - lastTotalSys);
        percent = total;
        total += (totalIdle - lastTotalIdle);
        percent /= total;
        percent *= 100;
    }

    lastTotalUser = totalUser;
    lastTotalUserLow = totalUserLow;
    lastTotalSys = totalSys;
    lastTotalIdle = totalIdle;

    return percent;
}
// end

CpuBackend::CpuBackend(QObject *parent) : QObject(parent) {
    m_timer.setInterval(3);
    m_timer.setSingleShot(false);
    m_timer.start(1000);
    connect(&m_timer, &QTimer::timeout, this, [this]() {

        // For cpu
        cpu_m_steps = getCpu();
        cpu_usage = cpu_m_steps;

        // For ram
        ram_m_steps = getRam();
        ram_usage = ram_m_steps;

        // For disk
        printRootDriveInfo();



        // Both
        cpuChanged();
        ramChanged();
    });
}

int CpuBackend::cpuPercentage() const { return (cpu_m_steps-50); }

QString CpuBackend::cpuText() const {
    return QString::number(cpu_usage) + "%";
}

int CpuBackend::ramPercentage() const { return (ram_m_steps-50); }

QString CpuBackend::ramText() const {
    return QString::number(ram_usage) + "%";
}
