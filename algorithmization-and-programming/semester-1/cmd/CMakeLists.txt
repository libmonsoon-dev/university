set(PLAYGROUND_EXE playground)
set(LAB1_EXE lab1)
set(LAB2_1_EXE lab2.1)
set(LAB2_2_EXE lab2.2)

add_executable(${LAB1_EXE} lab1.cpp)
add_executable(${LAB2_1_EXE} lab2_1.cpp)
add_executable(${LAB2_2_EXE} lab2_2.cpp)
add_executable(${PLAYGROUND_EXE} playground.cpp)

set(PROJECT_LIBS math utils lab)

target_link_libraries(${LAB1_EXE} ${PROJECT_LIBS})
target_link_libraries(${LAB2_1_EXE} ${PROJECT_LIBS})
target_link_libraries(${LAB2_2_EXE} ${PROJECT_LIBS})
target_link_libraries(${PLAYGROUND_EXE} ${PROJECT_LIBS})
