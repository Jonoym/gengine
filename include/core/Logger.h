#pragma once

#include <Types.h>
#include <iostream>
#include <string>
#include <cstdarg>

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0

typedef enum LogLevel
{
    LOG_LEVEL_FATAL,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARN,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_TRACE
} LogLevel;

namespace Gengine
{
    bool InitialiseLogging();
    void ShutdownLogging();

    void LogOutput(LogLevel level, const std::string& location, const char* message, ...);
}

#define L_FATAL(location, message, ...) LogOutput(LOG_LEVEL_FATAL, location, message, ##__VA_ARGS__);
#define L_ERROR(location, message, ...) LogOutput(LOG_LEVEL_ERROR, location, message, ##__VA_ARGS__);

#if LOG_WARN_ENABLED == 1
#define L_WARN(location, message, ...) LogOutput(LOG_LEVEL_WARN, location, message, ##__VA_ARGS__);

#else
#define L_WARN(location, message, ...)

#endif

#if LOG_INFO_ENABLED == 1
#define L_INFO(location, message, ...) LogOutput(LOG_LEVEL_INFO, location, message, ##__VA_ARGS__);

#else
#define L_INFO(location, message, ...)

#endif

#if LOG_DEBUG_ENABLED == 1
#define L_DEBUG(location, message, ...) LogOutput(LOG_LEVEL_DEBUG, location, message, ##__VA_ARGS__);

#else
#define L_DEBUG(location, message, ...)

#endif

#if LOG_TRACE_ENABLED == 1
#define L_TRACE(location, message, ...) LogOutput(LOG_LEVEL_TRACE, location, message, ##__VA_ARGS__);

#else
#define L_TRACE(location, message, ...)

#endif