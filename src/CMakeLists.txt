add_library(Add add.cpp)
set_normal_compile_options(Add)
set_warnings_as_errors(Add)

add_executable(spdlog_basic spdlog_basic.cpp)
link_spdlog(spdlog_basic)