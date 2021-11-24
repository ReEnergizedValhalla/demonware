file(GLOB_RECURSE SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h *inl)

add_library(T6 STATIC
    ${SRC}
)

add_virtual_path(T6)
set_target_properties(T6 PROPERTIES LINKER_LANGUAGE CXX)
