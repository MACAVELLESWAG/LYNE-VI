cmake_minimum_required(VERSION 3.22)
project(LYNE_VI VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(JUCE)

juce_add_plugin(LYNE_VI
    PRODUCT_NAME "LYNE VI"
    COMPANY_NAME "NeuralBeanBod"
    PLUGIN_MANUFACTURER_CODE "NBBE"
    PLUGIN_CODE "LYVI"
    FORMATS VST3 AU Standalone
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
)

target_sources(LYNE_VI PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

target_compile_definitions(LYNE_VI PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(LYNE_VI PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
)
