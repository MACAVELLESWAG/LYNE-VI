#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class LYNEVIPluginEditor : public juce::AudioProcessorEditor {
public:
    LYNEVIPluginEditor(LYNEVIPluginProcessor&);
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    LYNEVIPluginProcessor& audioProcessor;
    juce::Image backgroundImage;

    // All knobs from the red bean reference
    juce::Slider driveKnob, bassKnob, middleKnob, trebleKnob, presenceKnob;
    juce::Slider chanVolKnob, reverbKnob, outputKnob;
    juce::Slider ampModelsKnob, effectsKnob;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LYNEVIPluginEditor)
};