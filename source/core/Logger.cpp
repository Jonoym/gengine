#include <core/Logger.h>

bool Gengine::InitialiseLogging()
{
    return true;
}

void Gengine::ShutdownLogging()
{
}

void Gengine::LogOutput(LogLevel level, const std::string& location, const char* message, ...) {
    const std::string levelStrings[6] = {
        "[FATAL]",
        "[ERROR]",
        "[WARN ]",
        "[INFO ]",
        "[DEBUG]",
        "[TRACE]"
    };

    char outMessage[32000];
    va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(outMessage, sizeof(outMessage), message, arg_ptr);
    va_end(arg_ptr);

    std::string formattedMessage = levelStrings[static_cast<int>(level)] + location + ": " + outMessage;

    std::cout << formattedMessage << std::endl;
}