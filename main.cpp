#include <iostream>
#include <cstring>
#include <chrono>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <sys/time.h>
#include <stdarg.h>

#include "src/AsyncLog.h"
#include "src/LogFile.h"
#include "src/LogStream.h"
#include "src/logging.h"

using namespace std;
using namespace chrono;

//void testAsyncLog() {
//    AsyncLog log;
//    log.start();
//    char out[] = "hello world33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333\n";
//    int size = sizeof(out);
//    int length = 10000000;
//    auto start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < length; ++i) {
//        log.append(out, sizeof(out));
//    }
//    auto stop = std::chrono::high_resolution_clock::now();
//    log.stop();
//    auto use = duration_cast<std::chrono::microseconds>(stop - start).count();
////    cout << "use time: " << use << " us\n";
////    cout << "bytes :" << size *  length << "bits\n";
//    cout << "Speed: " << fixed << setprecision(3)  << double(size * length) / (1000 * 1000 * 1024)  <<  " Mib/s\n";
//}

//std::string testTimeFormat() {
//    time_t now;
//
//    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//    auto tm = localtime(&t);
//    std::string time;
//    time.append(std::to_string(tm->tm_year + 1900));
//    time.append("_");
//    time.append(std::to_string(tm->tm_mon + 1));
//    time.append("_");
//    time.append(std::to_string(tm->tm_mday));
//    time.append("_");
//    time.append(std::to_string(tm->tm_hour));
//    time.append("_");
//    time.append(std::to_string(tm->tm_min));
//    time.append("_");
//    time.append(std::to_string(tm->tm_sec));
//    return time;
//}

std::string testTimeFormatChr() {

}

//void testTimeFormat() {
//    std::cout << "Start Log Test!" << std::endl;
//    std::string ret = testTimeFormat();
//    cout << "get Format Time: " << ret << endl;
//
//    struct timeval tv;
//    ::gettimeofday(&tv, nullptr);
//    cout << "s: " << tv.tv_sec << " us: " << tv.tv_usec << endl;
//    time_t value = time(NULL);
//    cout << "s: " << value << endl;
//}

void testLogfile() {
    LogFile file("LogFile.txt", 1000 * 1000);
    char out[] = "hello world33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333\n";
    int size = sizeof(out);
    int length = 10000;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < length; ++i) {
        file.append(out, sizeof(out));
    }
    file.flush();
    auto stop = std::chrono::high_resolution_clock::now();
    auto use = duration_cast<std::chrono::microseconds>(stop - start).count();
    cout << "use time: " << use << " us\n";
    cout << "bytes :" << size *  length << "bits\n";
    cout << "Speed: " << fixed << setprecision(3)  << double(size * length) / (1000 * 1000 * 1024)  <<  " Mib/s\n";
}

void testStream() {
    LogStream logStream;
    logStream << "hello" << 10 << 11.8 << string("you") << " " << true;
    logStream << std::string("hello world********");
    logStream << "hello world********";
    std::string ret = logStream.getData();
    cout << ret << endl;
}

void testLog() {
    Log::Logging logging;
    logging.init();
    logging.setLogLevel(Log::Level::DEBUG);
    Log::LOG_INFO << "hello world ***************************************************************************************************************************";
    Log::LOG_WARNING << "hello world ***************************************************************************************************************************";
    Log::LOG_DEBUG << "hello world ***************************************************************************************************************************";
    Log::LOG_ERROR << "hello world ***************************************************************************************************************************";
    Log::LOG_FATAL << "hello world ***************************************************************************************************************************";
};

int main() {
    testLog();
    return 0;
}
