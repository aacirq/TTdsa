include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(N01 array/N01.cpp)
target_link_libraries(N01 IncludeLib)

add_executable(N02 string/N02.cpp)
target_link_libraries(N02 IncludeLib)

add_executable(N27 string/N27.cpp)
target_link_libraries(N27 IncludeLib)
