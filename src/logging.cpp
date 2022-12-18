#include "logging.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace ov
{
    std::shared_ptr<spdlog::logger> Logging::s_coreConsoleLogger;

    void Logging::Init()
    {
        s_coreConsoleLogger = spdlog::stdout_color_mt("OwlViewer");
        s_coreConsoleLogger->set_level(spdlog::level::trace);
    }
} // namespace ov