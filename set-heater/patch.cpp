#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);
        auto heater = getValue<input_Heat>(ctx);

        if (heater < 7) {
            sensor->setHeater(heater);
            emitValue<output_Done>(ctx, 1);
        }
        
        emitValue<output_Done>(ctx, 1);
    }
}
