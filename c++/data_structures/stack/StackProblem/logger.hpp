#ifndef MY_LOGGER_HPP
#define MY_LOGGER_HPP

#include <iostream>
#include <string>
#include <mutex> // For thread-safety if needed

namespace MyLogger {

    // Enum for log levels
    enum class LogLevel {
        INFO,
        WARNING,
        ERROR
    };

    // Simple logger class
    class Logger {
    public:
        // Using inline to avoid ODR violation if this class is defined in the header
        inline static Logger& getInstance() {
            static Logger instance; // Guaranteed to be created once
            return instance;
        }

        inline void log(LogLevel level, const std::string& message) {
            std::lock_guard<std::mutex> lock(mtx_); // Protects shared resources (e.g., cout)
            switch (level) {
            case LogLevel::INFO:
                std::cout << "[INFO] " << message << std::endl;
                break;
            case LogLevel::WARNING:
                std::cerr << "[WARNING] " << message << std::endl;
                break;
            case LogLevel::ERROR:
                std::cerr << "[ERROR] " << message << std::endl;
                break;
            }
        }

    private:
        Logger() = default; // Private constructor for Singleton pattern
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        std::mutex mtx_; // Mutex for thread-safe logging
    };

    // Convenience macros
#define LOG_INFO(msg) MyLogger::Logger::getInstance().log(MyLogger::LogLevel::INFO, msg)
#define LOG_WARNING(msg) MyLogger::Logger::getInstance().log(MyLogger::LogLevel::WARNING, msg)
#define LOG_ERROR(msg) MyLogger::Logger::getInstance().log(MyLogger::LogLevel::ERROR, msg)

} // namespace MyLogger

#endif // MY_LOGGER_HPP
#pragma once
