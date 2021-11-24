add_compile_options(
    /MP                      # Build with Multiple Processes
    /external:anglebrackets  # Treats all headers included by #include <header>, where the header file is enclosed in angle brackets (< >), as external headers
    /external:W0             # Sets the default warning level to 0 for external headers, effectively turning off warnings for external headers
    $<$<CONFIG:Debug>:/Zi>   # The /Zi option produces a separate PDB file that contains all the symbolic debugging information for use with the debugger.
)

add_subdirectory(T5)
add_subdirectory(T6)
