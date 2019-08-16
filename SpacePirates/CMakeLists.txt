
set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
    )

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.h
    )

add_subdirectory("${PROJECT_SOURCE_DIR}/SpacePirates/levels")

add_executable(space-pirates ${SOURCE} ${HEADERS})

target_link_libraries(space-pirates PRIVATE WarpEngine)
