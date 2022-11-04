set(OOP_LAB1_EXE oop_lab1)
set(OOP_LAB2_EXE oop_lab2)
set(OOP_LAB3_EXE oop_lab3)


add_executable(${OOP_LAB1_EXE} lab1.cpp)
add_executable(${OOP_LAB2_EXE} lab2.cpp)
add_executable(${OOP_LAB3_EXE} lab3.cpp)

set(OOP_LIBS oop_lab)

target_link_libraries(${OOP_LAB1_EXE} ${OOP_LIBS})
target_link_libraries(${OOP_LAB2_EXE} ${OOP_LIBS})
target_link_libraries(${OOP_LAB3_EXE} ${OOP_LIBS})

