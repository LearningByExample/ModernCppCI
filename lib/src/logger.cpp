/*
 *  Distributed under the MIT License (See accompanying file /LICENSE )
 */
#include "logger.h"
#include <spdlog/sinks/dist_sink.h>

#ifdef _WIN32
#include <spdlog/sinks/wincolor_sink.h>
#else
#include <spdlog/sinks/ansicolor_sink.h>
#endif

#if defined(_DEBUG) && defined(_MSC_VER)
#include <spdlog/sinks/msvc_sink.h>
#endif  // _DEBUG && _MSC_VER

namespace ModernCppCI {

auto create_spdlog() {
#ifdef _WIN32
  auto color_sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
#else
  auto color_sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
#endif

  auto dist_sink = std::make_shared<spdlog::sinks::dist_sink_st>();
  dist_sink->add_sink(color_sink);

#if defined(_DEBUG) && defined(_MSC_VER)
  auto debug_sink = std::make_shared<spdlog::sinks::msvc_sink_st>();
  dist_sink->add_sink(debug_sink);
#endif  // _DEBUG && _MSC_VER

  return spdlog::details::registry::instance().create("console", dist_sink);
}

Logger::Logger(const std::string &section) : section_{section} {
  internal_logger_ = spdlog::get("console");

  if (internal_logger_ == nullptr) {
    internal_logger_ = create_spdlog();
  }
}

}  // namespace ModernCppCI
