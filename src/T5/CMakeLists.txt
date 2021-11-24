file(GLOB_RECURSE SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h *inl)

add_library(T5 STATIC
    ${SRC}
)

add_virtual_path(T5)
set_target_properties(T5 PROPERTIES LINKER_LANGUAGE CXX VS_PLATFORM_TOOLSET v90)
