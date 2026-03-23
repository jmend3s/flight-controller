
target_include_directories(app PRIVATE
     ${CMAKE_CURRENT_SOURCE_DIR}/src/modules
     ${CMAKE_CURRENT_SOURCE_DIR}/src/services
)

add_subdirectory(src)
