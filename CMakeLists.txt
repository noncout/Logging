cmake_minimum_required(VERSION 3.10)
project(Logging)

set(CMAKE_CXX_STANDARD 14)

add_executable(Logging main.cpp
        src/logging.h
        src/FormatTime.cpp
        src/FormatTime.h
        src/LogStream.cpp
        src/LogStream.h
        src/AsyncLog.cpp
        src/AsyncLog.h
        src/CountDownLatch.cpp
        src/CountDownLatch.h
        src/noncopyable.h
        src/FileUtil.cpp
        src/FileUtil.h
        src/LogFile.cpp
        src/LogFile.h
        src/Singletion.h)

target_link_libraries(Logging pthread)

#add_subdirectory(./test)