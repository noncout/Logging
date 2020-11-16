//
// Created by admin on 2020/10/13.
//

#ifndef LOGGING_LOGGING_H
#define LOGGING_LOGGING_H
#include <string>
#include <thread>
#include <unistd.h>
#include <sys/syscall.h>

#include "noncopyable.h"
#include "LogStream.h"
#include "LogFile.h"
#include "FormatTime.h"
#include "Singletion.h"
#include "LogStream.h"


namespace  Log {
    enum class Level {
        INFO = 4,
        DEBUG = 3,
        WARNING = 2,
        ERROR = 1,
        FATAL = 0,
    };

    class LogImpl : public LogStream {
    public:
        LogImpl(const std::shared_ptr<LogFile> & logFile) {
            logFile_ = logFile;
        }

        ~LogImpl() {
            // 每次临时对象销毁时，输出到写文件中
            if (logFile_ != nullptr) {
                *this << "\n";  // 手动写入换行符
                logFile_->append(this->getData().c_str(), getData().size());
//                printf("size : %d, content: %s\n",getData().size(), this->getData().c_str());
            }
        }

    private:
        std::shared_ptr<LogFile> logFile_;
    };

    // TODO:add level
    class Logging : public Singletion<Logging> {
        public:
        static bool init(const std::string & fileName = "logging.txt",
                uint64_t maxSize = MAXSIZE) {
            file_ptr_.reset(new LogFile(fileName, maxSize));
        }

         static void setLogLevel(Level level) {
                out_level_ = level;
         }

         static Level getLogLevel()  {
             return out_level_;
         }

         static void flush() {
             file_ptr_->flush();
         }

         static std::shared_ptr<LogFile> getLogFile() {
             return file_ptr_;
         }

        private:
            static std::shared_ptr<LogFile>  file_ptr_;  // log file
            static Level        out_level_; // bottom of output
    };

    std::shared_ptr<LogFile> Logging::file_ptr_ = nullptr;
    Level Logging::out_level_ = Level::DEBUG;

// todo:添加日志等级控制
#define LOG_INFO    LogImpl(Log::Logging::Instance()->getLogFile()) << "["<< FormatTime::getCurrentTime() << "] " << "[" <<  std::string(__FUNCTION__)  \
                    << " | " << __LINE__ << long(::syscall(SYS_gettid)) <<"] [INFO]:"

#define LOG_DEBUG   LogImpl(Log::Logging::Instance()->getLogFile()) << "["<< FormatTime::getCurrentTime() << "] "<< "[" <<  std::string(__FUNCTION__)  \
                    << " | " << __LINE__ << long(::syscall(SYS_gettid)) <<"] [DEBUG]:"

#define LOG_WARNING LogImpl(Log::Logging::Instance()->getLogFile()) << "["<< FormatTime::getCurrentTime() << "] "<< "[" <<  std::string(__FUNCTION__)  \
                << " | " << __LINE__ << long(::syscall(SYS_gettid)) <<"] [WARNING]:"

#define LOG_ERROR   LogImpl(Log::Logging::Instance()->getLogFile()) << "["<< FormatTime::getCurrentTime() << "] "<< "[" <<  std::string(__FUNCTION__)  \
                << " | " << __LINE__ << long(::syscall(SYS_gettid)) <<"] [ERROR]:"

#define LOG_FATAL   LogImpl(Log::Logging::Instance()->getLogFile()) << "["<< FormatTime::getCurrentTime() << "] "<< "[" <<  std::string(__FUNCTION__)  \
                << " | " << __LINE__ << long(::syscall(SYS_gettid)) <<"] [FATAL]:"

} // namespace Log

#endif //LOGGING_LOGGING_H
