include_directories(${PROJECT_SOURCE_DIR}/include)

# array
add_executable(N01 array/N01.cpp)
target_link_libraries(N01 IncludeLib)

# dp
add_executable(N52 dp/N52.cpp)
target_link_libraries(N52 IncludeLib)

# hash
add_executable(N34 hash/N34.cpp)
target_link_libraries(N34 IncludeLib)

# string
add_executable(N02 string/N02.cpp)
target_link_libraries(N02 IncludeLib)

add_executable(N27 string/N27.cpp)
target_link_libraries(N27 IncludeLib)

add_executable(N43 string/N43.cpp)
target_link_libraries(N43 IncludeLib)

add_executable(N44 string/N44.cpp)
target_link_libraries(N44 IncludeLib)

add_executable(N49 string/N49.cpp)
target_link_libraries(N49 IncludeLib)
