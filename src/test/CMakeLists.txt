set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

aux_source_directory(. SRC_FILES)
aux_source_directory(. DEPEND_FILES)

add_executable(test ${SRC_FILES} ${DEPEND_FILES})

