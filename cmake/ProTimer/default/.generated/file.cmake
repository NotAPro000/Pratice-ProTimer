# The following variables contains the files used by the different stages of the build process.
set(ProTimer_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${ProTimer_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(ProTimer_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${ProTimer_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)
set(ProTimer_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ProTimer.X/mcc_generated_files/system/src/clock.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ProTimer.X/mcc_generated_files/system/src/config_bits.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ProTimer.X/mcc_generated_files/system/src/interrupt.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ProTimer.X/mcc_generated_files/system/src/pins.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ProTimer.X/mcc_generated_files/system/src/system.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ProTimer.X/mcc_generated_files/timer/src/tmr0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ProTimer.X/src/lcd/lcd.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ProTimer.X/src/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../ProTimer.X/src/protimer/protimer.c")
set_source_files_properties(${ProTimer_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(ProTimer_default_default_XC8_FILE_TYPE_link)

# The (internal) path to the resulting build image.
set(ProTimer_default_internal_image_name "${CMAKE_CURRENT_SOURCE_DIR}/../../../_build/ProTimer/default/default.elf")

# The name of the resulting image, including namespace for configuration.
set(ProTimer_default_image_name "ProTimer_default_default.elf")

# The name of the image, excluding the namespace for configuration.
set(ProTimer_default_original_image_name "default.elf")

# The output directory of the final image.
set(ProTimer_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/ProTimer")
