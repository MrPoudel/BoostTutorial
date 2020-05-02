
cmake_minimum_required (VERSION 3.7)
project (pattern_example)

#main project set up
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Boost related setup

#set(Boost_INCLUDE_DIR /usr/include/)
#set(Boost_LIBRARY_DIR /usr/lib/)

find_package(Boost 1.65.1 REQUIRED COMPONENTS program_options)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

option(ENABLE_EXAMPLES "Building the examples" ON)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    #ADD_DEFINITIONS("-DHAS_BOOST")

    #Just for debugging purpose
    message(${Boost_INCLUDE_DIR})

    if(ENABLE_EXAMPLES)        

        add_executable(boost_program_option examples/boost_program_option.cpp)
        target_link_libraries(boost_program_option ${Boost_LIBRARIES})

        add_executable(multiprecision examples/multiprecision.cpp)
        #target_link_libraries(multiprecision ${Boost_LIBRARIES})

        add_executable(program_option_fruit examples/program_option_fruit.cpp)
        target_link_libraries(program_option_fruit ${Boost_LIBRARIES})

        add_executable(program_option_advance examples/program_option_advance.cpp)
        target_link_libraries(program_option_advance ${Boost_LIBRARIES})
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/examples/apples_oranges.cfg
            DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)

    endif()
endif()
