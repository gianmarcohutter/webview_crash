/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Webview_crashAudioProcessorEditor::Webview_crashAudioProcessorEditor (Webview_crashAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (500, 500);

    // the dll needs to be accessible in order to get the webview2 (chromium, instead of internet explorer)
    // this should be in the git repository as well but the path might be wrong
    juce::File dllFileLocation  = juce::File::getCurrentWorkingDirectory().getChildFile("../../WebView2Loader.dll");
    jassert(dllFileLocation.existsAsFile());

    auto preferences = juce::WebView2Preferences().withDLLLocation(dllFileLocation);

    webComponent.reset(new juce::WindowsWebView2WebBrowserComponent(false, preferences));
    startTimer(5000); //wait before calling goToURL
   
    webComponent->setSize(getWidth(), getHeight());
    addAndMakeVisible(webComponent.get());
}

Webview_crashAudioProcessorEditor::~Webview_crashAudioProcessorEditor()
{
}

void Webview_crashAudioProcessorEditor::timerCallback()
{
    webComponent->goToURL("https://google.com");
    stopTimer();
}

