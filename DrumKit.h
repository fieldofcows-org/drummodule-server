/*
 * File: DrumKit.h
 * Project: drum-rest
 * File Created: Thursday, 20th September 2018 8:04:28 am
 * Author: rhopkins (roy.hopkins@fieldofcows.com)
 * -----
 * Last Modified: Thursday, 20th September 2018 8:04:31 am
 * Modified By: rhopkins (roy.hopkins@fieldofcows.com>)
 * -----
 * Copyright 2018 Roy Hopkins
 */
#pragma once

#include <string>

class DrumKit {
    /**
     * Get the name of the drum kit
     * @return Name
     */
    virtual std::string name() = 0;
};
