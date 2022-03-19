#pragma once

// TODO: Use logging framework instead of it

#include <string>
#include <sstream>
#include <iostream>

namespace logging {

enum class LogLevel {
    FATAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE
};

inline const char *level_to_string(LogLevel level) {
    switch (level) {
        case LogLevel::FATAL:
            return "FATAL";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::WARN:
            return "WARN";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::TRACE:
            return "TRACE";
        default:
            return "";
    }
}

class Logger {
    bool shifting {};
public:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger(Logger&& other): shifting(false) {}
    Logger &operator=(const Logger&) = delete;
    Logger &operator=(Logger&& other) {
        shifting = other.shifting;
        other.shifting = false;
        return *this;
    };
    ~Logger() {
        if (shifting) {
            --shift;
        }
    }

    template<typename...Types>
    inline void log(LogLevel level, Types&&... args) {
        if (!shifting) {
            ++shift;
            shifting = true;
        }
        std::cout << level_to_string(level) << ": ";
        for (int i = 0; i < shift; ++i) {
            std::cout << ' ';
        }
        ((std::cout << ' ' << std::forward<Types>(args)), ... );
        std::cout << std::endl;
    }

    template<typename...Types>
    inline void fatal(Types&&... args) {
        log(LogLevel::FATAL, std::forward<Types>(args)...);
    }

    template<typename...Types>
    inline void error(Types&&... args) {
        log(LogLevel::ERROR, std::forward<Types>(args)...);
    }

    template<typename...Types>
    inline void warn(Types&&... args) {
        log(LogLevel::WARN, std::forward<Types>(args)...);
    }

    template<typename...Types>
    inline void info(Types&&... args) {
        log(LogLevel::INFO, std::forward<Types>(args)...);
    }

    template<typename...Types>
    inline void debug(Types&&... args) {
        log(LogLevel::DEBUG, std::forward<Types>(args)...);
    }

    template<typename...Types>
    inline void trace(Types&&... args) {
        log(LogLevel::TRACE, std::forward<Types>(args)...);
    }
private:
    static int shift;
};

template<typename...Types>
inline void fatal(Types&&... args) {
    Logger().fatal(std::forward<Types>(args)...);
}

template<typename...Types>
inline void error(Types&&... args) {
    Logger().error(std::forward<Types>(args)...);
}

template<typename...Types>
inline void warn(Types&&... args) {
    Logger().warn(std::forward<Types>(args)...);
}

template<typename...Types>
inline void info(Types&&... args) {
    Logger().info(std::forward<Types>(args)...);
}

template<typename...Types>
inline void debug(Types&&... args) {
    Logger().debug(std::forward<Types>(args)...);
}

template<typename...Types>
inline void trace(Types&&... args) {
    Logger().trace(std::forward<Types>(args)...);
}

}
