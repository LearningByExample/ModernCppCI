/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#ifndef LOG_HPP
#define LOG_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

using namespace std;

namespace ModernCppCI {

  typedef enum {
    info = spdlog::level::level_enum::info,
    trace = spdlog::level::level_enum::trace,
    debug = spdlog::level::level_enum::debug,
    error = spdlog::level::level_enum::err
  } LogLevel;

  class Logger {
  public:
    Logger(const string& section);

    auto section() const {
      return section_;
    }

    template <typename Arg1, typename... Args>
    inline void log(LogLevel level, const char* fmt, const Arg1 &arg1, const Args&... args) {
      string new_fmt = "[{}] " + string(fmt);

      spdlog()->log((spdlog::level::level_enum)level, new_fmt.c_str(), section(), arg1, args...);
    }

    template <typename Arg1, typename... Args>
    inline void info(const char* fmt, const Arg1 &arg1, const Args&... args) {
      log(LogLevel::info, fmt, arg1, args...);
    }

    template <typename Arg1>
    inline void info(const Arg1 &arg1) {
      info("{}", arg1);
    }

    template <typename Arg1, typename... Args>
    inline void debug(const char* fmt, const Arg1 &arg1, const Args&... args) {
      log(LogLevel::debug, fmt, arg1, args...);
    }

    inline void debug(const char* value) {
      debug("{}", value);
    }

    template <typename Arg1, typename... Args>
    inline void trace(const char* fmt, const Arg1 &arg1, const Args&... args) {
      log(LogLevel::trace, fmt, arg1, args...);
    }

    inline void trace(const char* value) {
      trace("{}", value);
    }

    template <typename Arg1, typename... Args>
    inline void error(const char* fmt, const Arg1 &arg1, const Args&... args) {
      log(LogLevel::error, fmt, arg1, args...);
    }

    inline void error(const char* value) {
      error("{}", value);
    }

    inline static void level(LogLevel level) {
      spdlog::set_level((spdlog::level::level_enum) level);
    }

  private:
    string section_;
    static std::shared_ptr<spdlog::logger> spdlog();
  };

}

#endif //LOG_HPP
