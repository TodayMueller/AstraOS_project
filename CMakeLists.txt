cmake_minimum_required(VERSION 3.28.1)
project(baseAlt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    json 
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    CURL
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG        curl-8_6_0
)
FetchContent_MakeAvailable(CURL)

add_library(mylib SHARED
	lib_src/branchAnalysis.cpp
)

target_include_directories(mylib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/lib_src
)

find_package(CURL REQUIRED)

target_link_libraries(mylib
    PUBLIC
        CURL::libcurl
        nlohmann_json::nlohmann_json
)

add_executable(baseAlt 
    cli_src/main.cpp
)

target_link_libraries(baseAlt 
    PRIVATE 
        mylib
)
