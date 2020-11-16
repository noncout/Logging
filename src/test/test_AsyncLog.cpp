#include <iostream>
#include <cstring>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <sys/time.h>

#include "src/AsyncLog.h"

using namespace std;
using namespace chrono;

int main() {
    AsyncLog log;
    log.start();
    char out[] = "hello world33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333\n";
    int size = sizeof(out);
    int length = 10000000;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < length; ++i) {
        log.append(out, sizeof(out));
    }
    auto stop = std::chrono::high_resolution_clock::now();
    log.stop();
    auto use = duration_cast<std::chrono::microseconds>(stop - start).count();
    cout << "Speed: " << fixed << setprecision(3)  << double(size * length) / (1000 * 1000 * 1024)  <<  " Mib/s\n";
}
