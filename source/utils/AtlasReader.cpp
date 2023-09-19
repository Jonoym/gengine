#include <core/Logger.h>
#include <utils/AtlasReader.h>

namespace Gengine
{
    std::vector<AtlasRegion> AtlasReader::ParseAtlasFile(const std::string &atlasFilename) 
    {
        std::ifstream atlasFile(atlasFilename);

        if (!atlasFile.is_open())
        {
            L_WARN("[ATLAS READER]", "Could not open the Atlas file with Name: %s", atlasFilename.c_str());
            return {};
        }

        std::vector<AtlasRegion> atlasRegions = {};

        std::string currentLine;
        for (int i = 0; i < 5; i++)
        {
            // Skipping through file header content
            std::getline(atlasFile, currentLine);
        }

        while (std::getline(atlasFile, currentLine))
        {
            AtlasRegion currentRegion = {};

            currentRegion.mAnimationName = std::string(currentLine);

            std::getline(atlasFile, currentLine);
            currentRegion.mRotate = ParseLineBool(currentLine);

            std::getline(atlasFile, currentLine);
            currentRegion.mLocation = ParseLineCoord(currentLine);

            std::getline(atlasFile, currentLine);
            currentRegion.mSize = ParseLineCoord(currentLine);

            std::getline(atlasFile, currentLine);
            currentRegion.mOriginal = ParseLineCoord(currentLine);

            std::getline(atlasFile, currentLine);
            currentRegion.mOffset = ParseLineCoord(currentLine);

            std::getline(atlasFile, currentLine);
            currentRegion.mIndex = ParseLineInt(currentLine);

            atlasRegions.push_back(currentRegion);
        };

        return atlasRegions;
    }

    Coord AtlasReader::ParseLineCoord(const std::string &line)
    {
        size_t colonPosition = line.find(':');
        if (colonPosition != std::string::npos)
        {
            std::string value = line.substr(colonPosition + 1);
            // Trimming the whitespace
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);

            size_t delimiterPosition = value.find(", ");

            if (delimiterPosition == std::string::npos)
            {
                L_WARN("[ATLAS READER]", "Error Parsing the Line: '%s' for an Integer", line.c_str());
                return {0, 0};
            }
            L_INFO("[ATLAS READER]", "Parsing Line as a Coord: { %s, %s }", value.substr(0, delimiterPosition).c_str(), value.substr(delimiterPosition + 1).c_str());

            int32 xCoord = std::stoi(value.substr(0, delimiterPosition));
            int32 yCoord = std::stoi(value.substr(delimiterPosition + 1));

            return { xCoord, yCoord };
        }
        else
        {
            L_WARN("[ATLAS READER]", "Error Parsing the Line: '%s' for an Integer", line.c_str());
            return {0, 0};
        }
    }

    uint8 AtlasReader::ParseLineInt(const std::string &line)
    {
        size_t colonPosition = line.find(':');
        if (colonPosition != std::string::npos)
        {
            std::string value = line.substr(colonPosition + 1);
            // Trimming the whitespace
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);
            L_INFO("[ATLAS READER]", "Parsing Line as an Integer: %s", value.c_str());

            return std::stoi(value);
        }
        else
        {
            L_WARN("[ATLAS READER]", "Error Parsing the Line: '%s' for an Integer", line.c_str());
            return 0;
        }
    }

    bool AtlasReader::ParseLineBool(const std::string &line)
    {
        size_t colonPosition = line.find(':');
        if (colonPosition != std::string::npos)
        {
            std::string value = line.substr(colonPosition + 1);
            // Trimming the whitespace
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);
            L_INFO("[ATLAS READER]", "Parsing Line as a Bool: %s", value.c_str());

            return value == "true";
        }
        else
        {
            L_WARN("[ATLAS READER]", "Error Parsing the Line: '%s' for an Integer", line.c_str());
            return false;
        }
    }

}