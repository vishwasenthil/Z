set(HAL_DIR ${CMAKE_SOURCE_DIR}/lib/stm32g4xxhal)

add_library(STM32G4_BUILD_OPTIONS INTERFACE)

target_compile_definitions(STM32G4_BUILD_OPTIONS INTERFACE
    STM32G474xx
    ARM_MATH_CM4
)

target_compile_options(STM32G4_BUILD_OPTIONS INTERFACE
    -mcpu=cortex-m4
    -mthumb
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
)

target_link_options(STM32G4_BUILD_OPTIONS INTERFACE
    -mcpu=cortex-m4
    -mthumb
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
)

file(GLOB HAL_SOURCES ${HAL_DIR}/Src/*.c)

add_library(HAL_LIB STATIC ${HAL_SOURCES})
target_compile_definitions(HAL_LIB PUBLIC USE_HAL_DRIVER)
target_link_libraries(HAL_LIB PRIVATE STM32G4_BUILD_OPTIONS)

target_include_directories(HAL_LIB PUBLIC
                            ${HAL_DIR}/Inc
                            ${HAL_DIR}/CMSIS/Device/ST/STM32G4xx/Include
                            ${HAL_DIR}/CMSIS/include
                            ${CMAKE_SOURCE_DIR}/zactuator_node/config
)

add_library(STM32G4_PLATFORM OBJECT
    startup_stm32g474retx.s
    ${HAL_DIR}/Src/system_stm32g4xx.c
    stm32g4xx_hal_msp.c
)

target_link_libraries(STM32G4_PLATFORM PRIVATE
    STM32G4_BUILD_OPTIONS
)

target_include_directories(STM32G4_PLATFORM
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE
        ${HAL_DIR}/Inc
        ${HAL_DIR}/CMSIS/Device/ST/STM32G4xx/Include
        ${HAL_DIR}/CMSIS/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/config
)
