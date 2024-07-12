/**ID:206751976
Email:"aharonba123@gmail.com"
*/

#ifndef RESOURCE_HPP
#define RESOURCE_HPP
#include <string>
namespace ariel
{
    enum class Resource
    {
        Wood,
        Brick,
        Wool,
        Oats,
        Iron,
        Desert
    };

    std::string resourceToString(Resource resource);
}
#endif // RESOURCE_HPP
