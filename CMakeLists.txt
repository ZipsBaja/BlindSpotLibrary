set(LIBRARY_NAME pico-BlindSpot-lib)

if (NOT TARGET ${LIBRARY_NAME})

    add_library(${LIBRARY_NAME} STATIC
        # Add your source files here
        src/devices/BlindSpot.cpp
    )

    add_subdirectory(lib/ZipsPicoLib)
    add_subdirectory(lib/SegmentDisplayLibrary)

    target_include_directories(${LIBRARY_NAME} PUBLIC
        include
    )

    target_link_libraries(${LIBRARY_NAME}
        ZipsPicoLib
        pico-segmentdisplay-lib
    )

endif()