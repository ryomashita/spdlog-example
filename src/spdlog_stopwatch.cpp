#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/stopwatch.h>

#include <thread>

int main() {
  spdlog::stopwatch sw; // オブジェクト生成時に timer start
  sw.reset();           // reset the stopwatch

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  spdlog::info("Elapsed time: {} milliseconds", sw.elapsed_ms().count());
}