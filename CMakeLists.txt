cmake_minimum_required(VERSION 3.10)

# Project name and version
project(sys-gc VERSION 0.0.1 LANGUAGES C CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(APP_AUTHOR_NAME "Nontre")
set(APP_NAME "sys-gc")
set(APP_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

# Define the target and its sources
set(SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/source/gui.cpp
    ${CMAKE_SOURCE_DIR}/source/main.cpp
    ${CMAKE_SOURCE_DIR}/source/overlay.cpp
)

add_executable(${APP_NAME}.elf ${SOURCE_FILES})

# Include directories
target_include_directories(${APP_NAME}.elf PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/libs/libtesla/include
    /opt/devkitpro/portlibs/switch/include
    /opt/devkitpro/libnx/include
    ${CMAKE_BINARY_DIR}
)

# Compilation flags
target_compile_options(${APP_NAME}.elf PRIVATE
    -g
    -Wall
    -O2
    -ffunction-sections
    -march=armv8-a+crc+crypto
    -mtune=cortex-a57
    -mtp=soft
    -fPIE
    -D__SWITCH__
    -fno-exceptions
)

# Linker flags
target_link_options(${APP_NAME}.elf PRIVATE
    -specs=/opt/devkitpro/libnx/switch.specs
    -g
    -march=armv8-a+crc+crypto
    -mtune=cortex-a57
    -mtp=soft
    -fPIE
    -Wl,-Map,${APP_NAME}.map
)

# Libraries to link against
target_link_libraries(${APP_NAME}.elf
    nx
    -L/opt/devkitpro/portlibs/switch/lib
    -L/opt/devkitpro/libnx/lib
)

# Post-build steps
add_custom_command(TARGET ${APP_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_NM} -CSn ${CMAKE_SOURCE_DIR}/${APP_NAME}.elf > ${APP_NAME}.lst
    COMMENT "Creating LST symbols file from ELF (debug purposes)"
)

# Create NACP file
add_custom_command(TARGET ${APP_NAME}.elf POST_BUILD
    COMMAND nacptool --create ${APP_NAME} ${APP_AUTHOR_NAME} ${APP_VERSION} ${CMAKE_SOURCE_DIR}/${APP_NAME}.nacp
    COMMENT "Creating NACP file"
)

# Convert ELF to NRO
add_custom_command(TARGET ${APP_NAME}.elf POST_BUILD
    COMMAND elf2nro ${CMAKE_SOURCE_DIR}/${APP_NAME}.elf ${CMAKE_SOURCE_DIR}/${APP_NAME}.ovl --nacp=${CMAKE_SOURCE_DIR}/${APP_NAME}.nacp
    COMMENT "Converting ELF to OVL(NRO) (ovl-loader specific)"
)

# Set output directory for executables and other files
set_target_properties(${APP_NAME}.elf PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
