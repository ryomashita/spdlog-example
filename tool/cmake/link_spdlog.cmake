
# プロジェクト内で spdlog をビルドする場合
function(fetch_spdlog)
    include(FetchContent)
    FetchContent_Declare(
      spdlog
      URL https://github.com/gabime/spdlog/archive/refs/tags/v1.14.1.zip
          DOWNLOAD_EXTRACT_TIMESTAMP OFF)
    FetchContent_MakeAvailable(spdlog)
endfunction()

# プロジェクトの外部でビルドした spdlog を使用する場合
function(find_spdlog)
    # your spdlog path
    set(spdlog_DIR "$ENV{HOME}/.local/spdlog/build")
    if(NOT TARGET spdlog)
        # Stand-alone build
        find_package(spdlog REQUIRED)
    endif()
endfunction()

fetch_spdlog()

function(link_spdlog target)
    target_link_libraries(${target} PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)
endfunction()
