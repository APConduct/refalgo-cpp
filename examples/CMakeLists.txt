add_executable(list_examples list_examples.cpp)
target_link_libraries(list_examples PRIVATE refalgo)
target_include_directories(list_examples PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/modules
)

add_executable(stack_examples stack_examples.cpp)
target_link_libraries(stack_examples PRIVATE refalgo)
target_include_directories(stack_examples PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/modules
)
