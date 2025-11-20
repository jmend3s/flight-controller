
add_library(CoreKit STATIC)

target_link_libraries(CoreKit PUBLIC zephyr_interface)

target_include_directories(CoreKit PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/application
    ${CMAKE_CURRENT_SOURCE_DIR}/components
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/drivers
    ${CMAKE_CURRENT_SOURCE_DIR}/services
)

add_subdirectory(application)
add_subdirectory(components)
add_subdirectory(core)
add_subdirectory(drivers)
add_subdirectory(services)
