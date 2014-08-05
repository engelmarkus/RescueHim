add_custom_target(
    data ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/data ${PROJECT_BINARY_DIR}/data
    COMMENT "Copying data directory"
)
