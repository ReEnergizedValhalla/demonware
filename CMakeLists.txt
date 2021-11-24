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
link_directories(external/openssl/lib)

# source_group following the directory hierarchy
function(add_virtual_path target_name)
    get_target_property(target_sources  "${target_name}" SOURCES)
    foreach(file_name IN LISTS target_sources)
        get_filename_component(dir_name "${file_name}" PATH)
        string(REPLACE "/" "\\" group_name "${dir_name}")
        source_group("${group_name}" FILES "${file_name}")
    endforeach()
endfunction()

include_directories(. 
    external/libtomcrypt/src/headers 
    external/curl/include 
    external/openssl/include)

file(GLOB_RECURSE SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h *.inl)
list(FILTER SRC EXCLUDE REGEX "external[\r\n\t ]*build")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

add_executable(demonware WIN32
    ${SRC}
)

target_compile_definitions(demonware PUBLIC
    "_DEBUG"
    "_WINDOWS;"
    "_CRT_SECURE_NO_WARNINGS;")

target_link_libraries(demonware libeay32.lib ssleay32.lib ws2_32.lib)

add_virtual_path(demonware)
