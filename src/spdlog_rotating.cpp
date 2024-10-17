#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>

void rotating_example() {
  // Create a file rotating logger with size limitation.
  // 実行した場合 :
  // 1. rotating.txt にログが出力される
  // 2. rotating.txt が 1024 バイトを超えると、rotating.1.txt にリネームされる
  //    空になった rotating.txt に最新のログが出力される
  // 3. rotating.3.txt まで作成されると、次は rotating.1.txt が更新される
  auto max_size = 1024; // 1024 bytes
  auto max_files = 3;
  auto logger = spdlog::rotating_logger_mt(
      "some_logger_name", "logs/rotating.txt", max_size, max_files);
}

int main() {
  rotating_example();
  spdlog::get("some_logger_name")->info("Hello, rotating world!");
}