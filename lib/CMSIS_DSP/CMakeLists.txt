set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

file(GLOB_RECURSE DSP_SOURCES ${LIB_DIR}/CMSIS_DSP/Source/*.c)
list(REMOVE_ITEM DSP_SOURCES
    ${LIB_DIR}/CMSIS_DSP/Source/CommonTables/arm_common_tables.c
)

add_library(DSP_LIB STATIC ${DSP_SOURCES})
target_link_libraries(DSP_LIB PRIVATE STM32G4_BUILD_OPTIONS)
target_include_directories(DSP_LIB PUBLIC ${LIB_DIR}/CMSIS_DSP/Include ${LIB_DIR}/CMSIS_DSP/PrivateInclude)
target_include_directories(DSP_LIB PRIVATE ${LIB_DIR}/stm32g4xxhal/CMSIS/include)