#pragma once

#include "rapidjson/document.h"
#include "SFML/Graphics/Transform.hpp"
#include <string>

void FillTransformField(rapidjson::Document& document, const std::string& fieldName, const sf::Transform& transform);

sf::Transform GetTransformFromJson(const rapidjson::Document& document, const std::string& fieldName);