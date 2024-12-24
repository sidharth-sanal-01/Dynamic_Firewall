#include "onboot.h"
#include <filesystem>
#include <iostream>
#include <fstream>

namespace fs = std::filesystem;

void Onboot::startBoot()
{
    Onboot::addRulesOnBootOnCondition();
};

void Onboot::addRulesOnBootOnCondition()
{

    std::string ruleFilepath = "../rules.nft";

    if (!fs::exists(ruleFilepath))
    {
        std::cout << "Rule file not present in the system..So cannot add rule.." << std::endl;
    }
    else
    {
        std::ofstream file(ruleFilepath, std::ios::app);

        if (Onboot::checkDiagnosticsOn())
        {
            std::cout << "Diagnostics present, Adding Rules for Diagnostics ,Turning Diangnostics on in the system" << std::endl;
            // adding the rule to the system
            file << "tcp in port=any dip=180.120.1.10 sip=any keepstate comment=Diagnostics" << std::endl;
            file << "tcp out port=any sip=180.120.1.10 dip=any keepstate comment=Diagnostics" << std::endl;
        }
        else
        {
            std::cout << "Files do not exist in the system" << std::endl;
        }

        if (Onboot::checkSpeakerConnected())
        {
            std::cout << "Speakers present, Adding Rules for speakers ,Turning Speakers on in the system" << std::endl;
            file << "tcp in port=any dip=180.120.1.10 sip=any keepstate comment=speaker" << std::endl;
            file << "tcp out port=any sip=180.120.1.10 dip=any keepstate comment=speaker" << std::endl;
        }
        else
        {
            std::cout << "Speakers not present..Not Adding the rules for speakers.." << std::endl;
        }
    }
};

bool Onboot::checkDiagnosticsOn()
{
    std::string path = "/var";
    std::string required = "DiagnosticsON";
    try
    {
        if (fs::exists(path) && fs::is_directory(path))
        {
            for (const auto &file : fs::directory_iterator(path))
            {
                if (file.is_regular_file())
                {
                    if (file.path().filename() == required)
                    {
                        std::cout << "Diagnostics File present...Adding Diagnostics rule.." << std::endl;

                        return true;
                    }
                }
            }
        }

        std::cout << "Requried file not found not adding Diagnostics Rules" << std::endl;

        return true;
    }
    catch (...)
    {
        std::cerr << "Some error occured..Could not check directory.." << std::endl;
        return false;
    }
}

bool Onboot::checkSpeakerConnected()
{
    std::string path = "/var";
    std::string required = "SpeakersOn";
    try
    {
        if (fs::exists(path) && fs::is_directory(path))
        {
            for (const auto &file : fs::directory_iterator(path))
            {
                if (file.is_regular_file())
                {
                    if (file.path().filename() == required)
                    {
                        std::cout << "SpeakersOn File present...Adding Speakers rule.." << std::endl;

                        return true;
                    }
                }
            }
        }

        std::cout << "Requried file not found not adding Rules" << std::endl;

        return false;
    }
    catch (...)
    {
        std::cerr << "Some error occured..Could not check directory.." << std::endl;
        return false;
    }
}