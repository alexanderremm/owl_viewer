#ifndef LOGGING_HPP
#define LOGGING_HPP
#pragma once

#include <spdlog/spdlog.h>

namespace ov
{
    class Logging
    {
    private:
        static std::shared_ptr<spdlog::logger> s_coreConsoleLogger;

    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_coreConsoleLogger; }
    };

} // namespace ov

#define OV_TRACE(...)      ::ov::Logging::GetCoreLogger()->trace(__VA_ARGS__)
#define OV_INFO(...)       ::ov::Logging::GetCoreLogger()->info(__VA_ARGS__)
#define OV_WARN(...)       ::ov::Logging::GetCoreLogger()->warn(__VA_ARGS__)
#define OV_ERROR(...)      ::ov::Logging::GetCoreLogger()->error(__VA_ARGS__)
#define OV_FATAL(...)      ::ov::Logging::GetCoreLogger()->critical(__VA_ARGS__)

#endif
