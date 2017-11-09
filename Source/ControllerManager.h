/*
  ==============================================================================

    ControllerManager.h
    Created: 19 Oct 2017 7:35:51pm
    Author:  Ben

  ==============================================================================
*/

#pragma once

#include "Controller.h"

class ControllerManager :
	public BaseManager<Controller>
{
public:
	juce_DeclareSingleton(ControllerManager, true)

	ControllerManager();
	~ControllerManager();

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControllerManager)
};

class ControllerFactory :
	public Factory<Controller>
{
public:
	juce_DeclareSingleton(ControllerFactory,true)
	ControllerFactory();
};