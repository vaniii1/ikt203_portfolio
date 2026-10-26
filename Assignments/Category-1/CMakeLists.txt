# "ON" = build Option 1, "OFF" = build Option 2.
option(BUILD_CATEGORY_1_OPTION_1 "Build Assignment-Category 1 Option 1 (Standard)" ON)

add_executable(Category-1
    
    
    main.cpp
        Option-1/data_structures/linkedl_ist/TLinkedList.cpp
        Option-1/data_structures/linkedl_ist/TLinkedList.h
        Option-1/data_structures/linkedl_ist/TNode.cpp
        Option-1/data_structures/linkedl_ist/TNode.h
        Option-1/data_structures/stack/TActionStack.cpp
        Option-1/data_structures/stack/TActionStack.h
        Option-1/controlller/TextController.cpp
        Option-1/controlller/TextController.h
        Option-1/data_structures/queue/TQueue.cpp
        Option-1/data_structures/queue/TQueue.h
        Option-1/view/TextView.cpp
        Option-1/view/TextView.h
)

# Conditionally add the correct source file
if(BUILD_CATEGORY_1_OPTION_1)
    # If ON, add option1.cpp and define 'ASSIGNMENT_OPTION=1' for C++
    target_sources(Category-1
      PRIVATE
        "Option-1/app.cpp"
        "Option-1/app.h"
    )
    target_compile_definitions(Category-1 PRIVATE "CATEGORY_1_OPTION=1")
else()
    # If OFF, add option2.cpp and define 'ASSIGNMENT_OPTION=2' for C++
    target_sources(Category-1
      PRIVATE
        "Option-2/app.cpp" 
        "Option-2/app.h"
    )
    target_compile_definitions(Category-1 PRIVATE "CATEGORY_1_OPTION=2")
endif()

target_link_libraries(Category-1 PRIVATE StructureReader)
target_link_libraries(Category-1 PUBLIC DebugUtils)


add_custom_command(TARGET Category-1 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E echo "Category-1 post-build step, add any additional commands here if needed..."
)
