add_executable(space-pirates
    Main.h
    Main.cpp
    )

target_include_directories(space-pirates PUBLIC
    "${CMAKE_CURRENT_SCOURE_DIR}/levels"
)

target_link_libraries(space-pirates PRIVATE WarpEngine)
