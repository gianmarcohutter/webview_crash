/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Webview_crashAudioProcessorEditor  : public juce::AudioProcessorEditor, juce::Timer
{
public:
    Webview_crashAudioProcessorEditor (Webview_crashAudioProcessor&);
    ~Webview_crashAudioProcessorEditor() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Webview_crashAudioProcessor& audioProcessor;

    std::unique_ptr<juce::WindowsWebView2WebBrowserComponent> webComponent;

    void timerCallback() override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Webview_crashAudioProcessorEditor)
};
