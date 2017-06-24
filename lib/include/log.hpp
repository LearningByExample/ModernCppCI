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

namespace Log {

  typedef enum {
    info = spdlog::level::level_enum::info,
    trace = spdlog::level::level_enum::trace,
    debug = spdlog::level::level_enum::debug,
    error = spdlog::level::level_enum::err
  } log_level;

  class Logger {
  public:
    Logger(const string& section);

    template <typename Arg1, typename... Args>
    inline void log(spdlog::level::level_enum level, const char* fmt, const Arg1 &arg1, const Args&... args) {
      string newFmt = "[{}] " + string(fmt);

      spdlog()->log(level, newFmt.c_str(), section_, arg1, args...);
    }

    template <typename Arg1, typename... Args>
    inline void info(const char* fmt, const Arg1 &arg1, const Args&... args) {
      log(spdlog::level::level_enum::info, fmt, arg1, args...);
    }

    template <typename Arg1>
    inline void info(const Arg1 &arg1) {
      info("{}", arg1);
    }

    template <typename Arg1, typename... Args>
    inline void debug(const char* fmt, const Arg1 &arg1, const Args&... args) {
      log(spdlog::level::level_enum::debug, fmt, arg1, args...);
    }

    inline void debug(const char* value) {
      debug("{}", value);
    }

    template <typename Arg1, typename... Args>
    inline void trace(const char* fmt, const Arg1 &arg1, const Args&... args) {
      log(spdlog::level::level_enum::trace, fmt, arg1, args...);
    }

    inline void trace(const char* value) {
      trace("{}", value);
    }

    template <typename Arg1, typename... Args>
    inline void error(const char* fmt, const Arg1 &arg1, const Args&... args) {
      log(spdlog::level::level_enum::err, fmt, arg1, args...);
    }

    inline void error(const char* value) {
      error("{}", value);
    }

    inline static void level(log_level level) {
      spdlog::set_level((spdlog::level::level_enum) level);
    }

  private:
    string section_;
    static std::shared_ptr<spdlog::logger> spdlog();
  };

}

#endif //LOG_HPP
