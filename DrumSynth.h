/*
 * File: DrumSynth.h
 * Project: drum-rest
 * File Created: Thursday, 20th September 2018 8:03:05 am
 * Author: rhopkins (roy.hopkins@fieldofcows.com)
 * -----
 * Last Modified: Thursday, 20th September 2018 8:03:26 am
 * Modified By: rhopkins (roy.hopkins@fieldofcows.com>)
 * -----
 * Copyright 2018 Roy Hopkins
 */
#pragma once

#include "DrumKit.h"

class DrumSynth {

    /**
     * Get a count of the number of installed drum kits
     * @return  Number of kits
     */
    virtual int getDrumKitCount() = 0;

    /**
     * Get the drum kit with the given index.
     * This does not actually load the kit, only retrieves metadata about
     * the kit
     * @param[in] index     Index of kit to get
     * @return Kit or NULL if index is out of range
     */
    virtual DrumKit* getDrumKit(int index) = 0;
    
    /**
     * Load the given drum kit, unloading any previously loaded kit
     * @param[in] kit   Kit to load
     */
    virtual void loadDrumKit(DrumKit* kit) = 0;
};
