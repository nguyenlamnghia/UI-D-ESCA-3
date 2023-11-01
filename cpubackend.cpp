#include "cpubackend.h"
#include<QDebug>


// Some func for ram
int parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}
double getValue(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/meminfo", "r");
    int memUsage = -1;
    int memTotal = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "MemAvailable:", 6) == 0){
            memUsage = parseLine(line);
        }
        if (strncmp(line, "MemTotal:", 6) == 0){
            memTotal = parseLine(line);
        }
    }
    fclose(file);
    return static_cast<double>(memUsage)/memTotal * 100;
}

static unsigned long long lastTotalUser, lastTotalUserLow, lastTotalSys, lastTotalIdle;
double CpuBackend::getCurrentValueRam()
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

// some func for cpu
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

        // For cpu
        unsigned int total_now = 0, user_now = 0;
        std::tuple<unsigned int, unsigned int> tuple = readFile();
        user_now = std::get<0>(tuple);
        total_now = std::get<1>(tuple);
        unsigned int user_over_period = user_now - user, total_over_period = total_now - total;
        cpu_m_steps = static_cast<double>(user_over_period)/total_over_period * 100;
        cpu_usage = cpu_m_steps;
        total = total_now;
        user = user_now;

        // For ram
        ram_m_steps = getCurrentValueRam();
        ram_m_steps = getValue();
        ram_usage = ram_m_steps;



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
