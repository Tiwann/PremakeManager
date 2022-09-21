#pragma once
#include <filesystem>

class Assets
{
public:
    static std::filesystem::path GetAssetsFolder() { return std::filesystem::current_path().append("Assets"); }
    static std::filesystem::path GetAssetAt(const std::string& file)
    {
        return GetAssetsFolder().append(file).make_preferred();
    }
};
