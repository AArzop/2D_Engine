#pragma once

#include "../IVisitable.h"

namespace engine
{
	namespace management
	{
		namespace save
		{
			class ISaveVisitor;

			class ISaveVisitable : public IVisitable
			{
			public:

				void Accept(IVisitor* const) override {};
				virtual void Accept(ISaveVisitor* const visitor) = 0;
			};
		}
	}
}