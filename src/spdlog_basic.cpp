#include <spdlog/spdlog.h>

// spdlog basic example
// std::format (fmt) 準拠のフォーマット指定子を使用する。
// 改行文字は自動で追加される。
// ログは stdout に出力される (default logger: stdout_color_mt)

int main() {
  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);
  spdlog::info("Positional args are {1} {0}..", "too", "supported");

  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::info("{:<30}", "left aligned");
  spdlog::critical(
      "Support for int: {0:d};  hex: {0:#x};  oct: {0:o}; bin: {0:#b}", 42);
  spdlog::info("Support for floats {:03.2f}", 1.23456);

  spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  spdlog::debug("This message should be displayed..");

  // change log pattern
  spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
  spdlog::warn("This log message has a custom format");

  // Compile time log levels
  // Note that this does not change the current log level, it will only
  // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
  SPDLOG_TRACE("Some trace message with param {}", 42);
  SPDLOG_DEBUG("Some debug message");
}
