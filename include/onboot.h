#ifndef ON_BOOT_H
#define ON_BOOT_H

class Onboot
{
private:
    static bool diagnosticsMode;
    static bool speackerConnected;

public:
    static void startBoot();
    static bool checkDiagnosticsOn();
    static bool checkSpeakerConnected();
    static void addRulesOnBootOnCondition();
};

#endif