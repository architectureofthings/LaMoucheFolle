
/*
==============================================================================

This file was auto-generated!

It contains the basic startup code for a Juce application.

==============================================================================
*/

#pragma once

#include "JuceHeader.h"

#pragma warning(disable:4244 4100 4305)

#include "MainComponent.h"
#include "CFEngine.h"

//==============================================================================
class CFApplication : public JUCEApplication
{
public:
	//==============================================================================
	CFApplication() {}

	ApplicationCommandManager commandManager;
	ScopedPointer<ApplicationProperties> appProperties;
	ScopedPointer<CFEngine> engine;


	const String getApplicationName() override { return ProjectInfo::projectName; }
	const String getApplicationVersion() override { return ProjectInfo::versionString; }
	bool moreThanOneInstanceAllowed() override { return true; }


	//==============================================================================
	void initialise(const String& /*commandLine*/) override;

	void shutdown() override;

	//==============================================================================
	void systemRequestedQuit() override;

	void anotherInstanceStarted(const String& commandLine) override;

	//==============================================================================
	/*
	This class implements the desktop window that contains an instance of
	our MainContentComponent class.
	*/



	class MainWindow : public DocumentWindow
	{
	public:
		MainWindow(String name);

		void closeButtonPressed() override;


		MainContentComponent * mainComponent;


		/* Note: Be careful if you override any DocumentWindow methods - the base
		class uses a lot of them, so by overriding you might break its functionality.
		It's best to do all your work in your content component instead, but if
		you really have to override any DocumentWindow methods, make sure your
		subclass also calls the superclass's method.
		*/

#if JUCE_OPENGL
		OpenGLContext openGLContext;
#endif


	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)


	};

	ScopedPointer<MainWindow> mainWindow;
};



static CFApplication& getApp() { return *dynamic_cast<CFApplication*>(JUCEApplication::getInstance()); }
String getAppVersion() { return getApp().getApplicationVersion(); }
ApplicationProperties& getAppProperties() { return *getApp().appProperties; }

OpenGLContext * getOpenGLContext() { return &getApp().mainWindow->openGLContext; }

ApplicationCommandManager& getCommandManager() { return getApp().commandManager; }
CFApplication::MainWindow * getMainWindow() { return getApp().mainWindow; }
//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION(CFApplication)
