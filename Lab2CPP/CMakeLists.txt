add_executable(Lab2CPP lab2.cpp)
target_include_directories(Lab2CPP PUBLIC ../LibraryCPP)
target_link_libraries(Lab2CPP LibraryCPP)

add_test(TestLab2CPP Lab2CPP ${CMAKE_CURRENT_SOURCE_DIR}/input.txt)