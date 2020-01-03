#pragma once

#include "pimpl.h"

class widget {

private:
    class impl;
    pimpl<impl> m;
};