find_package(Doxygen REQUIRED)

configure_file(Doxyfile.in Doxyfile @ONLY)

add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} Doxyfile
    COMMENT "Generating documentation" VERBATIM
)
