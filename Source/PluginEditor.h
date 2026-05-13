#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "LcdDisplay.h"

class LYNEVIPluginEditor : public juce::AudioProcessorEditor
{
public:
    LYNEVIPluginEditor(LYNEVIPluginProcessor&);
    ~LYNEVIPluginEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    LYNEVIPluginProcessor& audioProcessor;
    juce::Image backgroundImage;

    // Knobs
    juce::Slider driveKnob, bassKnob, middleKnob, trebleKnob, presenceKnob;
    juce::Slider chanVolKnob, reverbKnob, outputKnob;
    juce::Slider ampModelsKnob, effectsKnob;

    std::unique_ptr<LcdDisplay> lcdDisplay;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LYNEVIPluginEditor)
};
