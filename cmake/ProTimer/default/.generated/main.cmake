include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(ProTimer_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(ProTimer_default_default_XC8_FILE_TYPE_assemble)
add_library(ProTimer_default_default_XC8_assemble OBJECT ${ProTimer_default_default_XC8_FILE_TYPE_assemble})
    ProTimer_default_default_XC8_assemble_rule(ProTimer_default_default_XC8_assemble)
    list(APPEND ProTimer_default_library_list "$<TARGET_OBJECTS:ProTimer_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(ProTimer_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(ProTimer_default_default_XC8_assemblePreprocess OBJECT ${ProTimer_default_default_XC8_FILE_TYPE_assemblePreprocess})
    ProTimer_default_default_XC8_assemblePreprocess_rule(ProTimer_default_default_XC8_assemblePreprocess)
    list(APPEND ProTimer_default_library_list "$<TARGET_OBJECTS:ProTimer_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(ProTimer_default_default_XC8_FILE_TYPE_compile)
add_library(ProTimer_default_default_XC8_compile OBJECT ${ProTimer_default_default_XC8_FILE_TYPE_compile})
    ProTimer_default_default_XC8_compile_rule(ProTimer_default_default_XC8_compile)
    list(APPEND ProTimer_default_library_list "$<TARGET_OBJECTS:ProTimer_default_default_XC8_compile>")
endif()

add_executable(${ProTimer_default_image_name} ${ProTimer_default_library_list})

target_link_libraries(${ProTimer_default_image_name} PRIVATE ${ProTimer_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
ProTimer_default_link_rule(${ProTimer_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${ProTimer_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${ProTimer_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${ProTimer_default_image_name} ${ProTimer_default_output_dir}/${ProTimer_default_original_image_name}
                    BYPRODUCTS ${ProTimer_default_output_dir}/${ProTimer_default_original_image_name})
