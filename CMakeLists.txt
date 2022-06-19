cmake_minimum_required(VERSION 3.8)

# Set your project name here
project(Soundboard CXX)

include_directories(
        "${PROJECT_SOURCE_DIR}/deps/imgui"
        "${PROJECT_SOURCE_DIR}/deps/imgui/backends"
)

if (WIN32)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(PROJECT_ARCH x64)
    else ()
        set(PROJECT_ARCH x86)
    endif ()
endif ()

file (GLOB srcFiles
	"src/*.cpp"
    "deps/imgui/*.cpp")

add_executable(Soundboard ${srcFiles})

if (BACKEND STREQUAL "sdl2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSING_SDL2")

	include_directories(
    	    "${PROJECT_SOURCE_DIR}/deps/SDL2/include"
	)

	file (GLOB srcFiles
	    "deps/imgui/backends/imgui_impl_sdl.cpp"
	    "deps/imgui/backends/imgui_impl_sdlrenderer.cpp")

    target_link_libraries(Soundboard
        SDL2main
        SDL2
        SDL2_image
    )

	link_directories(
    	    "${PROJECT_SOURCE_DIR}/deps/SDL2/lib/${PROJECT_ARCH}"
	)

	if (WIN32)
    	add_custom_command(TARGET Soundboard POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
            "${PROJECT_SOURCE_DIR}/deps/SDL2/lib/${PROJECT_ARCH}/SDL2.dll"      # <--this is in-file
            $<TARGET_FILE_DIR:Soundboard>)                 # <--this is out-file path
	endif ()
endif ()

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET Soundboard PROPERTY CXX_STANDARD 20)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(Soundboard PUBLIC -DDEBUG)
endif()

# TODO: Add tests and install targets if needed.
