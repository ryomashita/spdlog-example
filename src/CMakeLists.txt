add_executable(spdlog_basic spdlog_basic.cpp)
link_spdlog(spdlog_basic)

add_executable(spdlog_basic_sinks spdlog_basic_sinks.cpp)
link_spdlog(spdlog_basic_sinks)

add_executable(spdlog_rotating spdlog_rotating.cpp)
link_spdlog(spdlog_rotating)

add_executable(spdlog_stopwatch spdlog_stopwatch.cpp)
link_spdlog(spdlog_stopwatch)

add_executable(spdlog_periodic spdlog_periodic.cpp)
link_spdlog(spdlog_periodic)