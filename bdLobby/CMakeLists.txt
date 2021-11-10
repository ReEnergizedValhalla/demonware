add_library(bdLobby STATIC
    bdRemoteTaskManager/bdRemoteTask.h
    bdRemoteTaskManager/bdRemoteTask.cpp
)

create_target_directory_groups(bdLobby)

target_compile_options(bdLobby PUBLIC
                                        #/Zi
										/arch:SSE2
										/fp:fast           # fast floating point
										/errorreport:none
                                        /Od
										#/Ob2
										/Oi               # intrinsic functions
										/Oy               # supress frame pointer
										/Ot               # use faster code
										/GT               # tls
										#/W4
										/Gy              # function level linking
										/GF              # string pooling
										#/WX
                                        /utf-8
        )

target_compile_definitions(bdLobby PUBLIC
    "_DEBUG"
    "WIN32;"
    "_WINDOWS;"
    "_CRT_SECURE_NO_WARNINGS;"
    "NDEBUG;"
    "DEVELOPMENT;"
)

target_link_options(bdLobby PUBLIC
    /NOLOGO;
    /STACK:8388608;
    /DEBUG
    #/MACHINE:X86;
    /SUBSYSTEM:WINDOWS;
    /DYNAMICBASE:NO;
    /INCREMENTAL:NO)