add_subdirectory(converters)

# Console version
add_executable(OctoConverter main.cpp)
target_link_libraries(OctoConverter PRIVATE converters)

set_target_properties(
    OctoConverter
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}"
    WIN32_EXECUTABLE FALSE
)

# GUI version
add_executable(OctoConverterGUI WIN32 gui_main.cpp)
target_link_libraries(OctoConverterGUI PRIVATE converters imgui)

set_target_properties(
    OctoConverterGUI
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}"
)

if(WIN32)
    set_target_properties(
        OctoConverter
        PROPERTIES
        OUTPUT_NAME "OctoConverter"
    )
    set_target_properties(
        OctoConverterGUI
        PROPERTIES
        OUTPUT_NAME "OctoConverterGUI"
    )
endif()
