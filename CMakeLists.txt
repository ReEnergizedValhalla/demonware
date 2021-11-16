cmake_minimum_required(VERSION 3.20)
project(demonware LANGUAGES CXX)

set(MASTER_PROJECT OFF)
# Determine if we're built as a subproject (using add_subdirectory)
# or if this is the master project.
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MASTER_PROJECT ON)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# source_group following the directory hierarchy
function(add_virtual_path target_name)
    get_target_property(target_sources  "${target_name}" SOURCES)
    foreach(file_name IN LISTS target_sources)
        get_filename_component(dir_name "${file_name}" PATH)
        string(REPLACE "/" "\\" group_name "${dir_name}")
        source_group("${group_name}" FILES "${file_name}")
    endforeach()
endfunction()

include_directories(.)
include_directories(external/libtomcrypt/src/headers)
include_directories(external/curl/include)
include_directories(external/openssl/include)

add_compile_options(
    /MP                      # Build with Multiple Processes
    /external:anglebrackets  # Treats all headers included by #include <header>, where the header file is enclosed in angle brackets (< >), as external headers
    /external:W0             # Sets the default warning level to 0 for external headers, effectively turning off warnings for external headers
    $<$<CONFIG:Debug>:/Zi>   # The /Zi option produces a separate PDB file that contains all the symbolic debugging information for use with the debugger.
)

file(GLOB_RECURSE SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h *.inl)

add_executable(demonware WIN32
    ${SRC}
)

target_compile_definitions(demonware PUBLIC
    "_DEBUG"
    "_WINDOWS"
    "_CRT_SECURE_NO_WARNINGS"
)

add_virtual_path(demonware)
