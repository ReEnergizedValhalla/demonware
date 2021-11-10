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

file(GLOB_RECURSE SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h *.inl)

add_library(demonware STATIC
    ${SRC}
)

add_virtual_path(demonware)
