#include "FormatTime.h"

std::string Log::FormatTime::getCurrentTime(int format) {
    const auto now = std::chrono::system_clock::now();
    auto t = std::chrono::system_clock::to_time_t(now);
    const auto nowMs = std::chrono::duration_cast<std::chrono::microseconds>(
            now.time_since_epoch()) % 100000;
    auto tm = localtime(&t);
    char buffer[100];
    if(format == 0) {
        strftime (buffer,100,"%F %T",tm);
    } else {
        strftime (buffer,100,"%F_%T",tm);
    }
    std::string time(buffer);
    time.append(".");
    time.append(std::to_string(nowMs.count()));
    return time;
}
