#include "Resource.hpp"

namespace ariel
{

    std::string resourceToString(Resource resource)
    {
        switch (resource)
        {
        case Resource::Wood:
            return "Wood";
        case Resource::Brick:
            return "Brick";
        case Resource::Wool:
            return "Wool";
        case Resource::Oats:
            return "Oats";
        case Resource::Iron:
            return "Iron";
        case Resource::Desert:
            return "Desert";
        default:
            return "Unknown";
        }
    };

}