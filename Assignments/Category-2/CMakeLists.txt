# "ON" = build Option 1, "OFF" = build Option 2.
option(BUILD_CATEGORY_2_OPTION_1 "Build Assignment-Category 2 Option 1 (Standard)" ON)

add_executable(Category-2
    
    
    main.cpp
        Option-1/models/TPerson.h
        Option-1/Utils/TDataLoader.cpp
        Option-1/Utils/TDataLoader.h
        Option-1/Algorithms/TSortPersons.cpp
        Option-1/Algorithms/TSortPersons.h
        Option-1/Utils/TDataStructureConverter.h
        Option-1/Algorithms/TSearchPersons.cpp
        Option-1/Algorithms/TSearchPersons.h
        Option-1/Utils/TPersonComparators.h
)

# Conditionally add the correct source file
if(BUILD_CATEGORY_2_OPTION_1)
    # If ON, add option1.cpp and define 'ASSIGNMENT_OPTION=1' for C++
    target_sources(Category-2
      PRIVATE
        "Option-1/app.cpp"
        "Option-1/app.h"
    )
    target_compile_definitions(Category-2 PRIVATE "CATEGORY_2_OPTION=1")
else()
    # If OFF, add option2.cpp and define 'ASSIGNMENT_OPTION=2' for C++
    target_sources(Category-2
      PRIVATE
        "Option-2/app.cpp" 
        "Option-2/app.h"
    )
    target_compile_definitions(Category-2 PRIVATE "CATEGORY_2_OPTION=2")
endif()

target_link_libraries(Category-2 PRIVATE StructureReader)
target_link_libraries(Category-2 PUBLIC DebugUtils)


add_custom_command(TARGET Category-2 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E echo "Category-2 post-build step, add any additional commands here if needed..."
)
