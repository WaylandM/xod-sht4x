// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/adafruit/Adafruit_SHT4X"

//Include C++ libraries
#include <Adafruit_SHT4x.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_SHT4x*;
    }
    // Keep Adafruit_SHT4x object in state
    Adafruit_SHT4x sensor = Adafruit_SHT4x();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;
        emitValue<output_DEV>(ctx, &sensor);
    }
}
