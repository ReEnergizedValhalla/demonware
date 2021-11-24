cmake_minimum_required(VERSION 3.20)
project(demonware LANGUAGES C CXX)

# source_group following the directory hierarchy
function(add_virtual_path target_name)
    get_target_property(target_sources  "${target_name}" SOURCES)
    foreach(file_name IN LISTS target_sources)
        get_filename_component(dir_name "${file_name}" PATH)
        string(REPLACE "/" "\\" group_name "${dir_name}")
        source_group("${group_name}" FILES "${file_name}")
    endforeach()
endfunction()

add_subdirectory(src)
