#pragma once

namespace engine::management
{
	class Token
	{
	public:
		static constexpr const char* InlineDelimiterToken = "$";
		static constexpr const char* SectionDelimiterToken = "---";
		static constexpr const char* EntityToken = "Entity";
		static constexpr const char* ShapeListInstanceToken = "ShapeListInstance";
	};
}