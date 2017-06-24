#include "log.hpp"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/sinks/dist_sink.h"
#include "spdlog/fmt/ostr.h"

#ifdef _WIN32

#include <spdlog/sinks/wincolor_sink.h>

#if defined (_DEBUG) && defined(_MSC_VER)

#include <spdlog/sinks/msvc_sink.h>

#endif // _DEBUG && _MSC_VER

#else

#include <spdlog/sinks/ansicolor_sink.h>

#endif

namespace Log {

  Logger::Logger(const string& section) {
    section_ = section;
  }

  auto create_spdlog() {

#ifdef _WIN32
    auto color_sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
#else
    auto color_sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
#endif

    auto dist_sink = make_shared<spdlog::sinks::dist_sink_st>();
    dist_sink->add_sink(color_sink);

#if defined (_DEBUG) && defined(_MSC_VER)
    auto debug_sink = make_shared<spdlog::sinks::msvc_sink_st>();
    dist_sink->add_sink(debug_sink);
#endif // _DEBUG && _MSC_VER

    return spdlog::details::registry::instance().create("console", dist_sink);
  }

  std::shared_ptr<spdlog::logger> Logger::spdlog() {

    auto logger = spdlog::get("console");

    if (logger == nullptr) {
      logger = create_spdlog();
    }

    return logger;
  }

}
