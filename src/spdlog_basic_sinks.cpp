#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h> // 他のヘッダファイルを include する場合でも include する必要がある

#include <iostream>

constexpr auto kLoggerNameStdout = "console";
constexpr auto kLoggerNameStderr = "stderr";
constexpr auto kLoggerNameFile = "basic_logger";

namespace {
std::shared_ptr<spdlog::logger> stdout_logger;
}

void stdout_example() {
  // create a color multi-threaded logger
  stdout_logger = spdlog::stdout_color_mt(kLoggerNameStdout);
  auto err_logger = spdlog::stderr_color_mt(kLoggerNameStderr);
}

void basic_logfile_example() {
  try {
    // CWD に logs/basic-log.txt というファイルを作成し、ログを出力する
    // default では、既存ファイルに追記される (append mode)
    auto logger =
        spdlog::basic_logger_mt(kLoggerNameFile, "logs/basic-log.txt");
    logger->info("basic_logger created");
  } catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
  }
}

int main() {
  stdout_example();
  basic_logfile_example();

  // logger はファクトリメソッドの返り値 std::shared_ptr<logger> か、
  // spdlog::get(logger_name) でグローバルに取得できる
  stdout_logger->info("logging into stdout. logger name: {}",
                      stdout_logger->name());
  spdlog::get(kLoggerNameStderr)->error("logging into stderr.");
  spdlog::get(kLoggerNameFile)
      ->info("logging into file {}", "logs/basic-log.txt");
}
